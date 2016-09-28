#include "include.top.h"


void f13_4() {
	PRINT_DEBUG_INFO();

	for (int a=1;a<=10;a++) {
		cout<<"SPHERE_VOLUME("<<a<<")\t="<<SPHERE_VOLUME(a)
			<<"\t|\t"<<dec2bin(SPHERE_VOLUME(a))<<endl;
		if(SPHERE_VOLUME(a)<0) {break;}
	}

	cout<<dec2bin(1)<<endl;
	cout<<dec2bin(2)<<endl;
	cout<<dec2bin(4)<<endl;
	cout<<dec2bin(8)<<endl;
	cout<<dec2bin(7)<<endl;
	cout<<dec2bin(9)<<endl;
}

