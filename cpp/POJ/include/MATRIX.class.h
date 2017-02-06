#ifndef MATRIX_CLASS_H
#define MATRIX_CLASS_H
template<class T>
class Point
{
	public:
		Point() {loc={0,0};};
		Point(T x,T y)
		{   
			loc={x,y};
		};  
		void setLoc(T x,T y){ 
			//loc=make_pair(x,y);
			loc={x,y};
		};  
		void setX(T x) {loc.first=x;};
		void setY(T y) {loc.second=y;};
		pair<T,T> getLoc(){
			return loc;
		}   
		T getX () const { return loc.first; };
		T getY () const { return loc.second; };
		void incrX(){
			int u=getX();
			u++;
			setX(u);
		}
		void decrX(){
			int u=getX();
			u--;
			setX(u);
		}
		void incrY(){
			int u=getY();
			u++;
			setY(u);
		}
		void decrY(){
			int u=getY();
			u--;
			setY(u);
		}
		void show() {
			cout<<"Point\t("<<getX()<<",\t"<<getY()<<")"<<endl;
		}   

		friend ostream& operator<< (ostream& os, Point rhs) {
			os<<"Point\t("<<rhs.getX()<<",\t"<<rhs.getY()<<")"<<endl;
			return os; 
		};  
	private:
		pair<T,T> loc;
};



template<class T>
class MATRIX
{
	public:
		MATRIX(unsigned height,unsigned width,T v=0)
		{
			mWidth=width;
			mHeight=height;
			for(T row=0;row<height;row++)
			{
				vector<T> tmp;
				for(T col=0;col<width;col++)
				{
					tmp.push_back(v);
				}
				board.push_back(tmp);
			}
		};
		MATRIX(vector<vector<T>> m)
		{
			for(auto row:m)
			{
				vector<T> tmp;
				for(auto cell:row)
				{
					tmp.push_back(cell);
				}
				board.push_back(tmp);
			}
		}
		T getWidth()  {return mWidth;};
		T getHeight() {return mHeight;};
		void setWidth(T w)  {mWidth=w;};
		void setHeight(T h) {mHeight=h;};

		void fill(T v)
		{
			board.clear();
			T width=mWidth;
			T height=mHeight;
			for(T row=0;row<height;row++)
			{
				vector<T> tmp;
				for(T col=0;col<width;col++)
				{
					tmp.push_back(v);
				}
				board.push_back(tmp);
			}
		};
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
		bool isOnEdge(Point<int>p)
		{
			return isOnEdge(p.getX(),p.getY());
		}
	private:
		T mWidth;
		T mHeight;
		vector<vector<T>> board;
};

# endif
