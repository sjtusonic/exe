#include "include.top.h"
#include <math.h>
#include <iomanip>
#include <map>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

#include <fstream>

#define SHOW_DETAILS 0
#define CH0_ENABLE 1
#define CH1_ENABLE 1
#define CH2_ENABLE 1
#define CH3_ENABLE 1

void poj1753 () 
{
	cout<<"-----------------------------------------------"<<endl;
	cout<<"poj1753"<<endl;
	//----------------------------------------------------------
	string filename="input/poj1753.in";
	std::ifstream infile(filename);
	if (!infile)
		std::cerr << "Couldn't open " << filename << " for reading\n";

	//----------------------------------------------------------
	string filename_out="output/poj1753.out";
	std::ofstream outfile(filename_out);
	if (!outfile)
		std::cerr << "Couldn't open " << filename_out << " for writing\n";


	//----------------------------------------------------------
	std::cout << "parsing " << filename << " ...\n";
#if CH0_ENABLE

	std::cout << "----------------------------------------\n";
	std::cout << "ch0. solve the problem\n";
	std::cout << "----------------------------------------\n";
	Board board_read_file("input/poj1753.in");
	cout<<"board_read_file.show()"<<endl;
	board_read_file.show();
	Board board_read_file_bk=board_read_file;

	vector<Board> solution_tranformations;
	for(int seed0=0;seed0<pow(2,16);seed0++)
	{
		Board t;
		t.deserialize(seed0);
		board_read_file.transformed_by(t);
		if (board_read_file.isPure())
			solution_tranformations.push_back(t);
	}
	sort(solution_tranformations.begin(),solution_tranformations.end());
	std::cout << "----------------------------------------\n";
	cout<<"solution_tranformations"<<endl;
	for (auto t:solution_tranformations)
	{
		t.show();
	}
	std::cout << "----------------------------------------\n";
	//----------------------------------------------------------
	// dump output file
	outfile<<solution_tranformations[0].sumOfTrue();
#endif


#if CH1_ENABLE
	Board board_all_zeros,n,t;
	board_all_zeros.show();
	std::cout << "----------------------------------------\n";
	std::cout << "ch1. find all unit transformation s\n";
	std::cout << "----------------------------------------\n";
	vector<Board> unit_transforms;
	for(int seed0=0;seed0<pow(2,16);seed0++)
	{
		n=board_all_zeros;
		t.deserialize(seed0);
		n.transformed_by(t);
		if(n.isAllBlack())
		{
			cout<<"GOT UNIT seed:"<<seed0<<endl;
			//t.show();
			unit_transforms.push_back(t);
		}
	}

	sort(unit_transforms.begin(),unit_transforms.end());
	std::cout << "================================"<< " \n";
	cout<<"show unit_transforms:"<<endl;
	for ( auto u:unit_transforms)
	{
		u.show();
	}
	std::cout << "================================"<< " \n";
#endif

#if 0
	for (auto t:unit_transforms)
	{
		PRINTVAR(t.sumOfTrue());
		t.show();
	}
#endif

	std::cout << "----------------------------------------\n";


#if CH2_ENABLE
	std::cout << "----------------------------------------\n";
	std::cout << "ch2. find the shortest clean T for a random board \n";
	std::cout << "----------------------------------------\n";
	Board before,before_bk,after,transformation,t_init;
	//before.show();
	t_init.random(time(NULL));
	//t_init.deserialize(1+4+64+256);
	//t_init.deserialize(1);
	before.transformed_by(t_init);

	//before.random(time(NULL));
	//before.deserialize(3+16);
	after=before;
	before_bk=before;
	after.show();
	//#if 1
	int seed=0;
	int   min_transformation_cnt=99;
	Board min_transformation,min_after;
	vector<Board> restore_transformations;
	while (true)
	{
		after=before_bk;
		before=before_bk;

		//PRINTVAR(seed);
		transformation.deserialize(seed);
		//transformation.show();

		after.transformed_by(transformation);
		//after.show();
		if (after.isPure())
		{
			cout<<"--------------->"<<endl;
			cout<<"\tV"<<endl;
			cout<<"before:"<<endl;
			before.show();
			cout<<"transformation:"<<endl;
			transformation.show();
			cout<<"after:"<<endl;
			after.show();
#if SHOW_DETAILS
			cout<<"DETAILS:"<<endl;
			before.transformed_by(transformation,true);
#endif
			restore_transformations.push_back(transformation);
			if (transformation.sumOfTrue()<min_transformation_cnt)
			{
				min_transformation_cnt=transformation.sumOfTrue();
				min_transformation=transformation;
				min_after=after;
			}
			cout<<"<---------------"<<endl;
		}
		if (seed==pow(2,16)) // find all possible transformation(s)
		{
			break;
		}
		seed++;
	}

	if (min_transformation_cnt!=99)
	{
		PRINTVAR(min_transformation_cnt);
		//PRINTVAR(seed);
		cout<<"before:"<<endl;
		before.show();
		cout<<"transformation:"<<endl;
		min_transformation.show();
		cout<<"after:"<<endl;
		min_after.show();
#if SHOW_DETAILS
		cout<<"DETAILS:"<<endl;
		before=before_bk;
		before.transformed_by(min_transformation,true);
#endif
	}
	else
	{
		cout<<"find all possible transformation(s) but no answer"<<endl;
		before.show();
	}

	sort(restore_transformations.begin(),restore_transformations.end());
#endif // end of CH2_ENABLE
#if CH3_ENABLE
	std::cout << "----------------------------------------\n";
	std::cout << "ch3. find combined T in restore_transformations \n";
	std::cout << "----------------------------------------\n";
	vector<Board> unit_transforms_wo_zeros;
	for (auto t:unit_transforms) // gen unit_transforms_wo_zeros, because the Board fill 0s will be contained by all transforms
	{
		if(t.sumOfTrue()!=0)
			unit_transforms_wo_zeros.push_back(t);
	}

	int size=restore_transformations.size();
	PRINTVAR(size);
	int cntr=0;
	for (auto iter=restore_transformations.begin();iter!=restore_transformations.end();)
	{
		auto t=*iter;
		PRINTVAR(cntr);
		int ind=t.transformIsCombined(unit_transforms_wo_zeros);
		if (ind!=-1)
		{
			cout<<"reduced:"<<endl;
			Board reduced=t-unit_transforms_wo_zeros[ind];
			reduced.show();
			auto find_it=find(restore_transformations.begin(),restore_transformations.end(),reduced);
			if(find_it==restore_transformations.end()) // restore_transformations doesnot contain reduced
			{
				cout<<"push_back:"<<endl;
				restore_transformations.push_back(reduced);
			}
			cout<<"erase:"<<endl;
			restore_transformations.erase(iter); // delete the combined transform
			size=restore_transformations.size();
			PRINTVAR(size);
		} 
		else 
		{
			iter++;
		}
		//if(iter!=restore_transformations.end())
		//iter++;
		cntr++;
	}
	size=restore_transformations.size();
	PRINTVAR(size);
	sort(restore_transformations.begin(),restore_transformations.end());
	std::cout << "================================"<< " \n";
	cout<<"show restore_transformations:"<<endl;
	for ( auto r:restore_transformations)
	{
		r.show();
	}
	std::cout << "================================"<< " \n";
#endif // end of CH3_ENABLE
	//after.transformed_by(before);
#if 0
	for (int cnt=0;cnt<=10;cnt++)
	{
		std::cout << "================================"<< " \n";
		before.random(time(NULL)+cnt);
		before.show();
		before.serialize();
		Board a1=before;
		a1.flip(0,1);
		a1.flip(1,1);
		Board a2=before;
		a2.flip(1,1);
		a2.flip(0,1);
		if(a1!=a2)
		{
			cout<<"a1!=a2"<<endl;
			a1.show();
			a2.show();
		}
	}
#endif
	//show_board(board);

	//----------------------------------------------------------

	std::cout << "FINISH " << " \n";
	cout<<"-----------------------------------------------"<<endl;

#if 0
	Board t1,t2,t3;
	t1.deserialize(2);
	t2.deserialize(3);
	t1.show();
	t2.show();
	//t3=t1-t2;
	//t3.show();
	bool contain=t1%t2;
	PRINTVAR(contain);

#endif
}

//---------------------------------------------------------------------
// OPERATORS:
//---------------------------------------------------------------------
void Board::operator= (const Board & rhs) 
{
	vector<vector<bool>> b=rhs.getBoard();
	for(int row=0;row<getHeight();row++)
	{
		for(int col=0;col<getWidth();col++)
		{
			//board[row][col]=b[row][col];
			setBoard(row,col,b[row][col]);
		}
	}
};
bool Board::operator== (const Board & rhs) const
{
	for(int row=0;row<getHeight();row++)
	{
		for(int col=0;col<getWidth();col++)
		{
			if (board[row][col]!=rhs.getBoard()[row][col])
				return false;
		}
	}
	return true;
};
bool Board::operator!= (const Board & rhs) const  {return !(*this==rhs);};
bool Board::operator< (const Board & rhs)   const
{
	return sumOfTrue()<rhs.sumOfTrue();
};
bool Board::operator> (const Board & rhs)   const
{
	return sumOfTrue()>rhs.sumOfTrue();
};

Board Board::operator+ (Board & rhs)   
{   
	Board r;
	//int n=this->serialize()| rhs.serialize();
	int n1=serialize();
	int n2=rhs.serialize();
	int n=n1|n2;
	//PRINTVAR(n1);
	//PRINTVAR(n2);
	//PRINTVAR(n);
	r.deserialize(n);
	return r;
};  
Board Board::operator- (Board & rhs)    // set sub
{   
	Board r;
	int n1=serialize();
	int n2=rhs.serialize();
	int n=n1&(~n2);
	//PRINTVAR(n1);
	//PRINTVAR(n2);
	//PRINTVAR(n);
	r.deserialize(n);
	return r;
};  
bool Board::operator% (Board & rhs)  // set contain
{
	if (*this == rhs)
		return true;
	else if ((*this-rhs).sumOfTrue()>0 && (rhs-*this).sumOfTrue()==0)
	{
		return true;
	}
	else 
	{
		return false;
	}
};
//---------------------------------------------------------------------
// DEFINITIONS:
//---------------------------------------------------------------------
void show_board(vector<vector<bool>> board)
{
	cout<<"-----------------------------------"<<endl;
	for(auto line:board)
	{
		for (auto c:line)
		{
			string s=c?".":"@";
			cout<<s<<"\t";
		}
		cout<<endl;
	}
	cout<<"-----------------------------------"<<endl;

}

Board::Board()
{
	for(int row=0;row<4;row++)
	{  
		vector<bool> line_vec;
		for(int col=0;col<4;col++)
		{  
			line_vec.push_back(0);
		}
		board.push_back(line_vec);
	}
}
Board::Board(string in_file_name)
{
	//cout<<"calling Board::Board(string)"<<endl;
	std::ifstream infile(in_file_name);
	if (!infile)
		std::cerr << "Couldn't open " << in_file_name << " for reading\n";
	string line;
	while (infile >> line)
	{
		vector<bool> line_vec;
		for(auto c:line)
		{
			//cout<<"GOT:"<<c<<endl;
			if(c=='b' || c=='-')
				line_vec.push_back(0);
			else
				line_vec.push_back(1);
		}
		board.push_back(line_vec);
	}
}
void Board::show()
{
	show_board(board);
}
void Board::flip(int row,int col)
{
	//cout<<"calling Board::flip("<<row<<","<<col<<")"<<endl;
	int r,c;
	r=row;
	c=col;
	if(r>=0&&r<=3&&c>=0&&c<=3)
		board[r][c]=!board[r][c];

	r=row+1;
	c=col;
	if(r>=0&&r<=3&&c>=0&&c<=3)
		board[r][c]=!board[r][c];
	r=row-1;
	c=col;
	if(r>=0&&r<=3&&c>=0&&c<=3)
		board[r][c]=!board[r][c];

	r=row;
	c=col+1;
	if(r>=0&&r<=3&&c>=0&&c<=3)
		board[r][c]=!board[r][c];
	r=row;
	c=col-1;
	if(r>=0&&r<=3&&c>=0&&c<=3)
		board[r][c]=!board[r][c];
}

void Board::random(int seed)
{
	//int seed=col+row+time(NULL);
	srand (seed);
	for (int row=0;row<=3;row++ )
	{
		for (int col=0;col<=3;col++ )
		{
			//srand (time(NULL));
			/* generate secret number between 1 and 10: */
			int randi=rand();
			int i = randi % 2;
			board[row][col]=i;
		}
	}
}


int Board::serialize() 
{
	string s="";
	for(auto line:board)
		for(auto b:line)
			s+=b?"1":"0";
	//PRINTVAR(s);
	int r=std::stoi(s,nullptr,2);
	//PRINTVAR(r);
	return r;
}
void Board::deserialize(long i,bool as_binary) 
{
	//PRINTVAR(i);
	string s;
	if (as_binary)// treat as binary
	{
		s=to_string(i);
		//PRINTVAR(s);
	}
	else // treat as decimal
	{ 
		s=DecimalToBinaryString(i);
	}
	//PRINTVAR(s);
	int ptr=0;
	for (int row=0;row<=3;row++ )
	{
		for (int col=0;col<=3;col++ )
		{
			auto c=s[ptr++];
			board[row][col]=(c=='1')?true:false;
		}
	}
}
string DecimalToBinaryString(int a)
{
	string binary = "";
	int mask = 1;
	for(int i = 0; i < 16; i++)
	{
		if((mask&a) >= 1)
			binary = "1"+binary;
		else
			binary = "0"+binary;
		mask<<=1;
	}
	//cout<<binary<<endl;
	return binary;
}
void Board::transformed_by(Board t,bool details)
{
	for (int row=0;row<=3;row++ )
	{
		for (int col=0;col<=3;col++ )
		{
			if(t.getBoard()[row][col])
			{
				if (details)
				{
					show();
					cout<<"flip ("<<row<<","<<col<<")"<<endl;
					flip(row,col);
					show();
				}
				else 
				{
					flip(row,col);
				}
			}
		}
	}
}
void Board::transformed_by(Board t)
{
	transformed_by(t,false);
}

