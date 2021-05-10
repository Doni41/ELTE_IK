package hu.elte.hsfpoj.view;

import hu.elte.hsfpoj.model.board.Board;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class BoardGUI extends JPanel {

    private JButton[][] buttons;
    private Board board;
    private JPanel boardPanel;
    private int boardSize;
    int clickNum;

    /**
     *
     * @param boardSize
     * creates a new boardGUI with the boardSize
     * init the clickNum to 0 and renders the board
     */
    public BoardGUI (int boardSize) {
        render(boardSize);
        this.boardSize = boardSize;
        clickNum = 0;
    }

    /**
     *
     * @return the matrix of the buttons
     */
    public JButton[][] getButtons() {
        return buttons;
    }

    /**
     *
     * @return the board
     */
    public Board getBoard() {
        return board;
    }

    /**
     *
     * @return the boardPanel
     */
    public JPanel getBoardPanel() {
        return boardPanel;
    }

    /**
     *
     * @param button
     * @param path
     * with the path sets an image to the button
     */
    public void imgSetter (JButton button, String path) {
        try {
            Image img = ImageIO.read(getClass().getResource(path));
            button.setIcon(new ImageIcon(img));
        } catch (Exception ex) {
            System.out.println(ex);
        }
    }

    /**
     *
     * @param x
     * @param y
     * @return a Field from the board
     */
    public JButton getButton (int x, int y) {
        return buttons[x][y];
    }

    /**
     *
     * @param boardSize
     * creates a new Board with boardSize and sets the grid layout
     * sets the picture of the buttons
     * adds button listener to every button
     */
    public void render(int boardSize) {
        board = new Board(boardSize);
        boardPanel = new JPanel();
        boardPanel.setLayout(new GridLayout(boardSize, boardSize));
        buttons = new JButton[boardSize][boardSize];

        for (int i = 0; i < board.getBoardSize(); i++) {
            for (int j = 0; j < board.getBoardSize(); j++) {
                int playerID = board.get(i, j).getPlayerID();

                JButton button = new JButton();

                if (playerID == 1) {
                    imgSetter(button, "images/blue_rocket.png");
                } else if (playerID == 2) {
                    imgSetter(button, "images/red_rocket.png");
                } else if (board.get(i, j).isBlackHole()) {
                    imgSetter(button, "images/black_hole.png");
                } else {
                    imgSetter(button, "images/empty.png");
                }

                button.addActionListener(new ButtonListener(i, j));
                button.setPreferredSize(new Dimension(70, 50));
                button.setBackground(Color.white);
                button.setOpaque(true);
                button.setBorderPainted(true);
                buttons[i][j] = button;
                boardPanel.add(button);
            }
        }
    }

    /**
     *
     * @param id
     * @return the path of a picture for the buttons
     * helper function
     */
    public String stringHelper (int id) {
        if (id == 1) {
            return "images/blue_rocket.png";
        } else if (id == 2) {
            return "images/red_rocket.png";
        } else {
            return "images/empty.png";
        }
    }

    /**
     *
     * @param x
     * @param y
     * modify the background and boarder of a button
     */
    public void deselectButton (int x, int y) {
        board.get(x,y).setSelected(false);
        getButtons()[x][y].setBackground(Color.white);
        getButtons()[x][y].setOpaque(true);
        getButtons()[x][y].setBorderPainted(true);
        board.setSelectedField(null);
    }

    /**
     * increaes the clickNum for the players
     */
    public void increaseClickNum () {
        clickNum += 1;
    }

    /**
     *
     * @return 1 if the game is over and creates a new showMessageDialog with the if of a player
     */
    public int gameOver () {
        int gameOver = 0;
        if (board.isEndOfTheGame()) {
            if (board.getFirstPlayersShips() < board.getSecondPlayersShips()) {
                JOptionPane.showMessageDialog(boardPanel,
                        "Player 1 won the game" + JOptionPane.PLAIN_MESSAGE);
                gameOver = 1;
            } else {
                JOptionPane.showMessageDialog(boardPanel,
                        "Player 2 won the game" + JOptionPane.PLAIN_MESSAGE);
                gameOver = 1;
            }
        }
        return gameOver;
    }

    public class ButtonListener implements ActionListener {
        private int x;
        private int y;

        /**
         *
         * @param x
         * @param y
         * creates a button listener to every button
         */
        public ButtonListener(int x, int y) {
            this.x = x;
            this.y = y;
        }

        /**
         *
         * @param actionEvent
         * overrides the actionPerformed method
         * if selectedPlayer is null and clicknum % 2 == 0 sets the first players Field to selected
         * if selectedPlayer is null and clicknum % 2 == 1 sets the second players Field to selected
         * if selectedPlayer is not null and we clicked the selected Field again the method unselect the Field
         */
        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            if (!(board.isEndOfTheGame()) && (!board.get(x,y).isBlackHole())) {
                if ((clickNum % 2 == 0 && board.get(x,y).getPlayerID() == 1)
                        || (clickNum % 2 == 1 && board.get(x,y).getPlayerID() == 2)) {
                    if(board.get(x, y).isSelected() && board.getSelectedField() != null) {
                        board.get(x,y).setSelected(false);
                        getButtons()[x][y].setBackground(Color.white);
                        getButtons()[x][y].setOpaque(true);
                        getButtons()[x][y].setBorderPainted(true);
                        board.setSelectedField(null);
                    } else if(board.getSelectedField() == null) {
                        board.get(x,y).setSelected(true);
                        board.setSelectedField(board.get(x,y));
                        getButtons()[x][y].setBackground(Color.green);
                        getButtons()[x][y].setOpaque(true);
                        getButtons()[x][y].setBorderPainted(true);
                    }
                }
            }
        }
    }
}
