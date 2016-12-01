#include "include.top.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void exe_operator ()
{
	cout<<"----------------------"<<endl;
	std::vector<Employee_class> v = {
		Employee_class(108, "Z"),
		Employee_class(32, "A"),
		Employee_class(18, "F"),
		Employee_class(108, "F"),
		Employee_class(33,  "F"),
		Employee_class(208, "F"),
		Employee_class(108, "A"),
		Employee_class(108, "C"),
		Employee_class(108, "B"),
	};

	cout<<"-----------------------------"<<endl;
	for (const Employee_class &e : v) {
		std::cout << e.getAge() << ",\t " << e.getName() << "\n";
	}
	cout<<"-----------------------------"<<endl;
	v[0]+=1;
	v[1]+=v[2];

	cout<<"v[3]<v[4]="<<(v[3]<v[4])<<endl;
	cout<<"v[3]<=v[4]="<<(v[3]<=v[4])<<endl;
	cout<<"v[3]>v[4]="<<(v[3]>v[4])<<endl;
	cout<<"v[3]>=v[4]="<<(v[3]>=v[4])<<endl;
	cout<<"-----------------------------"<<endl;

	cout<<"v[6]< v[7]="<<(v[6]< v[7])<<endl;
	cout<<"v[6]<=v[7]="<<(v[6]<=v[7])<<endl;
	cout<<"v[6]> v[7]="<<(v[6]> v[7])<<endl;
	cout<<"v[6]>=v[7]="<<(v[6]>=v[7])<<endl;
	cout<<"-----------------------------"<<endl;
	for (const Employee_class &e : v) {
		std::cout << e.getAge() << ",\t " << e.getName() << "\n";
	}
	cout<<"-----------------------------"<<endl;
	cout<<"Operator for pointer"<<endl;
	Employee_class* p1;
	Employee_class* p2;

	Employee_class c1(1,"a"),c2(2,"b");
	cout<<"c1<c2="<<(c1<c2)<<endl;
	
	p1=&c1;
	p2=&c2;
	cout<<"*p1<*p2="<<(*p1<*p2)<<endl;

	cout<<"-----------------------------"<<endl;
}
