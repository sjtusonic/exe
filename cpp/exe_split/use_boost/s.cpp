#define PRINTVAR(a) std::cout<<#a<<"\t=\t'"<<a<<"'\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";

#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<"VEC:\t"<<#a<<"='"<<*u<<"'"<<std::endl;}

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
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/split.hpp>


using namespace std;
using namespace boost;

int main ()
{

	std::string s="    var_name ( + ) ";
	PRINTVAR(s);
	s=trim_left_copy(s);
	s=trim_right_copy(s);
	PRINTVAR(s);
	typedef vector<string> split_vector_type;
	split_vector_type SplitVec;
	split(SplitVec,s,is_any_of("()"));
	// delete empty string
	for(auto it=SplitVec.begin();it!=SplitVec.end();)
	{
		if(*it=="")
			it=SplitVec.erase(it);
		else
			++it;
	}
	// 
	PRINT_VECTOR(SplitVec );
	PRINTVAR(SplitVec.size());

	for(string& s:SplitVec )
	{
		s=trim_left_copy(s);
		s=trim_right_copy(s);
	}
	PRINT_VECTOR(SplitVec );

	//auto v=split(s,"e");
	//
	//PRINT_VECTOR(v);
	return 0;
}
