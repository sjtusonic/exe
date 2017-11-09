#define SIMPLE_LOG 0
#define LNX 1

#if (!SIMPLE_LOG)
#define DLOG(x) cout<<#x<<"="<<x<<" @"<<__LINE__<<endl;
#else
#define DLOG(x)
#endif

#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";

#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<"VEC:\t"<<#a<<"="<<*u<<std::endl;}
#define PRINT_VECTOR_hor(a)  std::cout<<#a<<":\t";for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;

#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)

#if (!SIMPLE_LOG)
#define DENTER \
	LVCALL++; PRLVCALL; ::std::cout<<"-->"<<__FUNCTION__<<::std::endl; 
#define DRETURN \
	PRLVCALL; ::std::cout<<"<--"<<__FUNCTION__<<::std::endl; LVCALL--;
#endif

#define DEBUG_MARK PRINT_DEBUG_INFO()
#define PRINT_COUT(p) \
	(::std::cout<<p<<"\t"   )
#define PRINT_ENDL() \
	(::std::cout<<::std::endl)
#define DPRINT(x) \
	(::std::cout<<x<<::std::endl   )
#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )



#define verbose_PRINT_VECTOR_hor(a)  std::cout<<#a<<":\t";for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;
#define verbose_PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define verbose_PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define verbose_PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )

#if SIMPLE_LOG
#define PRINTVAR(a)
#define PRINTVAR_hor(a)
#define PRINT_VECTOR(a)  
#define PRINT_VECTOR_hor(a) 
#define PRINT_DEBUG_INFO()

#define DEBUG_MARK 
#define PRINT_DEBUG_INFO_PREFIX(p)
#define DPRINT(x)
#define PRINT_COUT(p) 

#define DENTER 
#define DRETURN 
#endif

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
#include <regex>
#include <map>
#include <assert.h>
using namespace std;

int main()
{
	vector<pair<int,int>>items;
	//items[0]=0;
	//items[1]=1;
	//items[2]=2;
	items.push_back(make_pair(11,1));
	items.push_back(make_pair(11,3));
	items.push_back(make_pair(12,3));
	items.push_back(make_pair(13,2));
	items.push_back(make_pair(12,2));
	auto cmp = [](std::pair<int,int> const & a, std::pair<int,int> const & b) 
	{ 
		return a.second != b.second?  a.second < b.second : a.first < b.first;
	};
	std::sort(items.begin(), items.end(), cmp);

	for(auto p:items)
	{
		DPRINT(""<<p.first<<", "<<p.second);
	}
}
