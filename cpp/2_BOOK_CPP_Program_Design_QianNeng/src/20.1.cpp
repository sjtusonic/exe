
#include "include.top.h"
template <class T> 
T min(T& a,T& b) {
	return a>b?b:a;
}

char* min(char* a,char* b) { // override
	return (strcmp(a,b)?b:a);
}

void f20_1() {
	int c=min<int>(1,2);
	cout<<"min="<<c<<""<<endl;
	double r=min<double>(1.1,2.2);
	cout<<"min="<<r<<""<<endl;
	cout<<"min="<<min('3','5')<<""<<endl;
	cout<<"min="<<min("aoe","ziga")<<""<<endl;
}
