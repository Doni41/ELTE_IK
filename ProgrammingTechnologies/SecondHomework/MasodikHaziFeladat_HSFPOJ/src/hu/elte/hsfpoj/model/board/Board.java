package hu.elte.hsfpoj.model.board;

import hu.elte.hsfpoj.model.field.Field;

public class Board {
    private Field[][] board;
    private int boardSize;
    private int firstPlayersShips;
    private int secondPlayersShips;
    private Field selectedField;

    /**
     *
     * @param boardSize
     * creates a new Board object with boardSize param
     * has a board matrix wich contains boardSize * boardSize Field
     * sets first and second player's space ships and the black hole Field
     * inits first player's and second player's space ships (boardSize - 1)
     */
    public Board(int boardSize) {
        this.boardSize = boardSize;
        board = new Field[boardSize][boardSize];
        firstPlayersShips = boardSize - 1;
        secondPlayersShips = boardSize - 1;
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                if ((i == getBoardSize() / 2) && (j == getBoardSize() / 2) && i == j) {
                    board[i][j] = new Field(0, i, j);
                    board[i][j].setBlackHole(true);
                    board[i][j].setHasSpaceShip(true);
                } else {
                    if ((i < boardSize / 2) && (i == j || ((getBoardSize() - 1 - j) == i))) {
                        board[i][j] = new Field(1, i, j);
                        board[i][j].setHasSpaceShip(true);
                    } else if ((i > (boardSize / 2)) && (i == j || ((j - getBoardSize() + 1) * (-1))  == i )) {
                        board[i][j] = new Field(2, i, j);
                        board[i][j].setHasSpaceShip(true);
                    } else {
                        board[i][j] = new Field(0, i, j);
                    }
                }
            }
        }
        this.selectedField = null;
    }

    /**
     *
     * @return boardSize
     */
    public int getBoardSize() {
        return boardSize;
    }

    /**
     *
     * @return the number of first player's spaceships
     */
    public int getFirstPlayersShips() {
        return firstPlayersShips;
    }

    /**
     *
     * @param firstPlayersShips
     */
    public void setFirstPlayersShips(int firstPlayersShips) {
        this.firstPlayersShips = firstPlayersShips;
    }

    /**
     *
     * @return the number of second player's spaceships
     */
    public int getSecondPlayersShips() {
        return secondPlayersShips;
    }

    /**
     *
     * @param secondPlayersShips
     */
    public void setSecondPlayersShips(int secondPlayersShips) {
        this.secondPlayersShips = secondPlayersShips;
    }

    /**
     *
     * @return ture if first player's of second player's spaceships number less than half of init number of spaceships
     */
    public boolean isEndOfTheGame () {
        if ((firstPlayersShips <= (boardSize - 1) / 2 ) || (secondPlayersShips <= (boardSize - 1) / 2 )) {
            return true;
        }
        return false;
    }

    /**
     *
     * @param x
     * @param y
     * @return return a Field of the board
     */
    public Field get(int x, int y) {
        return board[x][y];
    }

    /**
     *
     * @return the selected Field
     */
    public Field getSelectedField() {
        return selectedField;
    }

    /**
     *
     * @param selectedField
     */
    public void setSelectedField(Field selectedField) {
        this.selectedField = selectedField;
    }

    /**
     *
     * @param x
     * @param y
     * remove the owner from a Field
     * Field is selected : false
     * playerID: 0
     * hasSpaceships : false
     */
    public void removeOwner(int x, int y) {
        get(x,y).setSelected(false);
        get(x,y).setPlayerID(0);
        get(x,y).setHasSpaceShip(false);
    }

    /**
     *
     * @param x
     * @param y
     * @param id
     * set an owner for the Field
     * hasSpaceship: true
     * playerID: the id of a player (1 or 2)
     */
    public void setOwner (int x, int y, int id) {
        get(x,y).setHasSpaceShip(true);
        get(x,y).setPlayerID(id);
    }

    /**
     *
     * @param x
     * @param y
     * @return the new y coordinate of the Field, if the Field can move at least one to the left otherwise returns -2
     * if the next Field to the next doesn't have spaceship the Field can move to the left at least one
     * if the next field is a black hole, the number of spaceships of player decreases 1
     */
    public int moveLeft (int x, int y) {
        int i = -2;
        int id = get(x,y).getPlayerID();
        if ((y - 1) >= 0) {
            if (!(get(x, y - 1).isHasSpaceShip()) || get(x, y - 1).isBlackHole()) {
                removeOwner(x, y);
                i = y;
                while(!get(x, i).isHasSpaceShip() && i > 0 && !(get(x, i).isBlackHole())) {
                    i--;
                }
                if(get(x,i).isBlackHole()) {
                    if (id == 1) {
                        setFirstPlayersShips(getFirstPlayersShips() - 1);
                        return -3;
                    } else if (id == 2) {
                        setSecondPlayersShips(getSecondPlayersShips() - 1);
                        return -3;
                    }
                } else {
                    if (!get(x, i).isHasSpaceShip()) {
                        setOwner(x, i, id);
                        return i;
                    } else if(!get(x, i+1).isHasSpaceShip()) {
                        setOwner(x, i+1, id);
                        return i+1;
                    }
                }
            }
        } else {
            setOwner(x, y, id);
            return y;
        }
        return i + 1;
    }

    /**
     *
     * @param x
     * @param y
     * @return the new x coordinate of the Field, if the Field can move at least one to up left otherwise returns -2
     * if the next Field to the next doesn't have spaceship the Field can move up at least one
     * if the next field is a black hole, the number of spaceships of player decreases 1
     */
    public int moveUp(int x, int y) {
        int i = -2;
        int id = get(x,y).getPlayerID();
        if ((x - 1) >= 0) {
            if (!(get(x - 1,y).isHasSpaceShip()) || get(x - 1, y).isBlackHole()) {
                removeOwner(x, y);
                i = x;
                while(!get(i, y).isHasSpaceShip() && i > 0 && !(get(i, y).isBlackHole())) {
                    i--;
                }
                if(get(i, y).isBlackHole()) {
                    if (id == 1) {
                        setFirstPlayersShips(getFirstPlayersShips() - 1);
                        return -3;
                    } else if (id == 2) {
                        setSecondPlayersShips(getSecondPlayersShips() - 1);
                        return -3;
                    }
                } else {
                    if (!get(i, y).isHasSpaceShip()) {
                        setOwner(i, y, id);
                        return i;
                    } else if(!get(i+1, y).isHasSpaceShip()) {
                        setOwner(i+1, y, id);
                        return i+1;
                    }
                }
            }
        } else {
            setOwner(x, y, id);
            return x;
        }
        return i + 1;
    }

    /**
     *
     * @param x
     * @param y
     * @return the new y coordinate of the Field, if the Field can move at least one to the right otherwise returns -2
     * if the next Field to the next doesn't have spaceship the Field can move to the right at least one
     * if the next field is a black hole, the number of spaceships of player decreases 1
     */
    public int moveRight (int x, int y) {
        int i = -2;
        int id = get(x,y).getPlayerID();
        if ((y + 1) <= boardSize - 1) {
            if (!(get(x, y + 1).isHasSpaceShip()) || get(x, y + 1).isBlackHole()) {
                removeOwner(x, y);
                i = y;
                while(!get(x, i).isHasSpaceShip() && i < boardSize - 1 && !(get(x, i).isBlackHole())) {
                    i++;
                }
                if(get(x,i).isBlackHole()) {
                    if (id == 1) {
                        setFirstPlayersShips(getFirstPlayersShips() - 1);
                        return -3;
                    } else if (id == 2) {
                        setSecondPlayersShips(getSecondPlayersShips() - 1);
                        return -3;
                    }
                } else {
                    if (!get(x, i).isHasSpaceShip()) {
                        setOwner(x, i, id);
                        return i;
                    } else if(!get(x, i - 1).isHasSpaceShip()) {
                        setOwner(x, i - 1, id);
                        return i - 1;
                    }
                }
            }
        } else {
            setOwner(x, y, id);
            return y;
        }
        return i + 1;
    }

    /**
     *
     * @param x
     * @param y
     * @return the new x coordinate of the Field, if the Field can move at least one to down otherwise returns -2
     * if the next Field to the next doesn't have spaceship the Field can move to down at least one
     * if the next field is a black hole, the number of spaceships of player decreases 1
     */
    public int moveDown(int x, int y) {
        int i = -2;
        int id = get(x,y).getPlayerID();
        if ((x + 1) <= boardSize - 1) {
            if (!(get(x + 1,y).isHasSpaceShip()) || get(x + 1, y).isBlackHole()) {
                removeOwner(x, y);
                i = x;
                while(!get(i, y).isHasSpaceShip() && i < boardSize - 1 && !(get(i, y).isBlackHole())) {
                    i++;
                }
                if(get(i, y).isBlackHole()) {
                    if (id == 1) {
                        setFirstPlayersShips(getFirstPlayersShips() - 1);
                        return -3;
                    } else if (id == 2) {
                        setSecondPlayersShips(getSecondPlayersShips() - 1);
                        return -3;
                    }
                } else {
                    if (!get(i, y).isHasSpaceShip()) {
                        setOwner(i, y, id);
                        return i;
                    } else if(!get(i - 1, y).isHasSpaceShip()) {
                        setOwner(i - 1, y, id);
                        return i - 1;
                    }
                }
            }
        } else {
            setOwner(x, y, id);
            return x;
        }
        return i + 1;
    }
}
