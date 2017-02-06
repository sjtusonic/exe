#ifndef POJ1328_H
#define POJ1328_H
#include "include.top.h"
#include "gnuplot_i.h"
//#include "gnuplot_i.new.hpp"


class Point
{
	public:
		Point() {loc={0,0};D=0;};
		Point(float x,float y)
		{
			loc={x,y};
			D=0;
		};
		Point(float x,float y,float d)
		{
			loc={x,y};
			D=d;
		};
		void setLoc(float x,float y){
			//loc=make_pair(x,y);
			loc={x,y};
		};
		void setD(float d) {D=d;};
		float getD() {return D;};
		pair<float,float> getLoc(){
			return loc;
		}
		float getX () const { return loc.first; };
		float getY () const { return loc.second; };
		void show() {
			cout<<"Point\t("<<getX()<<",\t"<<getY()<<"), D="<<D<<endl;
		}
		pair<float,float> getXCover(float) ;

		bool coverPointOnXAxis(Point targetP) { // this point covers the targetP(type=coverPointOnXAxis) on x-axis
			pair<float,float> cover=getXCover(D) ;
			if(targetP.getX()>=cover.first && targetP.getX()<=cover.second)
			{
				return true;
			}
			return false;
		};

		friend ostream& operator<< (ostream& os, Point rhs) {
			os<<"Point\t("<<rhs.getX()<<",\t"<<rhs.getY()<<"), D="<<rhs.getD()<<endl;
			return os;
		};
	private:
		pair<float,float> loc;
		float D;
};

class PointOnXAxis:public Point
{
	public:
		PointOnXAxis():Point(){};
		PointOnXAxis(float x,float y):Point(x,(float)0){};
		PointOnXAxis(float x):Point(x,(float)0){};
		bool isLeftBoardOfCoverage;
		bool operator< (const PointOnXAxis rhs) const {return getX()<rhs.getX();};
		//void coverIslandsPushBack(Point p){coverIslands.push_back(p);};
		vector<Point> coverIslands;
	private:
};

class Case
{
	public:
		int N;
		float D;
		//pair<float,float> coord;
		vector<Point> islands;
		vector<PointOnXAxis> radars;
		vector<pair<float,float>> covers;
		void show();
		void solve();
		bool checkLegality();
};

void poj1328();

void show(vector<pair<float,float>>) ;

void wait_for_key(); // Programm halts until keypress

class GUI
{
	public :
		GUI(){
			GUI_DRAW_NPOINTS=100;
			//Gnuplot g("GUI");
			//string s="";
			Gnuplot g;

			g.reset_all();
			g.reset_plot();
			g.set_grid();
			try {
			} 
			catch (GnuplotException ge)
			{
				cout << ge.what() << endl;
			}

		};
		//		void drawCircle(double xc,double yc,double r,string style,string info);
		void drawCircle(double xc,double yc,double r,string style,string info="")
		{
			std::vector<double> x, y ;
			//const double PI=3.1415926;
			double theta=0;
			double theta_step=2*PI/GUI_DRAW_NPOINTS;

			for (int i = 0; i < GUI_DRAW_NPOINTS; i++)  // fill double arrays x, y, z
			{
				x.push_back(xc+r*(double)cos(theta));             // x[i] = i
				y.push_back(yc+r*(double)sin(theta)); // y[i] = i^2
				theta+=theta_step;
			}

			//cout << endl << endl << "*** user-defined lists of points (x,y)" << endl;
			//string style="points";
			g.set_style(style);
			g.plot_xy(x,y,info);
		}
		//void drawPoint(Point p);
		void drawPoint(Point p,string mode="lines")
		{
			drawCircle(p.getX(),p.getY(),0.01,mode);
			drawCircle(p.getX(),p.getY(),p.getD(),mode);
		}
		int GUI_DRAW_NPOINTS;

	private:
		Gnuplot g;
};
#endif
