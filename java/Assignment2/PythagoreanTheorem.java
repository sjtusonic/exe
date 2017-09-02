/*
 * File: PythagoreanTheorem.java
 * Name: 
 * Section Leader: 
 * -----------------------------
 * This file is the starter file for the PythagoreanTheorem problem.
 */

import acm.program.*;

public class PythagoreanTheorem extends ConsoleProgram {
	public void run() {
		/* You fill this in */
		print("Enter values:\n");
		double a=readDouble("a: ");
		double b=readDouble("b: ");
		double ans=Math.sqrt(a*a+b*b);
		print("c = "+ans);
	}
}
