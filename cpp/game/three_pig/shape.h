#include "character.h"
class ShapeBase
{
	public:
		//int W;
		//int H;
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
		vector<vector<string>> board;
		void show() {
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

class Shape:ShapeBase 
{
	public:
		vector<Point> pList;
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
		void rotate()
		{
		};
		Point loc;
		void moveTo00()
		{
		};
		void apply(vector<vector<string>>& targetBoard){
			// zjc here
			for(auto thisP:pList)
			{
				int offsetX=loc.x+thisP.x;
				int offsetY=loc.y+thisP.y;
				DLOG(offsetX);
				DLOG(offsetY);
				targetBoard[offsetX][offsetY]+="#";
			}
		};
};
class Board:ShapeBase
{
	public:
		Board ()
		{
			DENTER;
			board={
				{"0","1","1","0"},
				{"1","1","1","1"},
				{"1","1","1","1"},
				{"0","1","1","1"},
			};
			DLOG(board.size());
			DRETURN;
		};
		vector<Character*> characterVec;
		vector<Shape*> shapeVec;

		void applyChar()
		{
			for(auto oneChar:characterVec )
			{
				auto loc=oneChar->getLoc();
				if(board[loc.x][loc.y]!="1")
				{
					DPRINT("ERROR, illegal char loc:"<<loc.x<<","<<loc.y);
				}
				board[loc.x][loc.y]=oneChar->getType();
			}
		}
		void applyShape()
		{
			for(auto oneShape:shapeVec )
			{
				oneShape->apply(board);
				//if(board[loc.x][loc.y]!="1")
				//{
				//	DPRINT("ERROR, illegal char loc:"<<loc.x<<","<<loc.y);
				//}
				//board[loc.x][loc.y]=oneChar->getType();
			}
		}
		void show() {
			DPRINT("-------------------------------");
			for(auto v1:board)
			{
				for(auto i:v1)
				{
					cout<<""<<i<<"\t";
				}
				cout<<""<<""<<endl;
			}
			DPRINT("-------------------------------");
		}

};
