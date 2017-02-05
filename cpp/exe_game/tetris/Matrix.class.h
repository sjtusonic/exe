#ifndef MATRIX_CLASS_H
#define MATRIX_CLASS_H
#include <vector>
#include <string>

#include "Shape.class.h"
using namespace std;

class Matrix
{
	public:
		Matrix(unsigned height,unsigned width,string v="0")
		{
			mWidth=width;
			mHeight=height;
			for(int row=0;row<height;row++)
			{
				vector<string> tmp;
				for(int col=0;col<width;col++)
				{
					tmp.push_back(v);
				}
				board.push_back(tmp);
			}
		};

		Matrix(vector<vector<string> > m)
		{
			for(vector<string> row:m)
			{
				vector<string> tmp;
				for(string cell:row)
				{
					tmp.push_back(cell);
				}
				board.push_back(tmp);
			}
		};
		int getWidth()  {return mWidth;};
		int getHeight() {return mHeight;};
		void setWidth(int w)  {mWidth=w;};
		void setHeight(int h) {mHeight=h;};

		void show(bool compacted=0)
		{
			for(vector<string> row:board)
			{
				for(string cell:row)
				{
					cout<<cell;
					if(!compacted)
						cout<<"\t";
				}
				cout<<endl;
			}
		};
		void show(int markRow,int markCol, string marker="X")
		{
			int cntRow=0;
			for(auto row:board)
			{
				int cntCol=0;
				for(auto cell:row)
				{
					if(cntRow==markRow && cntCol==markCol)
						cout<<marker <<"\t";
					else
						cout<<cell <<"\t";
					cntCol++;
				}
				cout<<endl;
				cntRow++;
			}
		}
		bool isOnEdge(unsigned row,unsigned col)
		{
			//if(row>=board.size())
			//if( col>=board[0].size())
			//if( col<0)
			//if( row<0)

			if(	row>=board.size()
					|| 	col>=board[0].size()
					|| 	col<0
					|| 	row<0)
			{
				cout<<"Error: illegal:("<<row<<","<<col<<")"<<endl;
				cout<<"Board:"<<endl;
				show();
				return false;
			}

			if(row==0 || row==board.size()-1)
				return true;
			if(col==0 || col==board[0].size()-1)
				return true;
		}
		bool isOnEdge(int row,int col)
		{
			return isOnEdge(row,col);
		}
		void addShape(Shape* shape,int loc_row=0, int loc_col=0,string anchor="up"){
			shape->loc_row=loc_row;
			shape->loc_col=loc_col;
			shapeList.push_back(shape);
		};
		void applyShape(Shape* shape){// mark shape into board
		};
	private:
		int mWidth;
		int mHeight;
		vector<vector<string> > board;
		vector<Shape*> shapeList;
};

# endif
