package LifeGame;

import acm.util.*;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;


public class LifeGame {
	
	public static void main(String[] args) {
		System.out.println("Hello!");
		
		LifeWorld world=new LifeWorld(10,10);
		world.init();
		world.add(5, 1);
		world.add(6, 2);
		world.add(7, 3);
		world.add(8, 4);
//		world.add(5, 5);
		world.showConfig();
//		world.showStatus();
		
		Integer cntr=100;
		while (cntr>0) {
			world.update();
			world.showConfig();
			cntr--;
			
		}
//		world.showStatus();
		
	}

}
