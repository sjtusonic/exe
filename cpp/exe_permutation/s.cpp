#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;

#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define PRINT_ARRAY(a,len)  for(int u=0;u<len;u++) {std::cout<<u<<":\t"<<*a+u<<std::endl;}
#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<std::endl;}
#define PRINT_VECTOR_hor(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;

#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)
#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )


vector<vector<int>> genPermutations(int n);
void show(vector<vector<int>> p,int length=0);
vector<vector<int>> breakIntoMatrix(vector<int> v,int length);
bool isLegal(vector<vector<int>> v);

// Catalan number
#define N 6
#define LEN 2
int main()
{
	//vector<int> a;
	//for(int i=0;i<12;i++)
	//	a.push_back(i);
	//PRINT_VECTOR(a);
	vector<vector<int>> p=genPermutations(N);
	vector<vector<int>> result;

	cout<<"SHOW------------------\t\n";
	show(p);
	PRINTVAR(p.size());


	for(auto v:p)
		if(isLegal(breakIntoMatrix(v,N/LEN)))
		{
			PRINT_VECTOR_hor(v);
			result.push_back(v);
		}
	cout<<"RESULT------------------\t\n";
	show(result,N/LEN);
	PRINTVAR(result.size());
	cout<<"END------------------\t\n";
	//vector<int> t;
	//t.push_back(0);
	//t.push_back(1);
	//t.push_back(2);
	//t.push_back(3);
	//auto u=breakIntoMatrix(t,2);
	////for(auto i:u)
	////	for(auto j:i)
	////		PRINTVAR(j);
	//for (int i=0;i<u.size();i++)
	//	for (int j=0;j<u[0].size();j++)
	//		PRINTVAR(u[i][j]);
	//PRINTVAR(isLegal(u));
	return 1;
}

vector<vector<int>> genPermutations(int n)
{
	vector<vector<int>> r;
	if(n==1)
	{
		vector<int> p;
		p.push_back(0);
		r.push_back(p);
		return r;
	} 
	else
	{
		int NEW_ADDED_NUM=n-1;
		auto permutations_n_1=genPermutations(n-1);
		for(auto one_p_n_1:permutations_n_1)
		{
			int marker=n-1;
			while(marker!=-1)
			{
				vector<int> p;
				int cntr=0;
				for(auto num:one_p_n_1)
				{
					//PRINT_DEBUG_INFO();
					if(cntr==marker)
						p.push_back(NEW_ADDED_NUM);
					p.push_back(num);
					cntr++;
				}
				if(marker==one_p_n_1.size())
					p.push_back(NEW_ADDED_NUM);
				r.push_back(p);
				marker--;
			}
		}
		return r;
	}
}

void show(vector<vector<int>> p,int length)
{
	//PRINT_DEBUG_INFO();
	//PRINTVAR(p.size());
	for(auto i:p)
	{
		//PRINTVAR(i.size());
		if(length!=0)
			cout<<"------"<<endl;
		if(length==0)
		{
			for(auto j:i)
			{
				cout<<j;
				cout<<"\t";
			}
			cout<<endl;
		}
		else
		{
			int cnt=0;
			for(auto j:i)
			{
				cout<<j;
				cout<<"\t";
				if((cnt+1)%length==0)
					cout<<endl;

				cnt++;
			}
			cout<<endl;
		}
	}
}

vector<vector<int>> breakIntoMatrix(vector<int> v,int length)
{
	//PRINTVAR(v.size());
	//PRINTVAR(length);
	assert(v.size()%length==0);
	vector<vector<int>> r;

	int cntr=0;
	vector<int> t;
	for(auto i:v)
	{
		//PRINTVAR(i);
		//PRINTVAR(cntr);
		if((cntr+1)%length!=0)
		{
			t.push_back(i);
			//PRINT_VECTOR_hor(t);
		}
		else
		{
			t.push_back(i);
			//PRINT_VECTOR_hor(t);
			r.push_back(t);
			t.clear();
		}
		cntr++;
		//PRINT_DEBUG_INFO();
	}
	//PRINT_DEBUG_INFO();
	return r;
}

bool isLegal(vector<vector<int>> v)
{
	for (int i=0;i<v.size();i++)
	{
		for (int j=0;j<v[0].size();j++)
		{
			//PRINTVAR(v[i][j]);
			if(i!=0 && v[i][j]<v[i-1][j])
				return false;
			if(j!=0 && v[i][j]<v[i][j-1])
				return false;
		}
	}
	return true;
}
