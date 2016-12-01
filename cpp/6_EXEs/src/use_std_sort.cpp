#include "include.top.h"
#include <algorithm>
#include <functional>
#include <array>
#include <iostream>

int use_std_sort()
{
	cout<<"----------------------------------------"<<endl;
	std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
	cout<<"BEFORE:"<<endl;
	PRINT_VECTOR_hor(s);
	cout<<"----------------------------------------"<<endl;

	// sort using the default operator<
	cout<<"default sort:"<<endl;
	std::sort(s.begin(), s.end());
	PRINT_VECTOR_hor(s);
	cout<<"----------------------------------------"<<endl;

	cout<<"use std::greater:"<<endl;
	// sort using a standard library compare function object
	std::sort(s.begin(), s.end(), std::greater<int>());
	PRINT_VECTOR_hor(s);
	cout<<"----------------------------------------"<<endl;
	// sort using a custom function object
	cout<<"use customLess:"<<endl;
	struct {
		bool operator()(int a, int b)
		{
			return a < b;
		}
	} customLess;
	std::sort(s.begin(), s.end(), customLess);
	PRINT_VECTOR_hor(s);
	cout<<"----------------------------------------"<<endl;
	cout<<"use lambda:"<<endl;

	// sort using a lambda expression
	std::sort(s.begin(), s.end(), 
		[](int a, int b) {
			return b < a;
		});
	PRINT_VECTOR_hor(s);
	cout<<"----------------------------------------"<<endl;
}
