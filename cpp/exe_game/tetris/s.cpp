//--------------------------------------
// include lib files
//--------------------------------------
//#include <curses.h>
#include "global.h"
#include "Display.class.h"
#include "Control.class.h"
//#include "TetrisCalc.class.h"
#include "Matrix.class.h"

#include "unit_test.h"

using namespace std;
//--------------------------------------
// include local files
//--------------------------------------
//#include "include/f13_2.h"
//#include "lib.h"
//#include "include.top.h"
//#include "gnuplot_i.h"

//--------------------------------------


#ifdef UNIT_TEST
//int main()
//{
//	cout<<"UNIT_TEST MODE"<<""<<endl;
//	//test_Control();
//
//
//	//test_Matrix();
//	test_flow();
//	//test_time_engine();
//	//test_Point();
//	//test_deleteFromVector();
//	return 0;
//}
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
