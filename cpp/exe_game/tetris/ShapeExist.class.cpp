#include "ShapeExist.class.h"

void ShapeExist::merge(Shape * shape) // merge the new added shape, after the shape doesn't move
{
}
void ShapeExist::checkDeleteRow() // then check whether to delete a row or not
{
}
void ShapeExist::update() // update all location after deleting
{
}
vector<string> ShapeExist::touch(Shape* shape)
{// zjc need unit test!

	// "NOT": not touch
	// "COINCIDE": coincide 
	// S:
	// E:
	// N:
	// W:
	vector<string> r;
	for(Point* p1:dots)
	{
		for(Point* p2:shape->getDots())
		{
			if(p1->touch(p2)=="COINCIDE")
			{
				r.push_back("HIT");
				return r;
			}
			if(p1->touch(p2)=="S") // p2 is in S
				r.push_back("S");
			if(p1->touch(p2)=="N") // p2 is in S
				r.push_back("N");
			if(p1->touch(p2)=="E") // p2 is in S
				r.push_back("E");
			if(p1->touch(p2)=="W") // p2 is in S
				r.push_back("W");
		}
	}
	if(r.size()==0)
	{
		r.push_back("NOT");
		return r;
	}
	else
		return r;
}
