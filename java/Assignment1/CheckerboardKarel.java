/*
 * File: CheckerboardKarel.java
 * ----------------------------
 * When you finish writing it, the CheckerboardKarel class should draw
 * a checkerboard using beepers, as described in Assignment 1.  You
 * should make sure that your program works for all of the sample
 * worlds supplied in the starter folder.
 */

import stanford.karel.*;

public class CheckerboardKarel extends SuperKarel {
	// in order to pack to JAR:
	
	public static void main(String[] args) {
		new CheckerboardKarel().start(args);
		}
	// You fill in this part

	int locX = 0;
	int locY = 0;

	public void run() {
		while (true) {
			travelALineAndPutBeeper();
			turnLeft();
			if (frontIsClear()) {
				moveMultAndUpdateLoc(1);
			} else {
				break;
			}
			turnRight();
		}
	}

	// ------------------------------
	public void turnRight() {
		turnLeft();
		turnLeft();
		turnLeft();
	}

	public void moveMult(int n) {
		int cntr = n;
		while (cntr > 0) {
			move();
			cntr--;
		}
	}

	public void fillALine() {
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

	public void turnToEast() {
		while (!facingEast()) {
			turnLeft();
		}
	}

	public void moveMultAndUpdateLoc(int n) {
		moveMult(n);
		if (facingEast()) {
			this.locX = this.locX + n;
		}
		if (facingWest()) {
			this.locX = this.locX - n;
		}
		if (facingNorth()) {
			this.locY = this.locY + n;
		}
		if (facingSouth()) {
			this.locY = this.locY - n;
		}
	}

	public void travelALineAndPutBeeper() {
		while (true) {
			if (locX % 2 == 0) {
				if (locY % 2 == 0) {
					putBeeper();
				}
			} else {
				if (locY % 2 != 0) {
					putBeeper();
				}
			}

			if (frontIsClear()) {
				moveMultAndUpdateLoc(1);
			} else {
				break;
			}
		}
		turnAround();
		while (true) {
			if (frontIsClear()) {
				moveMultAndUpdateLoc(1);
			} else {
				break;
			}
		}
		turnAround();
	}
}
