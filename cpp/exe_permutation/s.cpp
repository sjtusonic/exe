#include <vector>
#include <iostream>
using namespace std;

#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define PRINT_ARRAY(a,len)  for(int u=0;u<len;u++) {std::cout<<u<<":\t"<<*a+u<<std::endl;}
#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<std::endl;}
#define PRINT_VECTOR_hor(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl; 

#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)
#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )vector<vector<int>> genPermutations(int n);void show(vector<vector<int>> p);

vector<vector<int> > genPermutations(int n);
void show(vector<vector<int> > p);
int main()
{
	//vector<int> a;
	//for(int i=0;i<12;i++)		
	//	a.push_back(i);
	//PRINT_VECTOR(a);

	vector<vector<int> > p=genPermutations(2);
	show(p);
	return 1;
}

vector<vector<int> > genPermutations(int n)
{
	vector<vector<int> > r;
	if(n==1)	
	{
		PRINT_DEBUG_INFO();
		vector<int> p;
		p.push_back(0);
		r.push_back(p);
		return r;
	} 	else	
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
					p.push_back(num);
					if(cntr==marker)						p.push_back(NEW_ADDED_NUM);
					cntr++;
				}				r.push_back(p);
			}			marker--;
		}		return r;
	}
}
void show(vector<vector<int> > p)
{
	PRINT_DEBUG_INFO();
	PRINTVAR(p.size());
	for(auto i:p)	
	{
		PRINTVAR(i.size());
		for(auto j:i)		
		{
			cout<<j;
			cout<<"\t";
		}		cout<<endl;
	}
}
