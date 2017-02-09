//--------------------------------------
// include lib files
//--------------------------------------
//#include <curses.h>

#include "global.h"
#include "Display.class.h"
#include "Control.class.h"
#include "TetrisCalc.class.h"
#include "Matrix.class.h"

using namespace std;
//--------------------------------------
// include local files
//--------------------------------------
//#include "include/f13_2.h"
//#include "lib.h"
//#include "include.top.h"
//#include "gnuplot_i.h"

#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define PRINT_ARRAY(a,len)  for(int u=0;u<len;u++) {std::cout<<u<<":\t"<<*a+u<<std::endl;}
#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<std::endl;}
#define PRINT_VECTOR_hor(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;

#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)
//--------------------------------------

void deleteFromVector(vector<Point*>* vecPtr, Point* item)
{
	auto vec=*vecPtr;
	int size=vec.size();
	int cntr=0;
	for (auto iter=vecPtr->begin();iter!=vecPtr->end();)
	{
		Point* t=*iter; // t is Point*
		//int ind=t.transformIsCombined(unit_transforms_wo_zeros);
		if (t==item)
		{
			//cout<<"erase:"<<endl;
			//vec.erase(iter); // delete the combined transform
			vecPtr->erase(iter);
			size=vecPtr->size();
		}
		else 
		{
			iter++;
		}
		cntr++;
	}
}

#ifdef UNIT_TEST
void test_Control() {
	// test control
	cout<<"==================="<<""<<endl;
	cout<<"TEST CLASS: Constrol"<<""<<endl;
	cout<<"==================="<<""<<endl;
	Control c; c.run();
	cout<<"==================="<<""<<endl;

}
void test_Matrix()
{
	cout<<"==================="<<""<<endl;
	cout<<"TEST CLASS: Matrix"<<""<<endl;
	cout<<"==================="<<""<<endl;
	int WIDTH=10;
	int HEIGHT=5;
	//
	Display* d=new Display();
	d->showTitle();
	//
	Matrix* m=new Matrix(HEIGHT,WIDTH,"X");
	d->show();
	//
	cout<<"==================="<<""<<endl;
}
void test_flow()
{
	// INIT:
	int WIDTH=10;
	int HEIGHT=10;
	//
	Display* d=new Display();
	d->showTitle();
	//
	Matrix* m=new Matrix(HEIGHT,WIDTH,"X");
	//PRINTVAR(d);
	d->m=m;
	d->show();

	Control c; 
	//c.mat=m;
	//c.display=d;
	//c.run();

	// LOOP:
	while(true)
	{
		char ch;
		cout<<"ch (q to break)=";
		ch=c.getch();
		cout<<ch<<""<<endl;
		if(ch=='q')
			break;
		if(ch=='o')// add new shape
		{
			cout<<"ADD NEW SHAPE!"<<""<<endl;
			Shape* s=new Shape(WIDTH,HEIGHT);
			//Shape* s=new Shape(1);
			s->init();
			s->update();
			m->addShape(s);
			m->update();

		}
		if(ch=='r') // will instead by timing-triggered
		{
			cout<<"REFRESH!"<<""<<endl;
			// REFRESH Matrix
			d->show();
			cout<<"TICK!"<<""<<endl;
			m->tick();
			cout<<"UPDATE!"<<""<<endl;
			m->update();
			// Display
			d->show();
			// call
		}
	}
}
void test_Point()
{
	vector<Point> vp;
	vp.push_back(Point(0,0));
	vp.push_back(Point(0,1));
	vp.push_back(Point(0,2));
	PRINT_VECTOR(vp);
	cout<<"------------------"<<""<<endl;
	for(auto p:vp)
	{
		PRINTVAR(p);
		p.x++;
		PRINTVAR(p);
	}
}
void test_deleteFromVector()
{
	vector<Point*> v;
	v.push_back(new Point(0,0));
	v.push_back(new Point(0,1));
	v.push_back(new Point(0,2));
	//PRINT_VECTOR_hor(v);
	cout<<"--------"<<""<<endl;
	for(auto p:v)
		cout<<""<<*p<<"\t@"<<p<<endl;
	for(Point* p:v)
	{
		if(p->x==0&& p->y==1)
			deleteFromVector(&v,p);
	}
	cout<<"--------"<<""<<endl;
	for(auto p:v)
		cout<<""<<*p<<"\t@"<<p<<endl;
	//PRINT_VECTOR_hor(v);
}

int main()
{
	cout<<"UNIT_TEST MODE"<<""<<endl;
	//test_Control();


	//test_Matrix();
	test_flow();
	//test_Point();
	//test_deleteFromVector();
	return 0;
}
#else
int main()
{
	int WIDTH=20;
	int HEIGHT=30;
	//
	Display* d=new Display();
	d->showTitle();
	//
	Matrix* m=new Matrix(HEIGHT,WIDTH,"X");
	d->show();
	//

	return 0;
}
#endif
