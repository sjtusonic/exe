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



#define verbose_PRINT_VECTOR_hor(a)  std::cout<<#a<<":\t";for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;
#define verbose_PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define verbose_PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define verbose_PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )

//#define SIMPLE_LOG 
#ifdef SIMPLE_LOG
#define PRINTVAR(a)
#define PRINTVAR_hor(a)
#define PRINT_VECTOR(a)  
#define PRINT_VECTOR_hor(a) 
#define PRINT_DEBUG_INFO()
#define PRINT_DEBUG_INFO_PREFIX(p)
#define PRINT_COUT(p) 
#endif

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <deque>
#include <map>
#include <assert.h>
#include <math.h>
#include <iomanip>
#include <map>
#include <fstream>

using namespace std;

static map<int ,string > cache_series_lv1;
static map<int ,string > cache_series_lv2;

template <typename T>
std::string to_string(T value)
{
		std::ostringstream os ;
			os << value ;
				return os.str() ;
}
string genSeriesLv1 (int n) 
{
	string r="";
	if(cache_series_lv1.count(n))
	{
		PRINTVAR_hor(n);
		PRINT_DEBUG_INFO_PREFIX("USE CACHE genSeriesLv1");
		r=cache_series_lv1[n];
	}
	else if(n==1)
		r="1";
	else
		r=genSeriesLv1(n-1)+to_string(n);
	PRINTVAR(r);

	if(!cache_series_lv1.count(n))
		cache_series_lv1[n]=r;
	return r;
}

string genSeriesLv2 (int n) 
{
	string r="";
	if(cache_series_lv2.count(n))
	{
		PRINTVAR_hor(n);
		PRINT_DEBUG_INFO_PREFIX("USE CACHE genSeriesLv2");
		r=cache_series_lv2[n];
	}
	else if(n==1)
		r=genSeriesLv1(1);
	else
		r=genSeriesLv2(n-1)+genSeriesLv1(n);
	PRINTVAR(r);

	if(!cache_series_lv2.count(n))
		cache_series_lv2[n]=r;
	return r;
}

int main () 
{
	//----------------------------------------------------------
	//cout<<"-----------------------------------------------"<<endl;
	//string filename="input.txt";
	//std::ifstream infile(filename);
	//if (!infile)
	//	std::cerr << "Couldn't open " << filename << " for reading\n";
	//----------------------------------------------------------

	//for(int i=3;i<1000;i++)
	//{
	//	string s=genSeriesLv2(i);
	//	cout<<i
	//	<<"\t:\t"<<s.size()
	//	<<"\t:\t"<<(sqrt(s.size())-i)
	//	<<endl;
	//	if (s.size()>1000000000)
	//		break;
	//}
	int t;
	int cntr=0;
	while(cin >> t)
	{
		PRINTVAR(t);
		if(cntr!=0)
		{
			int i=sqrt((float)t)+5;
			PRINTVAR(i);
			string s=genSeriesLv2(i);
			PRINTVAR(s);
			assert(s.size()>t);
			cout<<s[t-1];
		}
		PRINTVAR(cache_series_lv1.size());
		PRINTVAR(cache_series_lv2.size());
		cntr++;
	}
	cout<<"-----------------------------------------------"<<endl;
	return 0;
}
