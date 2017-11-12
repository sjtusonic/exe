#include "character.h"
#include "shape.h"
class Board:public ShapeBase
{
	public:
		// MEMBER
		vector<Character*> characterVec;
		vector<Shape*> shapeVec;
		vector<vector<string>> boardShape;
		// METHOD
		Board ()
		{
			DENTER;
			board={
				{"0","1","1","0"},
				{"1","1","1","1"},
				{"1","1","1","1"},
				{"0","1","1","1"},
			};
			boardShape={
				{"","","",""},
				{"","","",""},
				{"","","",""},
				{"","","",""},
			};
			DLOG(board.size());
			DRETURN;
		};
		//Board& operator=(Board& other)
		//{
		//}

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
		void resetShape()
		{
			boardShape={
				{"","","",""},
				{"","","",""},
				{"","","",""},
				{"","","",""},
			};
		}
		bool applyShape()
		{
			for(auto oneShape:shapeVec )
			{
				bool r=oneShape->apply(boardShape,board);
				if(!r)
					return 0;
				//if(board[loc.x][loc.y]!="1")
				//{
				//	DPRINT("ERROR, illegal char loc:"<<loc.x<<","<<loc.y);
				//}
				//board[loc.x][loc.y]=oneChar->getType();
			}
			return 1;
		}
		void show() {
			DEBUG_MARK;
			DPRINT("-------------------------------");
			int ii=0,jj=0;
			for(auto v1:board)
			{
				jj=0;
				for(auto i:v1)
				{
					cout<<""<<i;
					if(i=="")
						cout<<"_";
					//DLOG(ii);
					//DLOG(jj);
						//DLOG(boardShape.size());
						//DLOG(boardShape[ii].size());
					if(boardShape.size()>ii && boardShape[ii].size()>jj )
					{
						//DPRINT("use boardShape:"<<ii<<","<<jj);
						cout<<boardShape[ii][jj];
					}
					cout<<"\t";
					jj++;
				}
				cout<<""<<""<<endl;
				ii++;
			}
			DPRINT("-------------------------------");
		}
		void showBoardShape() {
			DEBUG_MARK;
			DPRINT("-------------------------------");
			for(auto v1:boardShape )
			{
				for(auto i:v1)
				{
					cout<<""<<i;
					if(i=="")
						cout<<"_";

					cout<<"\t";
				}
				cout<<""<<""<<endl;
			}
			DPRINT("-------------------------------");
		}

};
