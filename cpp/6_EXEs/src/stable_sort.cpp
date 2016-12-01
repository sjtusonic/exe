#include "include.top.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool operator<(const Employee &lhs, const Employee &rhs) {
	return lhs.age < rhs.age;
}

int stable_sort()
{
	std::vector<Employee> v = { 
		Employee(108, "Zaphod"),
		Employee(32, "Arthur"),
		Employee(18, "Ford"),
		Employee(108, "Ford"),
		Employee(33,  "Ford"),
		Employee(208, "Ford"),
		Employee(108, "Alice"),
		Employee(108, "Chandler"),
		Employee(108, "Bob"),
	};  

cout<<"-----------------------------"<<endl;
	for (const Employee &e : v) {
		std::cout << e.age << ",\t " << e.name << '\n';
	}   
cout<<"-----------------------------"<<endl;
// sort age
	std::stable_sort(v.begin(), v.end());

cout<<"-----------------------------"<<endl;
	for (const Employee &e : v) {
		std::cout << e.age << ",\t " << e.name << '\n';
	}   
cout<<"-----------------------------"<<endl;
// sort name
	std::stable_sort(v.begin(), v.end(),
		[] (Employee a,Employee b)
		{
			return a.name<b.name;
		}
	);

cout<<"-----------------------------"<<endl;
	for (const Employee &e : v) {
		std::cout << e.age << ",\t " << e.name << '\n';
	}   
cout<<"-----------------------------"<<endl;
}
