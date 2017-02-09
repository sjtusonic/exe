#include "global.h"
#include "Shape.class.h"
using namespace std;

//Shape::Shape(unsigned height,unsigned width,string v){}

Shape::Shape(vector<vector<string> > m){
}
Shape::Shape(int w_board,int h_board,int t,string ori)
{
	width_board=w_board;
	height_board=h_board;
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
vector<Point*> Shape::getDots()    // return {P1,P2,...Pn}
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
void Shape::init()
{
	// apply type
	//dots.clear();
	switch(type)
	{
		case 0:
			if(orientation=="N" || orientation=="S")
			{
				dots.push_back(new Point(0,0));
				dots.push_back(new Point(0,1));
				dots.push_back(new Point(0,2));
				dots.push_back(new Point(0,3));
			}
			else
			{
				dots.push_back(new Point(0,0));
				dots.push_back(new Point(1,0));
				dots.push_back(new Point(2,0));
				dots.push_back(new Point(3,0));
			}
			break;
		case 1:
			dots.push_back(new Point(0,0));
			dots.push_back(new Point(0,1));
			dots.push_back(new Point(1,1));
			dots.push_back(new Point(1,0));
			break;
		case 2:
			// zjc TODO
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
	}
}
void Shape::update()
{
	// apply orientation
	// apply ul_row,ul_col
	// apply dotsMostN, E,W,S
	findTheMost("N");
	findTheMost("E");
	findTheMost("W");
	findTheMost("S");
}
void Shape::drop()
{
	PRINT_DEBUG_INFO_PREFIX("DROP");
	//if(hit_bottom())
	if(hit("S"))
		return;
	for(Point* d:dots)
	{
		d->x++;
	}
}
void Shape::showVector(vector<Point*>* vecPtr)
{
	cout<<"==============="<<""<<endl;
	cout<<"showVector @"<<vecPtr<<" :"<<endl;
	for(auto pptr:*vecPtr)
	{
		cout<<""<<*pptr<<"\t@"<<pptr<<endl;
	}
	cout<<"==============="<<""<<endl;
}
void Shape::deleteFromVector(vector<Point*>* vecPtr, Point* item)
{
	auto vec=*vecPtr;
	int size=vec.size();
	int cntr=0;
	for (auto iter=vecPtr->begin();iter!=vecPtr->end();)
	{
		Point* t=*iter; // t is Point*
		//int ind=t.transformIsCombined(unit_transforms_wo_zeros);
		if (t==item)
		{
			cout<<"erase Point: ("<<item->x<<","<<item->y<<")"<<endl;
			//vec.erase(iter); // delete the combined transform
			vecPtr->erase(iter);
			size=vecPtr->size();
		}
		else 
		{
			iter++;
		}
		cntr++;
	}
}
vector<Point*> Shape::findTheMost(string orientation) 
{
	cout<<"calling Shape::findTheMost "<<orientation<<""<<endl;
	vector<Point*> r0;
	if(orientation=="N") {r0=dotsMostN;}
	if(orientation=="E") {r0=dotsMostE;}
	if(orientation=="W") {r0=dotsMostW;}
	if(orientation=="S") {r0=dotsMostS;}
	if(r0.size()!=0) {
		showVector(&r0);
		return r0;
	}

	dotsMostN=dots;
	dotsMostE=dots;
	dotsMostW=dots;
	dotsMostS=dots;

	for(Point* p1:dots)
	{
		for(Point* p2:dots)
		{
			if(p1==p2)
				continue;
			if(p1->x == p2->x) // same row
			{
				if(p1->y +1== p2->y )
				{
					deleteFromVector(&dotsMostE,p1);
					deleteFromVector(&dotsMostW,p2);
				}
			}
			if(p1->y == p2->y) // same col
			{
				if(p1->x +1== p2->x )
				{
					deleteFromVector(&dotsMostS,p1);
					deleteFromVector(&dotsMostN,p2);
				}
			}
		}
	}

	vector<Point*> r;
	if(orientation=="N") {r=dotsMostN;}
	if(orientation=="E") {r=dotsMostE;}
	if(orientation=="W") {r=dotsMostW;}
	if(orientation=="S") {r=dotsMostS;}
	cout<<"Shape::findTheMost "<<orientation<<" return:"<<endl;
	showVector(&r);

	return r;
}

bool Shape::hit(string orientation)
{
	string to=orientation;
	for(auto p:findTheMost(to))
	{
		if(to=="W"&& p->y==0)
		{
			cout<<"hit W"<<""<<endl;
			return true;
		}
		if(to=="E"&& width_board-p->y==1)
		{
			cout<<"hit E"<<""<<endl;
			return true;
		}
		if(to=="S"&& height_board-p->x==1)
		{
			cout<<"hit S"<<""<<endl;
			return true;
		}
	}
	return false;
}
bool Shape::hit_bottom()
{
	string to="S";
	for(auto p:findTheMost(to))
	{
		int u= height_board-p->x;
		if(u ==1)
		{
			cout<<"hit S"<<""<<endl;
			return true;
		}
	}
	return false;
}
string Shape::hit(Point p)
{
	// zjc TODO
	// foreach dot findTheMost(S), if dot is up neighbor of p, return S
	string to="S";
	for(auto p:findTheMost(to))
	{
		if(p->y>=height_board)
		{
			cout<<"hit S"<<""<<endl;
			return "S";
		}
	}
	// foreach dot findTheMost(W), if dot is up neighbor of p, return W
	// foreach dot findTheMost(E), if dot is up neighbor of p, return E
}
