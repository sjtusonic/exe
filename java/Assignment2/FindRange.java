/*
 * File: FindRange.java
 * Name: 
 * Section Leader: 
 * --------------------
 * This file is the starter file for the FindRange problem.
 */

import acm.program.*;

public class FindRange extends ConsoleProgram {
	public void run() {
		/* You fill this in */

		double largeBound=-99999;
		double smallBound=99999;
		print("Find the largest and smallest(0 to end):\n");
		while (true) {
			double n=readDouble("?");
			if (n==0){break;}
			if (n>largeBound) {largeBound=n;}
			if (n<smallBound) {smallBound=n;}
		}
		print("largest="+largeBound);
		print("\n");
		print("smallest="+smallBound);
	}
}

