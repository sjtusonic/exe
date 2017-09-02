/*
 * File: CS106ATiles.java
 * Name: 
 * Section Leader: 
 * ----------------------
 * This file is the starter file for the CS106ATiles problem.
 */

import acm.graphics.*;
import acm.program.*;

import java.awt.*;

public class CS106ATiles extends GraphicsProgram {
	
	/** Amount of space (in pixels) between tiles */
	private static final int TILE_SPACE = 20;

	private static final int TILE_WIDTH = 60;
	private static final int TILE_HEIGHT = 32;
	private static final String TILE_TEXT = "CS106A";
	
	public void run() {
		/* You fill this in. */
		double cx=this.getWidth()/2;
		double cy=this.getHeight()/2;
		double tileCenter2ThisCenterDistX=TILE_SPACE/2+TILE_WIDTH/2;
		double tileCenter2ThisCenterDistY=TILE_SPACE/2+TILE_HEIGHT/2;
		drawTile (cx-tileCenter2ThisCenterDistX,cy-tileCenter2ThisCenterDistY,Color.RED);
		drawTile (cx+tileCenter2ThisCenterDistX,cy-tileCenter2ThisCenterDistY,Color.RED);
		drawTile (cx-tileCenter2ThisCenterDistX,cy+tileCenter2ThisCenterDistY,Color.RED);
		drawTile (cx+tileCenter2ThisCenterDistX,cy+tileCenter2ThisCenterDistY,Color.RED);
	}
	//-----------------
	public GRect drawRect (double x,double y,double width, double height, Color c) {
		GRect rect=new GRect(x,y,width,height);
		rect.setFilled(false);
		rect.setColor(c);
		add(rect);
		return rect;
	}
	public GLabel drawLabel (double cx,double cy, Color c) {
		GLabel label=new GLabel(TILE_TEXT);
		label.setColor(c);
		label.setLocation(cx-label.getWidth()/2, cy-label.getHeight()/2+label.getAscent());
		add(label);
		return label;
	}
	public void drawTile (double cx,double cy, Color c) {
//		System.out.println("center="+cx+" "+cy);
//		drawOval (cx,cy,1,1,Color.red); // debug;
		
		GLabel label=drawLabel(cx, cy, c);
		
		GRect rect=drawRect(0, 0, TILE_WIDTH, TILE_HEIGHT, c);
		rect.setLocation(cx-rect.getWidth()/2, cy-rect.getHeight()/2);
		
//		System.out.println(label.getX()+"+"+label.getWidth()/2+" "+label.getY()+"+"+label.getHeight()/2);
//		System.out.println(rect.getX() +"+"+rect.getWidth()/2 +" "+rect.getY() +"+"+rect.getHeight()/2);
	}
	public GOval drawOval (double centerX,double centerY,double width, double height, Color c) {
		GOval oval=new GOval(centerX-width/2, centerY-height/2, width, height);
		oval.setFilled(true);
		oval.setColor(c);
		add(oval);
		return oval;
	}
}

