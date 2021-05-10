import hu.elte.hsfpoj.model.board.Board;
import org.junit.Assert;
import org.junit.Test;

public class BoardTest {

    @Test
    public void createBoard5X5() {
        // GIVEN
        Board board = new Board(5);

        // WHEN
        int blackHoleX = (board.getBoardSize() / 2);
        int blackHoleY = (board.getBoardSize() / 2);

        // TEST
        Assert.assertEquals(board.getBoardSize(), 5);
        Assert.assertEquals(board.getFirstPlayersShips(), 4);
        Assert.assertEquals(board.getSecondPlayersShips(), 4);

        Assert.assertNull(board.getSelectedField());

        Assert.assertTrue(board.get(blackHoleX, blackHoleY).isBlackHole());

        Assert.assertEquals(board.get(0,0).getPlayerID(), 1);
        Assert.assertTrue(board.get(0,0).isHasSpaceShip());
        Assert.assertEquals(board.get(0,4).getPlayerID(), 1);
        Assert.assertTrue(board.get(0,4).isHasSpaceShip());
        Assert.assertEquals(board.get(4,0).getPlayerID(), 2);
        Assert.assertTrue(board.get(4,0).isHasSpaceShip());
        Assert.assertEquals(board.get(4,4).getPlayerID(), 2);
        Assert.assertTrue(board.get(4,4).isHasSpaceShip());
        Assert.assertEquals(board.get(0,1).getPlayerID(), 0);
        Assert.assertFalse(board.get(0,1).isHasSpaceShip());
        Assert.assertEquals(board.get(1,0).getPlayerID(), 0);
        Assert.assertFalse(board.get(1,0).isHasSpaceShip());
    }

    @Test
    public void createBoard7X7 () {
        // GIVEN
        Board board = new Board(7);

        // WHEN
        int blackHoleX = (board.getBoardSize() / 2);
        int blackHoleY = (board.getBoardSize() / 2);

        // TEST
        Assert.assertEquals(board.getBoardSize(), 7);
        Assert.assertEquals(board.getFirstPlayersShips(), 6);
        Assert.assertEquals(board.getSecondPlayersShips(), 6);

        Assert.assertNull(board.getSelectedField());

        Assert.assertTrue(board.get(blackHoleX, blackHoleY).isBlackHole());

        Assert.assertEquals(board.get(0,0).getPlayerID(), 1);
        Assert.assertTrue(board.get(0,0).isHasSpaceShip());
        Assert.assertEquals(board.get(0,6).getPlayerID(), 1);
        Assert.assertTrue(board.get(0,6).isHasSpaceShip());
        Assert.assertEquals(board.get(6,0).getPlayerID(), 2);
        Assert.assertTrue(board.get(6,0).isHasSpaceShip());
        Assert.assertEquals(board.get(6,6).getPlayerID(), 2);
        Assert.assertTrue(board.get(6,6).isHasSpaceShip());
        Assert.assertEquals(board.get(0,1).getPlayerID(), 0);
        Assert.assertFalse(board.get(0,1).isHasSpaceShip());
        Assert.assertEquals(board.get(1,0).getPlayerID(), 0);
        Assert.assertFalse(board.get(1,0).isHasSpaceShip());
    }

    @Test
    public void createBoard9X9 () {
        // GIVEN
        Board board = new Board(9);

        // WHEN
        int blackHoleX = (board.getBoardSize() / 2);
        int blackHoleY = (board.getBoardSize() / 2);

        // TEST
        Assert.assertEquals(board.getBoardSize(), 9);
        Assert.assertEquals(board.getFirstPlayersShips(), 8);
        Assert.assertEquals(board.getSecondPlayersShips(), 8);

        Assert.assertNull(board.getSelectedField());

        Assert.assertTrue(board.get(blackHoleX, blackHoleY).isBlackHole());

        Assert.assertEquals(board.get(0,0).getPlayerID(), 1);
        Assert.assertTrue(board.get(0,0).isHasSpaceShip());
        Assert.assertEquals(board.get(0,8).getPlayerID(), 1);
        Assert.assertTrue(board.get(0,8).isHasSpaceShip());
        Assert.assertEquals(board.get(8,0).getPlayerID(), 2);
        Assert.assertTrue(board.get(8,0).isHasSpaceShip());
        Assert.assertEquals(board.get(8,8).getPlayerID(), 2);
        Assert.assertTrue(board.get(8,8).isHasSpaceShip());
        Assert.assertEquals(board.get(0,1).getPlayerID(), 0);
        Assert.assertFalse(board.get(0,1).isHasSpaceShip());
        Assert.assertEquals(board.get(1,0).getPlayerID(), 0);
        Assert.assertFalse(board.get(1,0).isHasSpaceShip());
    }

    @Test
    public void checkingFields5X5 () {
        // GIVEN
        Board board = new Board(5);

        // WHEN
        int blackHoleX = (board.getBoardSize() / 2);
        int blackHoleY = (board.getBoardSize() / 2);

        // TEST
        Assert.assertEquals(board.get(0,0).getPlayerID(), 1);
        Assert.assertTrue(board.get(0,0).isHasSpaceShip());
        Assert.assertEquals(board.get(0,4).getPlayerID(), 1);
        Assert.assertTrue(board.get(0,4).isHasSpaceShip());
        Assert.assertEquals(board.get(1,1).getPlayerID(), 1);
        Assert.assertTrue(board.get(1,1).isHasSpaceShip());
        Assert.assertEquals(board.get(1,3).getPlayerID(), 1);
        Assert.assertTrue(board.get(1,3).isHasSpaceShip());

        Assert.assertTrue(board.get(blackHoleX, blackHoleY).isBlackHole());

        Assert.assertEquals(board.get(4,0).getPlayerID(), 2);
        Assert.assertTrue(board.get(4,0).isHasSpaceShip());
        Assert.assertEquals(board.get(4,4).getPlayerID(), 2);
        Assert.assertTrue(board.get(4,4).isHasSpaceShip());
        Assert.assertEquals(board.get(3,1).getPlayerID(), 2);
        Assert.assertTrue(board.get(3,1).isHasSpaceShip());
        Assert.assertEquals(board.get(3,3).getPlayerID(), 2);
        Assert.assertTrue(board.get(3,3).isHasSpaceShip());
    }

    @Test
    public void checkingFields7X7 () {
        // GIVEN
        Board board = new Board(7);

        // WHEN
        int blackHoleX = (board.getBoardSize() / 2);
        int blackHoleY = (board.getBoardSize() / 2);

        // TEST
        Assert.assertEquals(board.get(0,0).getPlayerID(), 1);
        Assert.assertTrue(board.get(0,0).isHasSpaceShip());
        Assert.assertEquals(board.get(0,6).getPlayerID(), 1);
        Assert.assertTrue(board.get(0,6).isHasSpaceShip());
        Assert.assertEquals(board.get(1,1).getPlayerID(), 1);
        Assert.assertTrue(board.get(1,1).isHasSpaceShip());
        Assert.assertEquals(board.get(1,5).getPlayerID(), 1);
        Assert.assertTrue(board.get(1,5).isHasSpaceShip());
        Assert.assertEquals(board.get(2,2).getPlayerID(), 1);
        Assert.assertTrue(board.get(2,2).isHasSpaceShip());
        Assert.assertEquals(board.get(2,4).getPlayerID(), 1);
        Assert.assertTrue(board.get(2,4).isHasSpaceShip());

        Assert.assertTrue(board.get(blackHoleX, blackHoleY).isBlackHole());

        Assert.assertEquals(board.get(6,0).getPlayerID(), 2);
        Assert.assertTrue(board.get(6,0).isHasSpaceShip());
        Assert.assertEquals(board.get(6,6).getPlayerID(), 2);
        Assert.assertTrue(board.get(6,6).isHasSpaceShip());
        Assert.assertEquals(board.get(5,1).getPlayerID(), 2);
        Assert.assertTrue(board.get(5,1).isHasSpaceShip());
        Assert.assertEquals(board.get(5,5).getPlayerID(), 2);
        Assert.assertTrue(board.get(5,5).isHasSpaceShip());
        Assert.assertEquals(board.get(4,2).getPlayerID(), 2);
        Assert.assertTrue(board.get(4,2).isHasSpaceShip());
        Assert.assertEquals(board.get(4,4).getPlayerID(), 2);
        Assert.assertTrue(board.get(4,4).isHasSpaceShip());
    }

    @Test
    public void checkingFields9X9 () {
        // GIVEN
        Board board = new Board(9);

        // WHEN
        int blackHoleX = (board.getBoardSize() / 2);
        int blackHoleY = (board.getBoardSize() / 2);

        // TEST
        Assert.assertEquals(board.get(0,0).getPlayerID(), 1);
        Assert.assertTrue(board.get(0,0).isHasSpaceShip());
        Assert.assertEquals(board.get(0,8).getPlayerID(), 1);
        Assert.assertTrue(board.get(0,8).isHasSpaceShip());
        Assert.assertEquals(board.get(1,1).getPlayerID(), 1);
        Assert.assertTrue(board.get(1,1).isHasSpaceShip());
        Assert.assertEquals(board.get(1,7).getPlayerID(), 1);
        Assert.assertTrue(board.get(1,7).isHasSpaceShip());
        Assert.assertEquals(board.get(2,2).getPlayerID(), 1);
        Assert.assertTrue(board.get(2,2).isHasSpaceShip());
        Assert.assertEquals(board.get(2,6).getPlayerID(), 1);
        Assert.assertTrue(board.get(2,6).isHasSpaceShip());
        Assert.assertEquals(board.get(3,3).getPlayerID(), 1);
        Assert.assertTrue(board.get(3,3).isHasSpaceShip());
        Assert.assertEquals(board.get(3,5).getPlayerID(), 1);
        Assert.assertTrue(board.get(3,5).isHasSpaceShip());

        Assert.assertTrue(board.get(blackHoleX, blackHoleY).isBlackHole());

        Assert.assertEquals(board.get(8,0).getPlayerID(), 2);
        Assert.assertTrue(board.get(8,0).isHasSpaceShip());
        Assert.assertEquals(board.get(8,8).getPlayerID(), 2);
        Assert.assertTrue(board.get(8,8).isHasSpaceShip());
        Assert.assertEquals(board.get(7,1).getPlayerID(), 2);
        Assert.assertTrue(board.get(7,1).isHasSpaceShip());
        Assert.assertEquals(board.get(7,7).getPlayerID(), 2);
        Assert.assertTrue(board.get(7,7).isHasSpaceShip());
        Assert.assertEquals(board.get(6,2).getPlayerID(), 2);
        Assert.assertTrue(board.get(6,2).isHasSpaceShip());
        Assert.assertEquals(board.get(6,6).getPlayerID(), 2);
        Assert.assertTrue(board.get(6,6).isHasSpaceShip());
        Assert.assertEquals(board.get(5,3).getPlayerID(), 2);
        Assert.assertTrue(board.get(5,5).isHasSpaceShip());
    }

    @Test
    public void editSpaceShipNumber () {
        // GIVEN
        Board board = new Board(7);

        // WHEN

        board.setFirstPlayersShips(board.getFirstPlayersShips() - 1);
        board.setSecondPlayersShips(board.getSecondPlayersShips() - 2);
        int firstPlayerSpaceShip = board.getFirstPlayersShips();
        int secondPlayerSpaceShip = board.getSecondPlayersShips();

        // THEN
        Assert.assertEquals(board.getBoardSize()-1-1, firstPlayerSpaceShip);
        Assert.assertEquals(board.getBoardSize()-1-2, secondPlayerSpaceShip);
    }

    @Test
    public void gameOverTest5X5 () {
        // GIVEN
        Board board = new Board(5);

        // WHEN
        board.setSecondPlayersShips(board.getSecondPlayersShips() - 2);

        // THEN
        Assert.assertTrue(board.isEndOfTheGame());
    }

    @Test
    public void gameOverTest7X7 () {
        // GIVEN
        Board board = new Board(7);

        // WHEN
        board.setSecondPlayersShips(board.getSecondPlayersShips() - 3);

        // THEN
        Assert.assertTrue(board.isEndOfTheGame());
    }

    @Test
    public void gameOverTest9X9 () {
        // GIVEN
        Board board = new Board(9);

        // WHEN
        board.setSecondPlayersShips(board.getSecondPlayersShips() - 4);

        // THEN
        Assert.assertTrue(board.isEndOfTheGame());
    }

    @Test
    public void selectFieldSuccess () {
        // GIVEN
        Board board = new Board(5);

        // WHEN
        board.setSelectedField(board.get(0,0));

        // THEN
        Assert.assertEquals(board.get(0,0), board.getSelectedField());
    }

    @Test
    public void removeFieldOwner() {
        // GIVEN
        Board board = new Board(5);

        // WHEN
        board.setSelectedField(board.get(0,0));
        board.removeOwner(board.get(0,0).getxCoord(), board.get(0,0).getyCoord());

        // THEN
        Assert.assertFalse(board.get(0,0).isSelected());
        Assert.assertFalse(board.get(0,0).isHasSpaceShip());
        Assert.assertEquals(board.get(0,0).getPlayerID(), 0);
    }

    @Test
    public void setFieldOwner() {
        // GIVEN
        Board board = new Board(5);

        // WHEN
        board.setSelectedField(board.get(0,1));
        int x = board.get(0,1).getxCoord();
        int y = board.get(0,1).getyCoord();
        board.setOwner(x,y,1);

        // THEN
        Assert.assertTrue(board.get(x,y).isHasSpaceShip());
        Assert.assertEquals(board.get(x,y).getPlayerID(), 1);
    }

    @Test
    public void moveLeftToTheNextPlayer () {
        // GIVEN
        Board board = new Board(5);

        // WHEN
        int boardSize = board.getBoardSize();
        board.setSelectedField(board.get(0,boardSize - 1));
        int x = board.get(0,boardSize - 1).getxCoord();
        int y = board.get(0,boardSize - 1).getyCoord();
        int playerID = board.get(x,y).getPlayerID();
        board.moveLeft(x,y);

        // THEN
        Assert.assertEquals(board.get(x,y).getPlayerID(), 0);
        Assert.assertFalse(board.get(x,y).isHasSpaceShip());
        Assert.assertTrue(board.get(x, 1).isHasSpaceShip());
        Assert.assertEquals(board.get(x, 1).getPlayerID(), playerID);
    }

    @Test
    public void moveLeftToTheBorder () {
        // GIVEN
        Board board = new Board(5);

        // WHEN
        board.setSelectedField(board.get(0,0));
        int x = board.get(0,0).getxCoord();
        int y = board.get(0,0).getyCoord();
        int playerID = board.get(x,y).getPlayerID();
        board.moveLeft(x,y);

        // THEN
        Assert.assertTrue(board.get(x, y).isHasSpaceShip());
        Assert.assertEquals(board.get(x, y).getPlayerID(), playerID);
    }

    @Test
    public void moveRightToTheNextPlayer () {
        // GIVEN
        Board board = new Board(5);

        // WHEN
        board.setSelectedField(board.get(0,0));
        int boardSize = board.getBoardSize();
        int x = board.get(0,0).getxCoord();
        int y = board.get(0,0).getyCoord();
        int playerID = board.get(x,y).getPlayerID();
        board.moveRight(x,y);

        // THEN
        Assert.assertEquals(board.get(x,y).getPlayerID(), 0);
        Assert.assertFalse(board.get(x,y).isHasSpaceShip());
        Assert.assertTrue(board.get(x, boardSize - 1).isHasSpaceShip());
        Assert.assertEquals(board.get(x, boardSize - 1).getPlayerID(), playerID);
        Assert.assertTrue(board.get(x, boardSize - 2).isHasSpaceShip());
        Assert.assertEquals(board.get(x, boardSize - 2).getPlayerID(), playerID);
    }

    @Test
    public void moveRightToTheBorder () {
        // GIVEN
        Board board = new Board(5);

        // WHEN
        int boardSize = board.getBoardSize();
        int x = board.get(0,boardSize - 1).getxCoord();
        int y = board.get(0,boardSize - 1).getyCoord();
        int playerID = board.get(x,y).getPlayerID();
        board.setSelectedField(board.get(x,y));
        board.moveRight(x,y);

        // THEN
        Assert.assertTrue(board.get(x, y).isHasSpaceShip());
        Assert.assertEquals(board.get(x, y).getPlayerID(), playerID);
    }

    @Test
    public void moveUpToTheNextPlayer () {
        // GIVEN
        Board board = new Board(5);

        // WHEN
        int boardSize = board.getBoardSize();
        int x = board.get(boardSize - 1,boardSize - 1).getxCoord();
        int y = board.get(boardSize - 1,boardSize - 1).getyCoord();
        int playerID = board.get(x,y).getPlayerID();
        board.setSelectedField(board.get(x,y));
        board.moveUp(x,y);

        // THEN
        Assert.assertEquals(board.get(x,y).getPlayerID(), 0);
        Assert.assertFalse(board.get(x,y).isHasSpaceShip());
        Assert.assertTrue(board.get(0, y).isHasSpaceShip());
        Assert.assertEquals(board.get(0, y).getPlayerID(), 1);
        Assert.assertTrue(board.get(1, y).isHasSpaceShip());
        Assert.assertEquals(board.get(1, y).getPlayerID(), playerID);
    }

    @Test
    public void moveUpToTheBorder () {
        // GIVEN
        Board board = new Board(5);

        // WHEN
        int boardSize = board.getBoardSize();
        int x = board.get(0,boardSize - 1).getxCoord();
        int y = board.get(0,boardSize - 1).getyCoord();
        int playerID = board.get(x,y).getPlayerID();
        board.setSelectedField(board.get(x,y));
        board.moveUp(x,y);

        // THEN
        Assert.assertTrue(board.get(x, y).isHasSpaceShip());
        Assert.assertEquals(board.get(x, y).getPlayerID(), playerID);
    }

    @Test
    public void moveDownToTheNextPlayer () {
        // GIVEN
        Board board = new Board(5);

        // WHEN
        int boardSize = board.getBoardSize();
        int x = board.get(0,0).getxCoord();
        int y = board.get(0,0).getyCoord();
        int playerID = board.get(x,y).getPlayerID();
        board.setSelectedField(board.get(x,y));
        board.moveDown(x,y);

        // THEN
        Assert.assertEquals(board.get(x,y).getPlayerID(), 0);
        Assert.assertFalse(board.get(x,y).isHasSpaceShip());
        Assert.assertTrue(board.get(boardSize - 1, y).isHasSpaceShip());
        Assert.assertEquals(board.get(boardSize - 1, y).getPlayerID(), 2);
        Assert.assertTrue(board.get(boardSize - 2, y).isHasSpaceShip());
        Assert.assertEquals(board.get(boardSize - 2, y).getPlayerID(), playerID);
    }

    @Test
    public void moveUpDownTheBorder () {
        // GIVEN
        Board board = new Board(5);

        // WHEN
        int boardSize = board.getBoardSize();
        int x = board.get(boardSize - 1,boardSize - 1).getxCoord();
        int y = board.get(boardSize - 1,boardSize - 1).getyCoord();
        int playerID = board.get(x,y).getPlayerID();
        board.setSelectedField(board.get(x,y));
        board.moveDown(x,y);

        // THEN
        Assert.assertTrue(board.get(x, y).isHasSpaceShip());
        Assert.assertEquals(board.get(x, y).getPlayerID(), playerID);
    }

    @Test
    public void moveToTheBlackHole () {
        // GIVEN
        Board board = new Board(5);

        // WHEN
        int boardSize = board.getBoardSize();
        int x = board.get(1,1).getxCoord();
        int y = board.get(1,1).getyCoord();
        int playerID = board.get(x,y).getPlayerID();
        int initFirstPlayersShips = board.getFirstPlayersShips();
        board.setSelectedField(board.get(x,y));
        board.moveDown(x,y);
        board.setSelectedField(board.get(x + 1,y));
        board.moveRight(x + 1,y);

        // THEN
        Assert.assertEquals(board.getFirstPlayersShips(), initFirstPlayersShips - 1);
    }
}
