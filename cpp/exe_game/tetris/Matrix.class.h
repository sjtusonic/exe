#ifndef MATRIX_CLASS_H
#define MATRIX_CLASS_H
#include <vector>
using namespace std;

class MATRIX
{
	public:
		MATRIX(unsigned height,unsigned width,int v=0)
		{
			mWidth=width;
			mHeight=height;
			for(int row=0;row<height;row++)
			{
				vector<int> tmp;
				for(int col=0;col<width;col++)
				{
					tmp.push_back(v);
				}
				board.push_back(tmp);
			}
		};

		MATRIX(vector<vector<int> > m)
		{
			for(vector<int> row:m)
			{
				vector<int> tmp;
				for(int cell:row)
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

		void show()
		{
			for(auto row:board)
			{
				for(auto cell:row)
				{
					cout<<cell
						<<"\t";
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
	private:
		int mWidth;
		int mHeight;
		vector<vector<int> > board;
};

# endif
