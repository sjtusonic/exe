#include "include.top.h"
using namespace std; // you'd better not use using command in header files.
void exe_2_3_1() {
	PRINT_DEBUG_INFO();

	cout<<"------------------------"<<endl;
	int ival=1.01;
	//int&rval1=1.01;
	int& rval2=ival;
	//int&rval3;
	cout<<"------------------------"<<endl;
	int i=7,&r1=i;
	double d=0.1,&r2=d;

	r2=3.14;
	PRINTVAR(r2);
	r2=r1;
	PRINTVAR(r2);
	r2=4.15;
	i=r2;
	PRINTVAR(i);
	r1=d;
	PRINTVAR(r1);
}
