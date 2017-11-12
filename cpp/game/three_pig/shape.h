#ifndef SHAPE_H_
#define SHAPE_H_ 
#include "character.h"
class ShapeBase
{
	public:
		// MEMBER:
		vector<vector<string>> board;
		//int W;
		//int H;
		//METHOD:
		ShapeBase() {
			DENTER;
			//vector<vector<int>> 	tboard={
			//	{0,1,1,0},
			//	{1,1,1,1},
			//	{1,1,1,1},
			//	{0,1,1,1},
			//};
			DRETURN;
		};
		void show() {
			DEBUG_MARK;
			DENTER;
			DPRINT("-------------------------------");
			for(auto v1:board)
			{
				for(auto i:v1)
				{
					DEBUG_MARK;
					cout<<""<<i<<"\t";
				}
				cout<<""<<""<<endl;
			}
			DPRINT("-------------------------------");
			DRETURN;
		}
};

class Shape:public ShapeBase 
{
	public:
		// MEMBER:
		vector<Point> pList;
		string name;
		//METHOD:
		Shape()
		{
			pList.push_back(Point(0,0));
			pList.push_back(Point(1,0));
			pList.push_back(Point(2,0));
			//board={
			//	{"1"},
			//	{"1"},
			//	{"1"},
			//};
		};
		Shape(vector<Point> s)
		{
			pList=s;
		};
		void transform()
		{
			for(Point& p:pList )
			{
				p.transform();
			}
		};
		void mirrorX()
		{
			for(Point& p:pList )
			{
				p.mirrorX();
			}
		};
		void r90()
		{
			transform();
			mirrorX();
		};
		Point loc;
		void setLoc(Point p) { loc=p; }
		void setLoc(int x,int y) {
			loc.x=x;
			loc.y=y;
		}
		void moveTo00() { };
		void turn() { };
		bool apply(vector<vector<string>>& targetBoard,vector<vector<string>>& boardRef)
		{
			// zjc here
			for(auto thisP:pList)
			{
				int offsetX=loc.x+thisP.x;
				int offsetY=loc.y+thisP.y;
				//DLOG(offsetX);
				//DLOG(offsetY);
				if(offsetX>=(int)targetBoard.size())
					return 0;
				if(offsetY>=(int)targetBoard[0].size())
					return 0;
				//DLOG(targetBoard.size());
				//DLOG(targetBoard[0].size());
				if(regex_match(boardRef[offsetX][offsetY],regex("^0.*"))) 
				{
					DPRINT("CONFLICT with ^0.* !!!");
					return 0;
				}
				targetBoard[offsetX][offsetY]+=name;
				//DPRINT("APPLY targetBoard["<<offsetX<<"]["<<offsetY<<"]="<<targetBoard[offsetX][offsetY]);
				//DLOG(targetBoard[offsetX][offsetY]);
				//DLOG(regex_match(targetBoard[offsetX][offsetY],regex("^0.*")));
			}
			return 1;
		};
		void print() {
			cout<<"Shape:"<<this<<""<<endl;
			cout<<"Loc:"<<loc.x<<","<<loc.y<<endl;
			cout<<"pList:"<<""<<endl;
			for(auto p:pList)
			{
				cout<<""<<p.x<<","<<p.y<<endl;
			}
		}
		bool operator% (const Shape& rhs) const // Shape hit Shape
		{
			for(auto p1:pList )
				for(auto p2:rhs.pList)
				{
					if(p1==p2)
						return true;
				}
			return false;
		}
		bool operator% (Character & rhs) // Shape hit Character 
		{
			auto p2=rhs.getLoc();
			for(auto p1:pList )
			{
				if(p1==p2)
					return true;
			}
			return false;
		}
};
#endif
