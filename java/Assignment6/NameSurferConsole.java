/*
 * File: NameSurfer.java
 * ---------------------
 * When it is finished, this program will implements the viewer for
 * the baby-name database described in the assignment handout.
 */

import acm.graphics.GObject;
import acm.graphics.GPoint;
import acm.program.*;
import acmx.export.javax.swing.JTextField;

import java.awt.event.*;
import java.util.HashMap;

import javax.swing.*;

//public class NameSurfer extends Program implements NameSurferConstants {
public class NameSurferConsole extends ConsoleProgram implements NameSurferConstants {

/* Method: init() */
/**
 * This method has the responsibility for reading in the data base
 * and initializing the interactors at the top of the window.
 */
	public void init() {
	    // You fill this in, along with any helper methods //
		contents = new HashMap<String, GObject>();
		createController();
		addActionListeners();

		u_NameSurferDataBase=new NameSurferDataBase("names-data.txt");
//		nse=new  NameSurferEntry("Sam 1 2 3 4 5");
//		println(nse.toString());
		
//		addMouseListeners();
	}

	/* Creates the control strip at the bottom of the window */
	private void createController() {
		nameField = new JTextField(MAX_NAME);
		nameField.addActionListener(this);
		graphButton = new JButton("Graph");
		clearButton = new JButton("Clear");
		add(new JLabel("Name"), NORTH);
		add(nameField, NORTH);
		add(graphButton, NORTH);
		add(clearButton, NORTH);
	}

/* Method: actionPerformed(e) */
/**
 * This class is responsible for detecting when the buttons are
 * clicked, so you will have to define a method to respond to
 * button actions.
 */
	public void actionPerformed(ActionEvent e) {
		// You fill this in //

		Object source = e.getSource();
		if (source == graphButton || source == nameField) {
			//addBox(nameField.getText());
			String name=nameField.getText();
			name=name.substring(0, 1).toUpperCase()+name.substring(1);
			this.println("Graph: \""+name+"\"");

			NameSurferEntry nseOfInputName=u_NameSurferDataBase.findEntry(name);
//			this.println(nseOfInputName.getRank(1900));
			this.println(nseOfInputName.toString());
			this.println("DONE");
		} else if (source == clearButton) {
			this.println("Clear");
			//removeContents();
		}
	}

	/* Called on mouse press to record the coordinates of the click */
	public void mousePressed(MouseEvent e) {
//		last = new GPoint(e.getPoint());
//		currentObject = getElementAt(last);
	}
	/* Called on mouse drag to reposition the object */
	public void mouseDragged(MouseEvent e) {
	}
	
	/* Private constants */
	private static final int MAX_NAME = 25;
//	private static final double BOX_WIDTH = 120;
//	private static final double BOX_HEIGHT = 50;
	/* Private instance variables */
	private HashMap<String, GObject> contents;
	private JTextField nameField;
	private JButton graphButton;
	private JButton clearButton;

	private NameSurferDataBase u_NameSurferDataBase;
//	private GObject currentObject;
//	private GPoint last;
}
