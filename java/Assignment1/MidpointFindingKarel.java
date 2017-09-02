/*
 * File: MidpointFindingKarel.java
 * -------------------------------
 * When you finish writing it, the MidpointFindingKarel class should
 * leave a beeper on the corner closest to the center of 1st Street
 * (or either of the two central corners if 1st Street has an even
 * number of corners).  Karel can put down additional beepers as it
 * looks for the midpoint, but must pick them up again before it
 * stops.  The world may be of any size, but you are allowed to
 * assume that it is at least as tall as it is wide.
 */

import stanford.karel.*;

public class MidpointFindingKarel extends SuperKarel {

	// You fill in this part
	public void run() {
		int cntr=0;
		while (true) {
			if (frontIsClear()) {
				move();
				cntr++;
			} else {
				break;
			}
		}
		turnAround();
		moveMult(cntr/2);
		putBeeper();
	}

	//------------------------------
	public void turnRight() {
		turnLeft();
		turnLeft();
		turnLeft();
	}
	public void moveMult (int n) {
		int cntr=n;
		while (cntr>0) {
			move();
			cntr--;
		}
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
