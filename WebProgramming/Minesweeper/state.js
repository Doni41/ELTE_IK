import { Field, FieldState } from "./field.js";

export const Stage = {
    NOT_STARTED: 1,
    PLAYING: 2,
    GAME_OVER: 4,
    VICTORY: 8
}

export class AppState {
    width = 0;
    height = 0;
    board = [];
    stage = Stage.NOT_STARTED

    /**
     * init() function:
     *      - instead of AppState constructor
     *      - and making new object continously
     *      - beolvasas NEM itt, hogy ne keveredjenek
     *  parameters:
     *      - width -> hanyszor
     *      - height -> hanyas
     *      - mineCount -> hany darab
     */
    init (width, height, mineCount) {
        if (mineCount >= width * height) {
            return;
        }

        this.width = width;
        this.height = height;

        // init the board
        this.board = [];
        // we build from rows to rows the HTML -> (y, x) coordinates
        for (let y = 0; y < height; y++) {
            this.board[y] = [];

            for (let x = 0; x < width; x++) {
                this.board[y][x] = new Field();
            }
        }

        // creating mines randomly, if we know that the field isn't a mine 
        for (let i = 0; i < mineCount; i++) {
            // generating mines with the function
            const {x, y} = this.getEmptyCoord();

            this.board[y][x].isMine = true;

            // increase the neighbours mine counter
            for (let dx = -1; dx <= 1; dx++) {
                //console.log('elso ciklus');
                for (let dy = -1; dy <= 1; dy++) {

                     // kihasznaljuk, hogy vagy egy tomb van ott, vagy undefined
                    if (this.board[y + dy] && this.board[y + dy][x + dx]) {
                        //  increase the mine neighbour counter
                        this.board[y + dy][x + dx].neighborCount += 1;
                    }
                }
            }
        }
        console.log(mineCount);
        this.stage = Stage.PLAYING;
    }


    getEmptyCoord() {
        let x, y;
        // generate random numbers, while the field isMine
        do {
            x = Math.floor(Math.random() * this.width);
            y = Math.floor(Math.random() * this.height);
        } while (this.board[y][x].isMine);
        // return with an object -> creating (x, y) from the object 
        return {x, y};  
    }

    // reveal field after the left click
    reveal(x, y) {
        const field = this.board[y][x];

        if (field.state !== FieldState.UNREVEALED) {
            return;
        }

        field.state = FieldState.REVEALED;

        if (field.isMine) {
            this.gameOver();
            field.isBlownUp = true;
            return;
        }

        if (field.neighborCount === 0) {
            for (let dx = -1; dx <= 1; dx++) {
                for (let dy = -1; dy <= 1; dy++) {
                    if (this.board[y + dy] && this.board[y + dy][x + dx]) {
                        this.reveal(x + dx, y + dy);
                    }
                }
            }
        }
    }

    // Check for Victory
    checkForVictory() {
        if(this.stage !== Stage.PLAYING) {
            return;
        }

        const isGameWon = 
        this.board.every(row => 
            row.every(field => 
                field.isMine || field.state === FieldState.REVEALED))
        
        if(isGameWon) {
            this.stage = Stage.VICTORY;
            this.revealAll();
        }
    }

    // Reveale all fields
    gameOver() {
        this.stage = Stage.GAME_OVER;
        this.revealAll();
    }

    // Toggle the unrevield field with right click 
    toggleFlag (x, y) {
        const field = this.board[y][x];

        if (field.state === FieldState.FLAGGED) {
            field.state = FieldState.UNREVEALED;
        } else {
            field.state = FieldState.FLAGGED;
        }
    }
    
    countFlagsNearby (x, y) {
        let flagCount = 0;
        for (let dx = -1; dx <= 1; dx++) {
            for (let dy = -1; dy <= 1; dy++) {
                if (this.board[y + dy] && this.board[y + dy][x + dx]) {
                    if(this.board[y + dy][x + dx].state === FieldState.FLAGGED) {
                        flagCount += 1;
                    }
                }
            }
        }
    }

    // Reveal all fields
    revealAll() {
        for (const row of this.board) {
            for (const field of row) {
                field.state = FieldState.REVEALED;
            }
        }
    }
}