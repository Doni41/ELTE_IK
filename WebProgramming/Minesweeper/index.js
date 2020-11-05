import { FieldState } from "./field.js";
import { render } from "./render.js";
import { AppState, Stage } from "./state.js";

const state = new AppState();

const game = document.querySelector("#game");
const newButton = document.querySelector("button");
const widthInput = document.querySelector("#width");
const heightInput = document.querySelector("#height");
const mineCountInput = document.querySelector("#mineCount");

/* Event Listener functions */

//  New Button click function -> start the game
newButton.addEventListener("click", handleNewButtonClick);
function handleNewButtonClick () {
    const width = parseInt(widthInput.value);
    const height = parseInt(heightInput.value);
    const mineCount = parseInt(mineCountInput.value);

    // abort the function
    if (mineCount >= width * height) {
        return 
    }

    state.init(width, height, mineCount);
    game.innerHTML = render(state);
}


// Button left click function -> reveal 
game.addEventListener('click', handleFieldLeftClick)
function handleFieldLeftClick(e) {
    if (!e.target.matches('button')) {
        return;
    }

    if(state.stage !== Stage.PLAYING) {
        return;
    }
    // get the x and y coord -> the parent node of the button is a table cell
    const td = e.target.parentNode;
    // the parent node of tf is a table row
    const tr = td.parentNode;
    const x = td.cellIndex; // y
    const y = tr.rowIndex;  // x

    state.reveal(x, y);
    state.checkForVictory();

    game.innerHTML = render(state);
}

game.addEventListener("mousedown", handleFieldDoubleClick)
function handleFieldDoubleClick(e) {
    if (e.button !== 3 || state.stage !== Stage.PLAYING || !e.target.matches('td')) {
        return;
    }

    // e.target -> table cell
    const td = e.target;
    const tr = td.parentNode;
    const x = td.cellIndex; // y
    const y = tr.rowIndex;  // x

    const neighborCount = state.board[y][x].neighborCount
    const flagsNearby = state.countFlagsNearby(x, y);

    if (flagsNearby === state.board[y][x].neighborCount) {
        state.board[y][x] = FieldState.UNREVEALED;
        state.board[y][x].neighborCount = 0;
        state.reveal(x, y);
        state.board[y][x].neighborCount = neighborCount;
    }

    state.checkForVictory();

    game.innerHTML = render(state);
    
    
}

// Button right click function -> flagged
game.addEventListener('contextmenu', handleFieldRightClick);
function handleFieldRightClick(e) {
    e.preventDefault();
    if (!e.target.matches('button')) {
        return;
    }

    const td = e.target.parentNode;
    const tr = td.parentNode;
    const x = td.cellIndex; // y
    const y = tr.rowIndex;  // x

    state.toggleFlag(x, y);
    game.innerHTML = render(state);
}



