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
#include <regex>
#include <assert.h>
using namespace std;

class Kata {
	public:
		static bool validate(long long int n) {
			vector<int> v;
			// split
			for(auto c:to_string(n))
			{
				PRINTVAR(c);
				v.push_back(c-48);
			}
			PRINTVAR(v.size());
			PRINT_VECTOR_hor(v);

			// s1 double
			int start=0;
			if(v.size()%2==0)
			{
				start=0;
			}
			else
			{
				start=1;
			}
			int cntr=0;
			for(int & i:v)
			{
				if((cntr-start)%2==0)
				{
					i=i*2;
					while(i>9)
						i-=9;
				}
				cntr++;
			}
			PRINT_VECTOR_hor(v);
			// s2 9-
			// s3 sum
			long long sum=0;
			for(int i:v)
			{
				sum+=i;
			}
			PRINTVAR(sum);

			// s4 div by 10

			if(sum%10==0)
				return true;
			//else
			string r="FALSE";
			PRINTVAR(r);
			return false;
		}
};

int main ()
{
	Kata::validate(891);
	Kata::validate(2121);

	return 0;
}
