#include "include.top.h"
using namespace std;

//void printvar (int& var) ;
int main()  // FUNC
{
	time_t timer;
	struct tm *tblock;
	timer=time(NULL);
	tblock=localtime(&timer);
	cout<<asctime(tblock)<<endl;
	////////////////////////////////////////////////
	//string s="test";
	//cout<<"this is "<<s<<endl;
	//return 0;
	////////////////////////////////////////////////
	
	//f_test_linear_list();
	
 	//f_test_Stack() ;
 	f_test_LinkList() ;

	int a = 1010;
	string b="test";
	//printf("%s  = %d\n", VNAME(a), a);
	//
	cout<<VNAME(a)<<" = "<<a<<endl;
	cout<<VNAME(b)<<" = "<<b<<endl;
	//printvar (a);

	////////////////////////////////////////////////
	tblock=localtime(&timer);
	cout<<asctime(tblock)<<endl;
	cout<<"END"<<endl;
	return 0;
}

//void printvar (int& var) {
	////int v=*var;
	//cout<<VNAME(var)<<" = "<<var<<endl;
//}
