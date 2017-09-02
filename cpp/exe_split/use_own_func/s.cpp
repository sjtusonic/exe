#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";

#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<"VEC:\t"<<#a<<"="<<*u<<std::endl;}

#define PRINT_VECTOR_hor(a)  std::cout<<#a<<":\t";for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;
#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)
#define PRINT_COUT(p) \
	(::std::cout<<p<<"\t"   )
#define PRINT_ENDL() \
	(::std::cout<<::std::endl)

#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )

//#define SIMPLE_LOG

#ifdef SIMPLE_LOG
#define PRINTVAR(a)
#define PRINTVAR_hor(a)
#define PRINT_VECTOR(a)  
#define PRINT_VECTOR_hor(a) 
#define PRINT_DEBUG_INFO()
#define PRINT_DEBUG_INFO_PREFIX(p)
#endif

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>
#include <assert.h>


std::vector<std::string> split(std::string str,std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	std::string str_bk=str,str_no_repeat_blank;
	//PRINTVAR(str);
	for (auto it=str.begin();it!=str.end();it++)
	{
		if(it!=str.begin() && *it==' ' && *(it-1)==' ')
			;
		else
			str_no_repeat_blank+=*it;
	}
	//PRINTVAR(str_no_repeat_blank);
	str=str_no_repeat_blank;
	str+=pattern;
	int size=str.size();

	for(int i=0; i<size; i++)
	{
		pos=str.find(pattern,i);
		if(pos<size)
		{
			std::string s=str.substr(i,pos-i);
			result.push_back(s);
			i=pos+pattern.size()-1;
		}
	}
	return result;
}

int main ()
{

	std::string s="var_name ( + ) ";
	auto v=split(s,"e");

	PRINT_VECTOR(v);
	return 0;
}
