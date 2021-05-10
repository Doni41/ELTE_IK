package hu.elte.hsfpoj.view;

import javax.swing.*;

public class MenuBarGUI extends JMenuBar {
    private JMenuBar menuBar;
    private JMenu mainMenu;
    private JMenu newMenu;
    private JMenuItem exitMenu;

    /**
     * creates a MenuBarGUI with two options
     * New game creates a new game with 5X5, 7X7 or 9X9 boardSize
     * Exit exits the application
     */
    public MenuBarGUI() {
        menuBar = new JMenuBar();
        mainMenu = new JMenu("Menu");
        menuBar.add(mainMenu);
        newMenu = new JMenu("New Game");
        mainMenu.add(newMenu);
        exitMenu = new JMenuItem("Exit");
        mainMenu.add(exitMenu);
    }

    /**
     *
     * @return the menuBar
     */
    public JMenuBar getMenuBar() {
        return menuBar;
    }

    /**
     *
     * @return the newMenu
     */
    public JMenu getNewMenu() {
        return newMenu;
    }

    /**
     *
     * @return the exitMenu
     */
    public JMenuItem getExitMenu() {
        return exitMenu;
    }
}
