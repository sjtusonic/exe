#include "global.h"
#include "Shape.class.h"
using namespace std;

//Shape::Shape(unsigned height,unsigned width,string v){}

Shape::Shape(vector<vector<string> > m){
}
Shape::Shape(int t,string ori)
{
	ul_row=0;
	ul_col=0;
	type=t;
	orientation=ori;
}

bool Shape::touchToShape(Shape* another)
{
	return false;
}
int Shape::getWidthN() {
	if(!legalType())
		return 0;
	switch(type)
	{
		case 0:
			return 4;
			break;
		case 1:
			return 2;
			break;
		default:
			return 3;
	}
};
int Shape::getHeightN() {
	if(!legalType())
		return 0;
	switch(type)
	{
		case 0:
			return 1;
			break;
		default:
			return 2;
	}
};
int Shape::getWidth() {
	if(orientation=="N")
		return getWidthN();
	if(orientation=="S")
		return getWidthN();
	if(orientation=="E")
		return getHeightN();
	if(orientation=="W")
		return getHeightN();
	return 0;
}
int Shape::getHeight() {
	if(orientation=="N")
		return getHeightN();
	if(orientation=="S")
		return getHeightN();
	if(orientation=="E")
		return getWidthN();
	if(orientation=="W")
		return getWidthN();
	return 0;
}
bool Shape::legalType() 
{
	if(type <0)
		return false;
	if(type >6)
		return false;
	return true;
};
void Shape::setDots()
{
	switch(type)
	{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			;
			//return 0;
	}
}
vector<Point> Shape::getDots()    // return {P1,P2,...Pn}
{
	return dots;
}
vector<Point> Shape::getBorder() // return {{ul_row,ul_col},  {drx,dry}}
{
	Point P_ul(ul_row,ul_col);
	Point P_dr(ul_row+getWidth(),ul_col+getHeight());
	vector<Point> r;
	r.push_back(P_ul);
	r.push_back(P_dr);
	return r;
}
