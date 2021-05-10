package hu.elte.hsfpoj.view;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class BlackHoleGUI {

    private JFrame frame;
    private BoardGUI boardGUI;
    private MenuBarGUI menuBarGUI;
    private ControlPanelGUI controlPanel;
    private JPanel boardPanel;
    private JMenuBar menuBar;
    private JMenu newMenu;
    private JMenuItem exitMenu;
    private int[] boardSizes = {5, 7, 9};

    private final int INITIAL_BOARD_SIZE = 5;

    /**
     * creates a new BlackHoleGUI
     */
    public BlackHoleGUI() {
        initGame();
    }

    /**
     * setting the grid layout of the GUI
     */
    public void initBoard() {
        GroupLayout layout = new GroupLayout(frame.getContentPane());
        frame.getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addContainerGap()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(boardPanel, javax.swing.GroupLayout.DEFAULT_SIZE,
                                                javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(controlPanel, javax.swing.GroupLayout.DEFAULT_SIZE,
                                                javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                .addContainerGap())
        );

        layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addComponent(controlPanel, javax.swing.GroupLayout.PREFERRED_SIZE, 49,
                                        javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(boardPanel, javax.swing.GroupLayout.DEFAULT_SIZE, 244,
                                        Short.MAX_VALUE)
                                .addContainerGap())
        );
    }

    /**
     * creates a new JFrame with title and default close operation
     * creates a new menubar with menu options and action listeners
     * creates a board with the selected boardSize
     * add action listeners to the navigation buttons
     */
    public void initGame () {
        frame = new JFrame("Black Hole Game");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        menuBarGUI = new MenuBarGUI();
        menuBar = menuBarGUI.getMenuBar();
        newMenu = menuBarGUI.getNewMenu();
        exitMenu = menuBarGUI.getExitMenu();
        exitMenu.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                System.exit(0);
            }
        });
        frame.setJMenuBar(menuBar);

        boardGUI = new BoardGUI(INITIAL_BOARD_SIZE);

        for (int boardSize : boardSizes) {
            JMenuItem sizeMenuItem = new JMenuItem(boardSize + " x " + boardSize);
            newMenu.add(sizeMenuItem);
            sizeMenuItem.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent actionEvent) {
                    frame.getContentPane().remove(boardGUI.getBoardPanel());
                    boardGUI = new BoardGUI(boardSize);
                    boardPanel = boardGUI.getBoardPanel();
                    initBoard();
                    frame.pack();
                }
            });
        }

        controlPanel = new ControlPanelGUI(boardGUI.getBoard());

        controlPanel.getLeftButton().addActionListener(new DirectionButtonListener(1));
        controlPanel.getUpButton().addActionListener(new DirectionButtonListener(2));
        controlPanel.getRightButton().addActionListener(new DirectionButtonListener(3));
        controlPanel.getDownButton().addActionListener(new DirectionButtonListener(4));

        frame.add(controlPanel.getControlPanel());

        frame.pack();
        frame.setVisible(true);
    }

    public class DirectionButtonListener implements ActionListener {
        private int direction;

        /**
         * creates a button listener with the id of the direction
         * @param direction
         */
        public DirectionButtonListener(int direction) {
            this.direction = direction;
        }

        /**
         *
         * @param actionEvent
         * override the actionPerformed function
         * with the x and y coordinates and the ID of a Field calls the buttonAction function
         */
        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            if (boardGUI.getBoard().getSelectedField() != null) {
                int x = boardGUI.getBoard().getSelectedField().getxCoord();
                int y = boardGUI.getBoard().getSelectedField().getyCoord();
                int id = boardGUI.getBoard().getSelectedField().getPlayerID();
                if (direction == 1) {
                    buttonAction(x,y,id);
                } else if (direction == 2) {
                    buttonAction(x,y,id);
                } else if (direction == 3) {
                    buttonAction(x,y,id);
                } else if (direction == 4) {
                    buttonAction(x,y,id);
                }
            }
        }

        /**
         *
         * @param x
         * @param y
         * @param id
         * @param direction
         * with the return value of the moveLeft, moveRight, moveUp or moveDown function, rendering the image for
         * the field with the new attributes
         */
        public void renderNewImage(int x, int y, int id, int direction) {
            boardGUI.imgSetter(boardGUI.getButton(x,y), "images/empty.png");
            int i = -10;
            if (direction == 1) {
                i = boardGUI.getBoard().moveLeft(x,y);
                if (i == -1) {
                    boardGUI.imgSetter(boardGUI.getButton(x,y), boardGUI.stringHelper(id));
                } else if (i > -1) {
                    boardGUI.imgSetter(boardGUI.getButton(x,i), boardGUI.stringHelper(id));
                }
            } else if (direction == 2) {
                i = boardGUI.getBoard().moveUp(x, y);
                if (i == -1) {
                    boardGUI.imgSetter(boardGUI.getButton(x,y), boardGUI.stringHelper(id));
                } else if (i > -1) {
                    boardGUI.imgSetter(boardGUI.getButton(i,y), boardGUI.stringHelper(id));
                }
            } else if (direction == 3) {
                i = boardGUI.getBoard().moveRight(x,y);
                if (i == -1) {
                    boardGUI.imgSetter(boardGUI.getButton(x,y), boardGUI.stringHelper(id));
                } else if (i > -1) {
                    boardGUI.imgSetter(boardGUI.getButton(x,i), boardGUI.stringHelper(id));
                }
            } else {
                i = boardGUI.getBoard().moveDown(x,y);
                if (i == -1) {
                    boardGUI.imgSetter(boardGUI.getButton(x,y), boardGUI.stringHelper(id));
                } else if (i > -1) {
                    boardGUI.imgSetter(boardGUI.getButton(i,y), boardGUI.stringHelper(id));
                }
            }
        }

        /**
         *
         * @param x
         * @param y
         * @param id
         * helper function wich calls the renderNewImage function
         * deselect the button(Field) and increase the clickNum for the players
         * if the game is over, creates a new game with the same boardSize
         */
        public void buttonAction(int x, int y, int id) {
            renderNewImage(x, y, id, direction);
            boardGUI.deselectButton(x, y);
            boardGUI.increaseClickNum();
            int tmp = boardGUI.gameOver();
            if (tmp == 1) {
                frame.getContentPane().remove(boardGUI.getBoardPanel());
                boardGUI = new BoardGUI(boardGUI.getBoard().getBoardSize());
                boardPanel = boardGUI.getBoardPanel();
                initBoard();
                frame.pack();
            }
        }
    }
}
