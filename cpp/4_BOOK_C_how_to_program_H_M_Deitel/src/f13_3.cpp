#include "include.top.h"

#define GET_VALUE(x) (x)

#define TRUE a

#ifdef TRUE
	#undef TRUE
	#define TRUE 1
#else
	#define TRUE 1
#endif

#define TRUE 0
#if TRUE
	#define FALSE 0
#else 
	#define FALSE 1
#endif

#define SQUARE_VOLUME(a) (a*a*a)

void f13_3() {
	cout<<YES<<endl;	
	PRINT_DEBUG_INFO();
	cout<<"MACRO TRUE="<<GET_VALUE(TRUE)<<endl;
	cout<<"MACRO FALSE="<<GET_VALUE(FALSE)<<endl;
	int a=3;

	for (a=1;a<=10000;a++) {
		cout<<"SQUARE_VOLUME("<<a<<")="<<SQUARE_VOLUME(a)<<endl;
		if(SQUARE_VOLUME(a)<0) {break;}
	}
#line 3000
	PRINT_DEBUG_INFO();
	//cout<<"DEBUG: " <<__FILE__<<":" <<__LINE__<<" compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<endl;
}
