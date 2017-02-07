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
	int HEIGHT=5;
	//
	Display* d=new Display();
	d->showTitle();
	//
	Matrix* m=new Matrix(HEIGHT,WIDTH,"X");
	PRINTVAR(d);
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
			Shape* s=new Shape();
			m->addShape(s);

		}
		if(ch=='r') // will instead by timing-triggered
		{
			cout<<"REFRESH!"<<""<<endl;
			// REFRESH Matrix
			m->update();
			// Display
			d->show();
			// call
		}
	}
}

int main()
{
	cout<<"UNIT_TEST MODE"<<""<<endl;
	//test_Control();


	//test_Matrix();
	test_flow();
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
