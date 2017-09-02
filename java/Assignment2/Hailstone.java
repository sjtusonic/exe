/*
 * File: Hailstone.java
 * Name: 
 * Section Leader: 
 * --------------------
 * This file is the starter file for the Hailstone problem.
 */

import acm.program.*;

public class Hailstone extends ConsoleProgram {
	public void run() {
		/* You fill this in */
		int t=1;
		while (t<1000) {
			
			int iter_cnt =0;
//			print("Enter values:\n");
//			double n = readDouble("n: ");
			double n=t;

			while (n != 1) {
				iter_cnt++;
				double new_n;
				if (n % 2 == 1) {
					new_n = 3 * n + 1;
//					print(n + "  is odd, so I make 3n+1: " + new_n + "\n");
				} else {
					new_n = n / 2;
//					print(n + "  is even, so I take half: " + new_n + "\n");

				}
				n = new_n;
			}
			print ("TRY:"+t+" ITER:"+iter_cnt+"\n");
			t++;
		}
	}
}
