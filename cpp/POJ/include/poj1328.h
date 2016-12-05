#include "include.top.h"
#include <set>

class Point
{
	public:
		void setLoc(float x,float y){
			//loc=make_pair(x,y);
			loc={x,y};
		};
		pair<float,float> getLoc(){
			return loc;
		}
		float getX () { return loc.first; };
		float getY () { return loc.second; };
	private:
		pair<float,float> loc;
};

class Case
{
	public:
		int N;
		int D;
		//pair<float,float> coord;
		set<Point> islands;
		set<Point> radars;
};
void poj1328();
std::vector<std::string> split(std::string str,std::string pattern) ;

