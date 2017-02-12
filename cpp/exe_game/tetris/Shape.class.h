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
	public:
		Point(int u,int v){
			x=u; y=v;
		}
		Point shift(Point vector) {
			Point p2(x+vector.x,y+vector.y);
			return p2;
		}
		void setLoc(int u, int v) { x=u; y=v; }
		void setLoc(Point p) { x=p.x; y=p.y; }

		int getX(){return x;};
		int getY(){return y;};
		friend ostream& operator<< (ostream& os, Point rhs) {
			//os<<"Point\t("<<rhs.getX()<<",\t"<<rhs.getY()<<")"<<endl;
			os<<"Point\t("<<rhs.getX()<<",\t"<<rhs.getY()<<")";
			return os;
		};

	public:
		int x;
		int y;
};

class Shape 
{
	public:
		int width_board;
		int height_board;
		//Shape(unsigned height,unsigned width,string v="0"){};
		//Shape(unsigned height=4,unsigned width=4,string v="#");
		Shape(vector<vector<string> > m);
		Shape(int w_board,int h_board,int type=0,string ori="N");
		bool touchToShape(Shape* another);

		int getWidthN() ;
		int getHeightN() ;
		int getWidth() ;
		int getHeight() ;

		bool legalType() ;

		void setDots();
		vector<Point*> getDots();   // return {P1,P2,...Pn};

		vector<Point> getBorder(); // return {{ul_row,ul_col},  {drx,dry}};
		int ul_row;
		int ul_col;
		void init(); // apply type
		void update(); // apply orientation,ul_row,ul_col to dots
		void move(string orientation);
		void drop();
		void turn(string left_or_right);
	private:
		vector<Point*>  findTheMost(string orientation) ; // orientation={N,E,W,S};
		void showVector(vector<Point*>* vecPtr);
		void deleteFromVector(vector<Point*>* vecPtr, Point* item);
		void initShapeFaceToN(int type);
	public:
		bool hit(string orientation);
		bool hit_bottom();
		string hit(Point p);// return R={N,E,W,S," "} hit the point to move towards the R orientation, " " means not hit 

		// LV1 MEMBERS:
		// written by outside
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

		// LV2 MEMBERS:
		// written by update()
		vector<Point*> dots;    // store dots, to save time
		vector<Point*> dotsMostN; 
		vector<Point*> dotsMostE; 
		vector<Point*> dotsMostW; 
		vector<Point*> dotsMostS; 

};
# endif
