#include "global.h"
#include "Display.class.h"
void Display::show(bool compacted)
{
	auto board=m->getBoard();
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

void Display::show(int markRow,int markCol, string marker)
{
	PRINT_DEBUG_INFO();
	auto board=m->getBoard();
	PRINT_DEBUG_INFO();
	int cntRow=0;
	PRINT_DEBUG_INFO();
	for(auto row:board)
	{
		PRINT_DEBUG_INFO();
		int cntCol=0;
		for(auto cell:row)
		{
			PRINT_DEBUG_INFO();
			if(cntRow==markRow && cntCol==markCol)
				cout<<marker <<"\t";
			else
				cout<<cell <<"\t";
	PRINT_DEBUG_INFO();
			cntCol++;
		}
	PRINT_DEBUG_INFO();
		cout<<endl;
		cntRow++;
	PRINT_DEBUG_INFO();
	}
}
