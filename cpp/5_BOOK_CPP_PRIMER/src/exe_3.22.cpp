
#include <vector>
#include "include.top.h"
using namespace std;
using std::string;
using std::vector;

void f_3_22() {
	cout<<"==============="<<endl;
	cout<<"exe_3_22:"<<""<<endl;
	cout<<"==============="<<endl;
	string s("this is a string!");
	PRINTVAR(s);
	for (auto &c:s)
	{
		if(isspace(c))
		{
			break;
		}
		c=toupper(c);
	}
	PRINTVAR(s);
	cout<<"==============="<<endl;
	cout<<"exe_3_23:"<<""<<endl;
	cout<<"==============="<<endl;
	vector<int> vi(10,0);
	int cnt=0;
	for (auto& i:vi)
	{
		i=cnt;
		cnt++;
	}
	print_vector(vi);
	for (auto& i:vi)
	{
		i*=2;
	}
	print_vector(vi);
	cout<<"==============="<<endl;
	cout<<"exe_3_25:"<<""<<endl;
	cout<<"==============="<<endl;
	vector<int> score{11,22,33,44,51,4,23,99,100,66,77,88,67,23,1,0};
	vector<int> stat(11,0);
	print_vector(score);
	auto it_sum=stat.begin();
	for(auto it=score.begin();it!=score.end();it++)
	{
		int step=*it;
		step=step/10;
		PRINTVAR(step);
		auto target=it_sum+step;
		*target+=1;
	}
	print_vector(stat);
}
