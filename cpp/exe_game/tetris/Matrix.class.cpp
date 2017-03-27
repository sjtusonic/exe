#include "global.h"
#include "Matrix.class.h"
using namespace std;

Matrix::Matrix(unsigned height,unsigned width,string v)
{
	mWidth=width;
	mHeight=height;
	for(unsigned row=0;row<height;row++)
	{
		vector<string> tmp;
		for(unsigned col=0;col<width;col++)
		{
			tmp.push_back(v);
		}
		board.push_back(tmp);
	}
};

Matrix::Matrix(vector<vector<string> > m)
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

bool Matrix::isOnEdge(unsigned row,unsigned col)
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
		//show();
		return false;
	}

	if(row==0 || row==board.size()-1)
		return true;
	if(col==0 || col==board[0].size()-1)
		return true;

	return false; // bug?
}
bool Matrix::isOnEdge(int row,int col)
{
	return isOnEdge(row,col);
}
//void Matrix::addShape(Shape* shape,int ul_row, int ul_col,string anchor)
//{
//	shape->ul_row=ul_row;
//	shape->ul_col=ul_col;
//	shapeList.push_back(shape);
//};
void Matrix::addShape(Shape* shape)
{
	shapeList.push_back(shape);
};
void Matrix::deleteShape(Shape* shape)
{
	deleteFromVectorShape(&shapeList,shape);
	//shapeList.push_back(shape);
};
Shape* Matrix::getShape()
{
	//PRINTVAR(shapeList.size());
	if(shapeList.size()==0)
		return 0;
	else
		return shapeList.back();
}
void Matrix::applyShape(Shape* shape){// mark shape into board
};
bool Matrix::tick()
{
	bool dropSucceed=false;
	bool dropSucceed_bk=dropSucceed;
	allShapesAreSteady=true;
	for (auto shapePtr:shapeList)
	{
		if(shapePtr->steady)
			continue;
		// if not hit bottom or other shapes
		dropSucceed_bk=dropSucceed;
		dropSucceed=shapePtr->drop();
		PRINTVAR(dropSucceed);
		PRINTVAR(dropSucceed_bk);
		if(!dropSucceed && !dropSucceed_bk) // steady
		{
			shapePtr->steady=true;
		}
		if(shapePtr->steady==false)
			allShapesAreSteady=false;
		shapePtr->update(); // apply data to board
	}
	if(allShapesAreSteady)
	{
		// check clean rows
		// foreach shapes to form list[row] if full clean row
		// clean row: foreach shapes { shape->clean(row)}

		PRINT_DEBUG_INFO_PREFIX("ALL STEADY!!!");
		for(int r=mHeight-1;r>=0;r--)
			if(rowIsFull(r))
			{
				cout<<"ROW IS FULL("<<r<<")"<<endl;
				cleanRow(r);
			}
		//
		// shape->clean(row) means: 
		// 	dots under row: not change 
		// 	dots in    row: delete
		// 	dots above row: drop one row 
		if(rowIsEmpty(mHeight-1))
		{
			for (auto shapePtr:shapeList)
			{
				// zjc here: bug in it:
				shapePtr->drop();
			}
		}

		// check if dead
		if(!rowIsEmpty(0))
		{
			cout<<"DEAD!!!!!!!!!!!!!!!!!"<<""<<endl;
			return false;
		}
	}
	return true;
}

void Matrix::clear()
{
	int width=mWidth;
	int height=mHeight;
	for(unsigned row=0;row<height;row++)
	{
		for(unsigned col=0;col<width;col++)
		{
			board[row][col]="X";
		}
	}
};


void Matrix::update()
{
	clear();
	//PRINTVAR(shapeList.size());
	for (auto shapePtr:shapeList)
	{
		vector<Point*> vector_dots_in_shape=shapePtr->getDots();
		//PRINTVAR(vector_dots_in_shape.size());
		//PRINT_DEBUG_INFO_PREFIX("core dump");
		for(Point* dot:vector_dots_in_shape)
		{
			//PRINT_DEBUG_INFO_PREFIX("core dump");
			//PRINTVAR(dot->x);
			//PRINTVAR(dot->y);
			//PRINTVAR(mHeight);
			//PRINTVAR(mWidth);

			PRINTVAR(shapePtr->steady);
			assert(dot->x>=0);
			assert(dot->y>=0);
			assert(dot->x<=mHeight-1);
			assert(dot->y<= mWidth-1);
			if(shapePtr->steady)
				board[dot->x][dot->y]="s";
			else
				board[dot->x][dot->y]="0";
		}
		//PRINT_DEBUG_INFO_PREFIX("core dump");
	}
	//PRINT_DEBUG_INFO_PREFIX("core dump");
};

bool Matrix::rowIsFull(int row)
{
	PRINT_DEBUG_INFO_PREFIX(row);
	vector<int> rowVec;
	for(Shape* one_shape:shapeList)
	{
		//PRINT_DEBUG_INFO();
		//PRINTVAR(one_shape);
		auto dots=one_shape->getDots();
		for(Point* one_dot:dots)
		{
			//PRINTVAR(one_dot);
			if(one_dot->x==row)
				rowVec.push_back(one_dot->y);
		}
	}
	PRINTVAR(rowVec.size());
	// check:
	if(rowVec.size()==0)
		return false;
	if(rowVec.size()<mWidth)
		return false;
	PRINT_VECTOR_hor(rowVec);
	//PRINT_DEBUG_INFO();
	sort(rowVec.begin(),rowVec.end());
	PRINT_VECTOR_hor(rowVec);
	for(int i=0;i<getWidth();i++)
	{
		if(rowVec[i]!=i)
			return false;
	}
	return true;
}
bool Matrix::rowIsEmpty(int row)
{
	PRINT_DEBUG_INFO();
	print();
	for(Shape* one_shape:shapeList)
	{
		auto dots=one_shape->getDots();
		for(Point* one_dot:dots)
		{
			if(one_dot->x==row)
				return false;
		}
	}
	return true;
}

void Matrix::cleanRow(int row)
{
	PRINT_DEBUG_INFO();
	//print();
	PRINTVAR(shapeList.size());
	//for(Shape* one_shape:shapeList)
	for (auto iter=shapeList.begin();iter!=shapeList.end();)
	{
		Shape* one_shape=*iter;
		PRINTVAR(*one_shape);
		one_shape->cleanRow(row);
		vector<Point*> dots=one_shape->getDots();
		auto size1=shapeList.size();
		if(dots.size()==0)
		{
			deleteFromVectorShape(&shapeList,one_shape);
			PRINTVAR(size1);
			PRINTVAR(shapeList.size());
			assert(size1==shapeList.size()+1);
		}
		else 
		{
			iter++;
		}
	}
	PRINTVAR(shapeList.size());
	PRINT_DEBUG_INFO();
}
void Matrix::print()
{
	PRINT_DEBUG_INFO_PREFIX("---------------------------------");
	for(Shape* one_shape:shapeList)
	{
		for(Point* one_dot:one_shape->getDots())
		{
			PRINTVAR_hor(*one_dot);
		}
		cout<<""<<""<<endl;
	}
	PRINT_DEBUG_INFO_PREFIX("---------------------------------");
}
