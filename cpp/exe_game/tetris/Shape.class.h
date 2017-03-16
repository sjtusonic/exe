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

		string touch(Point* p)
		{
			// "NOT": not touch
			// "COINCIDE": coincide 
			// S: p is at the S of this
			// E: p is at the E of this
			// N: p is at the N of this
			// W: p is at the W of this
			if(x==p->x)
				if(y==p->y)
					return "COINCIDE";
			if(x==p->x)
				if(y-p->y==1)
					return "W";
			if(y-p->y==-1)
				return "E";
			if(y==p->y)
				if(x-p->x==1)
					return "N";
			if(x-p->x==-1)
				return "S";
			return "NOT";
		}
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
		//bool touchToShape(Shape* another);

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
		void update_ul();
		void move(string orientation);
		void move(string orientation,unsigned times);
		void drop();
		void turn(string left_or_right);
	private:
		vector<Point*>  findTheMost(string orientation) ; // orientation={N,E,W,S};
		void showVector(vector<Point*>* vecPtr);
		void deleteFromVector(vector<Point*>* vecPtr, Point* item);
		void initShapeFaceToN(int type);
	public:
		bool hit(string orientation);
		int hit_depth(string orientation); 
		// depth <0 means not hit
		// depth =0 means touch the border
		// depth >0 means out of border
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

		TEST_CASE( "getHeightN", "[getHeightN]" ) {
			REQUIRE( getHeightN() >= 0 );
		}
};
# endif
