#include "include.top.h"
class Board
{
	public:
		Board() ;
		Board(string ) ;
		//Board(vector<vector<bool>> );
		//-----------------------------------------------------------
		void show();
		void random(int);
		void flip(int,int);
		const vector<vector<bool>>& getBoard() const {return board;};
		void setBoard(int row,int col,bool v) 
		{
			board[row][col]=v;
		};
		int  getWidth()  const {return board.size();};
		int  getHeight() const {return board[1].size();};
		bool isAllBlack() 
		{
			for(int row=0;row<getHeight();row++)
			{
				for(int col=0;col<getWidth();col++)
				{
					if (board[row][col]!=0)
						return false;
				}
			}
			return true;
		};
		bool isAllWhite() 
		{
			for(int row=0;row<getHeight();row++)
			{
				for(int col=0;col<getWidth();col++)
				{
					if (board[row][col]!=1)
						return false;
				}
			}
			return true;
		};
		bool isPure() {return (isAllBlack() || isAllWhite());};
		int transformIsCombined(vector<Board> basicTransforms) {
			int ind=0;
			for(auto b:basicTransforms)
			{
				if((*this)%b)
				{
					cout<<"======================"<<endl;
					cout<<"transformIsCombined:"<<endl;
					this->show();
					b.show();
					cout<<"======================"<<endl;
					return ind;
				}
				ind++;
			}
			return -1;
		};
		int  serialize();
		void deserialize(long,bool as_binary=false);
		void transformed_by(Board t);
		void transformed_by(Board t,bool details);
		int  sumOfTrue() const
		{
			int r=0;
			for(int row=0;row<getHeight();row++)
			{
				for(int col=0;col<getWidth();col++)
				{
					if (board[row][col])
						r++;
				}
			}
			return r;
		};
		//-----------------------------------------------------------
		void  operator=  (const Board & rhs) ;
		bool  operator== (const Board & rhs) const;
		bool  operator!= (const Board & rhs) const;
		bool  operator<  (const Board & rhs) const;
		bool  operator>  (const Board & rhs) const;
		bool  operator%  ( Board & rhs) ; // set contains
		Board operator+ (Board & rhs)   ;
		Board operator- (Board & rhs)   ; // set sub
		//-----------------------------------------------------------
	private:
		vector<vector<bool>> board;
};

void poj1753();

void show_board(vector<vector<bool>> board);
string DecimalToBinaryString(int a);

