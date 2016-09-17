#include "include.top.h"
void f13_2() {
	PRINT_DEBUG_INFO();
}
void showInfo() {
	cout<<"-------------"<<endl;
	//cout<<"FILE:\t"<<__FILE__<<endl;
	//cout<<"LINE:\t"<<__LINE__<<endl;
	//cout<<"DATE:\t"<<__DATE__<<endl;
	//cout<<"TIME:\t"<<__TIME__<<endl;
	//cout<<"STDC:\t"<<__STDC__<<endl;
	cout<<"DEBUG: " <<__FILE__<<":" <<__LINE__<<" compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<endl;
	cout<<"-------------"<<endl;
}
