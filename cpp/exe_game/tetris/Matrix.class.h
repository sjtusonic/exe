#ifndef MATRIX_CLASS_H
#define MATRIX_CLASS_H
#include <vector>
#include <string>

#include "Shape.class.h"
using namespace std;

class Matrix
{
	public:
		Matrix(unsigned height,unsigned width,string v="0");

		Matrix(vector<vector<string> > m);
		int getWidth()  {return mWidth;};
		int getHeight() {return mHeight;};
		void setWidth(int w)  {mWidth=w;};
		void setHeight(int h) {mHeight=h;};

		bool isOnEdge(unsigned row,unsigned col);
		bool isOnEdge(int row,int col);
		//void addShape(Shape* shape,int ul_row=0, int ul_col=0,string anchor="up");
		void addShape(Shape* shape);
		void deleteShape(Shape* shape);
		Shape* getShape();
		void applyShape(Shape* shape);
		vector<Shape*> getShapeList(){return shapeList;};
		bool tick(); // time++
		void clear(); // apply all blank to board
		void update(); // apply data to board
		vector<vector<string> > getBoard() {return board;};
		bool rowIsFull(int row);
		bool rowIsEmpty(int row);
		void cleanRow(int row);
		void print();
		bool getAllShapesAreSteady() {return allShapesAreSteady;};
	private:
		int mWidth;
		int mHeight;
		vector<vector<string> > board; 
		// X : blank
		// 0 : dot
		vector<Shape*> shapeList;
		bool allShapesAreSteady;
};

# endif
