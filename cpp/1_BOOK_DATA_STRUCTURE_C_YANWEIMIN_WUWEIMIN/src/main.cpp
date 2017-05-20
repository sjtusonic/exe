#include "include.top.h"
using namespace std;

//void printvar (int& var) ;
int main()  // FUNC
{
	float f=3.121;
	printf("========= %f \n",f);
	printf("========= %d \n",f);
	printf("========= %x \n",f);
	printf("========= %s \n",f);

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

	PRINTVAR(a);
	PRINTVAR(b);
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
