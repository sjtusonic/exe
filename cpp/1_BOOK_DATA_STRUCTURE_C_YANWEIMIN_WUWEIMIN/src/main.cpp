#include "include.top.h"
using namespace std;

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
 	f_test_Stack() ;

	////////////////////////////////////////////////
	tblock=localtime(&timer);
	cout<<asctime(tblock)<<endl;
	cout<<"END"<<endl;
	return 0;
}
