package hu.elte.hsfpoj.view;

import hu.elte.hsfpoj.model.board.Board;

import javax.swing.*;
import java.awt.*;

public class ControlPanelGUI extends JPanel {
    private JPanel controlPanel;
    private Board board;
    private JButton leftButton;
    private JButton upButton;
    private JButton downButton;
    private JButton rightButton;

    /**
     *
     * @param board
     * creates a control panel with grid layout and Left, Up, Down and Right buttons with event listener
     */
    public ControlPanelGUI (Board board) {
        this.board = board;

        controlPanel = new JPanel();
        controlPanel.setLayout(new GridLayout(1, 4));

        JButton leftButton = new JButton();
        leftButton.setText("Left");
        controlPanel.add(leftButton);
        this.leftButton = leftButton;

        JButton upButton = new JButton();
        upButton.setText("Up");
        controlPanel.add(upButton);
        this.upButton = upButton;

        JButton downButton = new JButton();
        downButton.setText("Down");
        controlPanel.add(downButton);
        this.downButton = downButton;

        JButton rightButton = new JButton();
        rightButton.setText("Right");
        controlPanel.add(rightButton);
        this.rightButton = rightButton;
    }

    /**
     *
     * @return the controlPanel
     */
    public JPanel getControlPanel() {
        return controlPanel;
    }

    /**
     *
     * @return the leftButton
     */
    public JButton getLeftButton() {
        return leftButton;
    }

    /**
     *
     * @return the upButton
     */
    public JButton getUpButton() {
        return upButton;
    }

    /**
     *
     * @return the rightButton
     */
    public JButton getRightButton() {
        return rightButton;
    }

    /**
     *
     * @return the downButton
     */
    public JButton getDownButton() {
        return downButton;
    }
}
