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
	// zjc TODO
};
Shape* Matrix::getShape()
{
	return shapeList.back();
}
void Matrix::applyShape(Shape* shape){// mark shape into board
};
void Matrix::tick()
{
	for (auto shapePtr:shapeList)
	{
		// if not hit bottom or other shapes
		shapePtr->drop();
		shapePtr->update();
	}
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
	PRINTVAR(shapeList.size());
	for (auto shapePtr:shapeList)
	{
		vector<Point*> vector_dots_in_shape=shapePtr->getDots();
		PRINTVAR(vector_dots_in_shape.size());
		PRINT_DEBUG_INFO_PREFIX("core dump");
		for(Point* dot:vector_dots_in_shape)
		{
			PRINT_DEBUG_INFO_PREFIX("core dump");
			PRINTVAR(dot->x);
			PRINTVAR(dot->y);
			board[dot->x][dot->y]="0";
		}
		PRINT_DEBUG_INFO_PREFIX("core dump");
	}
	PRINT_DEBUG_INFO_PREFIX("core dump");
};


