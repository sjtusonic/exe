/*
 * File: Target.java
 * Name: 
 * Section Leader: 
 * -----------------
 * This file is the starter file for the Target problem.
 */

import acm.graphics.*;
import acm.program.*;

import java.awt.*;

public class Target extends GraphicsProgram {
	public void run() {
		/* You fill this in. */
		double centerX=this.getWidth()/2;
		double centerY=this.getHeight()/2;
		
		double r=getHeight()/3;
		drawOval(centerX,centerY,r,r,Color.RED);
		drawOval(centerX,centerY,r*2/3,r*2/3,Color.WHITE);
		drawOval(centerX,centerY,r/3,r/3,Color.RED);
	}
	//-----------------
	public GRect drawRect (double x,double y,double width, double height, Color c) {
		GRect rect=new GRect(x,y,width,height);
		rect.setFilled(false);
		rect.setColor(c);
		add(rect);
		return rect;
	}
	public GOval drawOval (double centerX,double centerY,double width, double height, Color c) {
		GOval oval=new GOval(centerX-width/2, centerY-height/2, width, height);
		oval.setFilled(true);
		oval.setColor(c);
		add(oval);
		return oval;
	}
}
