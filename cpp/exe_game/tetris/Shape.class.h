#ifndef SHAPE_CLASS_H
#define SHAPE_CLASS_H

using namespace std;
class Shape 
{
	public:
		//Shape(unsigned height,unsigned width,string v="0"){};
		Shape(unsigned height=4,unsigned width=4,string v="X"){
		};
		Shape(vector<vector<string> > m){
		};
		bool touchToShape(Shape* another){
		};
		int loc_row;
		int loc_col;
	private:
		string orientation;// N,E,W,S
};
# endif
