#include "include.top.h"

#define MINNUM2(a,b) (a<b?a:b)
#define MINNUM3(a,b,c) (MINNUM2(a,MINNUM2(b,c)))

#define PRINT(a) (a)


//#ifdef DEBUG
//	#define PIRNT_DEBUG(cond,msg,) if (cond) cout<<""<<<<""<<endl;
//#else
//	#define PIRNT_DEBUG(cond,msg,)
//#endif

#define SUM_ARRAY(a,len,return_value)  int sum=0;for(int u=0;u<len;u++) {sum+=*a+u;};return_value=sum;

//#define SHOW_VAR(a,b) cout<<a<<"="<<b<<endl;
//#define PRINTVAR(a) SHOW_VAR(#a,a)


void f13_6() {
	cout<<"==============="<<endl;
	cout<<"EXE 13_6:"<<endl;
	int x,y,z;
	cout<<"please enter a num x:"<<endl;
	cin>>x;
	cout<<"please enter a num y:"<<endl;
	cin>>y;
	cout<<"please enter a num z:"<<endl;
	cin>>z;

	cout<<"MINNUM2(x,y)="<<MINNUM2(x,y)<<endl;
	cout<<"==============="<<endl;
	cout<<"EXE 13_7:"<<endl;
	cout<<"MINNUM3(x,y,z)="<<MINNUM3(x,y,z)<<endl;
	cout<<"==============="<<endl;
	cout<<"EXE 13_8:"<<endl;
	cout<<"PRINT(x)="<<PRINT("this is a string")<<endl;
	cout<<"PRINT(x)="<<PRINT(1)<<endl;
	cout<<"PRINT(x)="<<PRINT(PI)<<endl;
	cout<<"Info: so, the macro PRINT() can be used for all kinds of variables"<<endl;
	cout<<"==============="<<endl;
	cout<<"EXE 13_9:"<<endl;
	int x1[3]={1,2,3};
	cout<<"debug:"<<x1[0]<<endl;
	cout<<"PRINT_ARRAY:"<<endl;
	PRINT_ARRAY(x1,3);
	cout<<"Info: you can use 'g++ -E' instead of 'g++' to debug macro"<<endl;
	cout<<"==============="<<endl;
	cout<<"EXE 13_10:"<<endl;
	cout<<"SUM_ARRAY:"<<endl;
	int r=0;
	SUM_ARRAY(x1,3,r);
	cout<<r<<endl;
	cout<<"==============="<<endl;
	cout<<"EXE 13_more # and ##:"<<endl;
#define HELLO0(x) printf ("Hello,x\n")
#define HELLO(x)  printf ("Hello,"#x"\n")
#define CALC0(x)  (x+2)
#define CALC(x)   (#x+2)
	HELLO0(John);
	HELLO(John);
	CALC0(3);
	CALC(3);
#define AND(x,y) printf (#x""#y" \n")
	AND(Albert,Bob);
	int intVar=3555;
#define AND2(x,y) cout<<x##y<<endl
	AND2(intV,ar);

	cout<<"==============="<<endl;
	cout<<"SHOW_VAR:"<<endl;
	//SHOW_VAR("r",r);
	int a1=1;
	int a2=2;
	double d1=2.13;
	string s1="this is a string";

	PRINTVAR(r);
	PRINTVAR(a1);
	PRINTVAR(a2);
	PRINTVAR(d1);
	PRINTVAR(s1);
	PRINTVAR(x1);

}
