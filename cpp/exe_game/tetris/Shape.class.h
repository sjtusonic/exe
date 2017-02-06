#ifndef SHAPE_CLASS_H
#define SHAPE_CLASS_H

using namespace std;
class Point
{
	/*
	 * x : row
	 * y : col
	 *
	 *   o--------------------> 
	 *   |							y
	 *   |
	 *   |
	 *   v
	 *    x
	 *
	 */
	Point(int u,int v){
		x=u; y=v;
	}
	Point shift(Point vector) {
		Point p2(x+vector.x,y+vector.y);
		return p2;
	}
	void setLoc(int u, int v) { x=u; y=v; }
	void setLoc(Point p) { x=p.x; y=p.y; }
	public:
	int x;
	int y;
};

class Shape 
{
	public:
		//Shape(unsigned height,unsigned width,string v="0"){};
		Shape(unsigned height=4,unsigned width=4,string v="#");
		Shape(vector<vector<string> > m);
		bool touchToShape(Shape* another);

		int getWidthN() ;
		int getHeightN() ;
		int getWidth() ;
		int getHeight() ;

		bool legalType() ;

		void setDots();
		vector<Point> getDots();    // return {P1,P2,...Pn};

		vector<Point> getBorder(); // return {{ul_row,ul_col},  {drx,dry}};
		int ul_row;
		int ul_col;
	private:
		string orientation;// N,E,W,S (no flip)
		int type; // 
		/* types:
		 * 0 ####
		 *
		 * 1 ## 
		 *   ##
		 *
		 * 2 ##
		 *    ##
		 *
		 * 3  ##
		 *   ##
		 *
		 * 4  #
		 *   ###
		 *
		 * 5 #
		 *   ###
		 *
		 * 6   #
		 *   ###
		 *
		 */

		vector<Point> dots;    // store dots, to save time

};
# endif
