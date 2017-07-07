#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;

#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<"VEC:\t"<<#a<<"="<<*u<<std::endl;}

#define PRINT_VECTOR_hor(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;
//#define PRINT_VECTOR_hor(a) 
#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)

#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )

#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <stack>
#include <algorithm>
#include <assert.h>

using namespace std;

vector<string>* genSeries(int n);
vector<vector<int>>* genAllValidSum(int n);

int main ()
{
	stack<int> s ;
	//TreeNode* expected = new TreeNode(17, new TreeNode(0, new TreeNode(3), new TreeNode(15)), new TreeNode(-4));
	//Assert::That(*Solution::arrayToTree(arr), Equals(*expected));

	//*Solution::arrayToTree(arr);
	s.push(1);
	s.push(2);
	s.push(3);
	PRINTVAR(s.top());

	genAllValidSum(2);
	//genSeries(3);
	return 0;
}
#if 0
vector<string>* genSeries(int n)
{
	stack<int> left,bottom;
	vector<int> right;
	// init in left side:
	for(int i=1;i<=n;i++)
		left.push(i);
	auto left.bk=left;

	int go_r_cnt=0;
	int go_b_cnt=0;
	int go_r_cnt2=0;
}
#endif

# if 0

1

1 1
2

1 1 1
1 2
3

#endif
void show_v_v(vector<vector<int>> vv)
{
	for(auto v:vv)
	{
		for(auto i:v)
			cout<<""<<i<<"\t";
		cout<<""<<""<<endl;
	}
}
vector<vector<int>>* genAllValidSum(int n)
{
	if(n==1)
	{
		auto r=new vector<vector<int>>();
		vector<int> v;
		v.push_back(1);
		r->push_back(v);
		return r;
	}
	else 
	{
		auto r=genAllValidSum(n-1);
		auto r_new=new vector<vector<int>>();
		vector<vector<int>>& old=*r;	
		vector<vector<int>>  old_scratch=old;	
		vector<vector<int>>& newvv=*r_new ;	

		PRINT_DEBUG_INFO_PREFIX("newvv:");
		show_v_v(newvv);
		for(auto v:old_scratch ) // vector<int>
		{
			for(auto i:v)
			{
			}
		}
		PRINT_DEBUG_INFO_PREFIX("newvv:");
		show_v_v(newvv);
	}
}
