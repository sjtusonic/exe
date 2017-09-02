package LifeGame;

import java.util.ArrayList;


public class LifeWorld {
	LifeWorld (Integer [][] config) {
		arrayName=config;
	}
	LifeWorld (Integer width, Integer height) {
		arrayName=new Integer[width][height];
		WIDTH=width;
		HEIGHT=height;
	}

	public void init () {

		for (int i = 0; i < arrayName.length; i++) {
			for (int j = 0; j < arrayName[i].length; j++) {
				arrayName[i][j]=0;
			}
		}
	}
	public void add (Integer col,Integer row) {
		arrayName[col][row]=1;
	}
	public void showConfig () {
		System.out.println("=========================");
		System.out.println("SHOW CONFIG:");
//		System.out.println(arrayName.toString());

		for (int i = 0; i < arrayName.length; i++) {
			for (int j = 0; j < arrayName[i].length; j++) {
//				System.out.print(arrayName[i][j] + " ");
				if (arrayName[i][j]==1) {
					System.out.print("* ");
				} else {
					System.out.print("_ ");
					
				}
			}
			System.out.println();
		}
	}

	public void showStatus () {
		System.out.println("=========================");
		System.out.println("SHOW STATUS:");
		for (int i = 0; i < arrayName.length; i++) {
			for (int j = 0; j < arrayName[i].length; j++) {
				System.out.print(getNeighbourSum(i, j) + " ");
			}
			System.out.println();
		}
	}
	private Integer getNeighbourSum (Integer col,Integer row) {
		Boolean colDownIsEdge=false;
		Boolean colUpIsEdge=false;
		Boolean rowDownIsEdge=false;
		Boolean rowUpIsEdge=false;

		if (col==0) 				{colDownIsEdge=true;}
		if (col==arrayName.length-1) 	{colUpIsEdge=true;}
		if (row==0) 				{rowDownIsEdge=true;}
		if (row==arrayName.length-1) 	{rowUpIsEdge=true;}
		
		Integer sum=0;
		if (!colDownIsEdge &&!rowDownIsEdge) {sum+=arrayName[col-1][row-1];}
		if (!colDownIsEdge                 ) {sum+=arrayName[col-1][row];}
		if (!colDownIsEdge &&!rowUpIsEdge)   {sum+=arrayName[col-1][row+1];}
		
		if (                 !rowDownIsEdge) {sum+=arrayName[col][row-1];}
		if (                 !rowUpIsEdge) 	 {sum+=arrayName[col][row+1];}
		
		if (!colUpIsEdge &&!rowDownIsEdge)   {sum+=arrayName[col+1][row-1];}
		if (!colUpIsEdge                 )   {sum+=arrayName[col+1][row];}
		if (!colUpIsEdge &&!rowUpIsEdge)     {sum+=arrayName[col+1][row+1];}
		
		return sum;
	}
	
	public void update () {
		System.out.println(this+"UPDATE");

		Integer[][] newArrayName=new Integer[WIDTH][HEIGHT];
		
		for (int i = 0; i < newArrayName.length; i++) {
			for (int j = 0; j < newArrayName[i].length; j++) {
				Integer sum=getNeighbourSum(i, j);
				if (sum==3) {
					newArrayName[i][j]=1;
				} else if (sum==2) {
					newArrayName[i][j]=arrayName[i][j];
				} else {
					newArrayName[i][j]=0;
				}
//				System.out.print(newArrayName[i][j] + " ");
			}
//			System.out.println();
		}
		
		arrayName=newArrayName;
	}
	public void update (Integer steps) {
		while (steps>0) {
			update();
			steps--;
		}
	}
	Integer [][]arrayName;
	private String name;

	Integer WIDTH=10;
	Integer HEIGHT=10;
	
//	Boolean [][] config=new Boolean[WIDTH][HEIGHT];
	  
}
