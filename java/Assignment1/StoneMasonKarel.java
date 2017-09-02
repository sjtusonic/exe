/*
 * File: StoneMasonKarel.java
 * --------------------------
 * The StoneMasonKarel subclass as it appears here does nothing.
 * When you finish writing it, it should solve the "repair the quad"
 * problem from Assignment 1.  In addition to editing the program,
 * you should be sure to edit this comment so that it no longer
 * indicates that the program does nothing.
 */

import stanford.karel.*;

public class StoneMasonKarel extends SuperKarel {

	// You fill in this part
	public void run() {
		while (true){
			turnLeft();
			fillALine();
			turnToEast();
			if (frontIsClear()) {
				if (!moveMult(4)) {
					return;
				}
			} else {
				break;
			}
		}

	}
	
//------------------------------
	public void turnRight() {
		turnLeft();
		turnLeft();
		turnLeft();
	}
	public boolean moveMult (int n) {
		int cntr=n;
		while (cntr>0) {
			if (frontIsClear()) {
				move();
			} else {
				return false;
			}
			cntr--;
		}
		return true;
	}
	public void fillALine () {
		while (true) {
			if (!beepersPresent()) {
				putBeeper();
			} 
			if (frontIsClear()) {
				move();
			} else {
				break;
			}
		}
		turnAround();
		while (true) {
			if (frontIsClear()) {
				move();
			} else {
				break;
			}
		}
		turnAround();
	}
	public void turnToEast () {
		while (!facingEast()) {turnLeft();}
	}
}
