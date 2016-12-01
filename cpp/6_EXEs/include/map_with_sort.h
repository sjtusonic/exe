#include<map>   
using namespace std;   
using std::map;   
int map_with_sort_wrp() ;

//template <class T> struct is_less : binary_function <T,T,bool> {   
//	bool operator() (const T& x, const T& y) const   
//	{return x>y;}   
//};

template <class T> struct is_less : std::binary_function <T,T,bool> {   
	bool operator() (const T& x, const T& y) const   
	{return x>y;}   
};

//void foo(map<string, int, is_less<string> > m);
void foo(map<string, int, is_less<string> > );
