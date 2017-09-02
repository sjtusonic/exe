/*
 * File: Pyramid.java
 * Name: 
 * Section Leader: 
 * ------------------
 * This file is the starter file for the Pyramid problem.
 * It includes definitions of the constants that match the
 * sample run in the assignment, but you should make sure
 * that changing these values causes the generated display
 * to change accordingly.
 */

import acm.graphics.*;
import acm.program.*;

import java.awt.*;

import sun.java2d.loops.DrawLine;
import sun.java2d.loops.DrawRect;

public class Pyramid extends GraphicsProgram {

/** Width of each brick in pixels */
	private static final int BRICK_WIDTH = 30;

/** Height of each brick in pixels */
	private static final int BRICK_HEIGHT = 12;

/** Number of bricks in the base of the pyramid */
	private static final int BRICKS_IN_BASE = 12;
	
	private static final Color BRICKS_COLOR = Color.BLACK;
	
	public void run() {
		/* You fill this in. */
		System.out.println( this.getHeight());
		int currSumOfBricks=BRICKS_IN_BASE;
		double currX=BRICK_WIDTH*3;
		double currY=this.getHeight()-BRICK_HEIGHT;
		while (currSumOfBricks>=1) {
			drawARow(currX, currY,currSumOfBricks );
			currSumOfBricks--;
			currX+=BRICK_WIDTH/2;
			currY-=BRICK_HEIGHT;
		}
	}
	//-----------------
	public GRect drawRect (double x,double y,double width, double height, Color c) {
		GRect rect=new GRect(x,y,width,height);
		rect.setFilled(false);
		rect.setColor(c);
		add(rect);
		return rect;
	}
	public void drawARow (double startX,double startY,int numOfBricks) {
		int cntr=0;
		double currX=startX;
		double currY=startY;
		while (cntr<numOfBricks) {
			drawRect(currX, currY, BRICK_WIDTH, BRICK_HEIGHT, BRICKS_COLOR);
			currX+=BRICK_WIDTH;
			//currY+=BRICK_HEIGHT;
			cntr++;
		}
	}
}

