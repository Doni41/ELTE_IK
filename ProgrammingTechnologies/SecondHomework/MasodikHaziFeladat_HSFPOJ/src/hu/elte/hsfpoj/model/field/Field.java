package hu.elte.hsfpoj.model.field;

public class Field {
    private boolean hasSpaceShip;
    private boolean isBlackHole;
    private int playerID;
    private int xCoord;
    private int yCoord;
    private boolean isSelected;

    /**
     *
     * @param playerID
     * @param x
     * @param y
     * creates a new Field
     * hasSpaceShip: false
     * isBlackHole: false
     * playerID : playerID from params
     * isSelcted: false
     * xCoord: x from params
     * yCoord: y from params
     */
    public Field(int playerID, int x, int y) {
        hasSpaceShip = false;
        isBlackHole = false;
        this.playerID = playerID;
        isSelected = false;
        xCoord = x;
        yCoord = y;
    }

    /**
     *
     * @return ture if a Field has spaceship
     */
    public boolean isHasSpaceShip() {
        return hasSpaceShip;
    }

    /**
     *
     * @param hasSpaceShip
     */
    public void setHasSpaceShip(boolean hasSpaceShip) {
        this.hasSpaceShip = hasSpaceShip;
    }

    /**
     *
     * @return true if a Field is black hole
     */
    public boolean isBlackHole() {
        return isBlackHole;
    }

    /**
     *
     * @param blackHole
     */
    public void setBlackHole(boolean blackHole) {
        isBlackHole = blackHole;
    }

    /**
     *
     * @return the id a Field
     */
    public int getPlayerID() {
        return playerID;
    }

    /**
     *
     * @param playerID
     */
    public void setPlayerID(int playerID) {
        this.playerID = playerID;
        hasSpaceShip = true;
    }

    /**
     *
     * @return the x coordinate of a Field
     */
    public int getxCoord() {
        return xCoord;
    }

    /**
     *
     * @return the y coordinate of a Field
     */
    public int getyCoord() {
        return yCoord;
    }

    /**
     *
     * @return true if a Field is selected
     */
    public boolean isSelected() {
        return isSelected;
    }

    /**
     *
     * @param selected
     */
    public void setSelected(boolean selected) {
        if (!isBlackHole) {
            isSelected = selected;
        }
    }
}
