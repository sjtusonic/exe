
#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define PRINT_ARRAY(a,len)  for(int u=0;u<len;u++) {std::cout<<u<<":\t"<<*a+u<<std::endl;}
#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<std::endl;}
#define PRINT_VECTOR_hor(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;

#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int,map<int,map<int,string>>> m;
	m[0][0][0]="000";
	m[0][0][1]="001";
	m[0][0][2]="002";
	m[0][1][0]="010";
	m[0][1][1]="011";
	m[0][1][2]="012";
	m[1][2][0]="120";
	m[1][2][1]="121";
	std::cout<<"------------------------------"<<std::endl;
	std::cout<<"SHOW:"<<std::endl;
	for(auto l1:m)
	{
		//std::cout<<"el.first="<<el.first;
		//std::cout<<"el.first="<<el.first;
		//std::cout<<"\t"
		//PRINTVAR(el.second);
		for (auto l2:l1.second)
		{
			for (auto l3:l2.second)
			{
				PRINTVAR_hor(l1.first);
				PRINTVAR_hor(l2.first);
				PRINTVAR_hor(l3.first);
				std::cout<<":\t";
				PRINTVAR_hor(l3.second);
				std::cout<<std::endl;
			}
		}
	}
	std::cout<<"------------------------------"<<std::endl;
}

