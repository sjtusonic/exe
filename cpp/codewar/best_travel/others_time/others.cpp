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


#define verbose_PRINT_VECTOR_hor(a)  std::cout<<#a<<":\t";for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;
#define verbose_PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define verbose_PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define verbose_PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )

//#if(SIMPLE_LOG)
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
#include <vector>
#include <string>
#include <algorithm>

class BestTravel
{
	public:
		static int chooseBestSum(int t, int k, std::vector<int>& ls);
};

int BestTravel::chooseBestSum(int t, int k, std::vector<int>& ls)
{
	PRINT_DEBUG_INFO();
	clock_t start, end;
	start = clock();
	//
	unsigned int n = ls.size();
	if ((unsigned int)k > n) return -1;
	int max = -1, sum;
	std::string bitmask(k, 1);
	for(auto c:bitmask) { std::string s=c?"1":"0"; std::cout<<s<<"\t"; } PRINT_ENDL();
	bitmask.resize(n, 0);
	for(auto c:bitmask) { std::string s=c?"1":"0"; std::cout<<s<<"\t"; } PRINT_ENDL();
	do {
		//for(int i=0;i<bitmask.size();i++)
		//PRINT_COUT(bitmask[i]);
		for(auto c:bitmask) { std::string s=c?"1":"0"; std::cout<<s<<"\t"; } PRINT_ENDL();
		//PRINT_ENDL();
		sum = 0;
		for (unsigned int i = 0; i < n; ++i)
			if (bitmask[i]) sum += ls[i];
		if ((sum >= max) && (sum <= t)) max = sum;
	} while (std::prev_permutation(bitmask.begin(), bitmask.end()));



	//
	end = clock();

	std::cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";
	return max;
}
int main ()
{

	//std::vector<int> arr = {17, 0, -4, 3, 15};
	//std::vector<int> arr = {3,4,8,9,10};

#if 1
	std::vector<int> arr = {91,74,73,73,73,73,73};
	std::map<std::vector<int>,int> cache_keep_max;
	auto r=BestTravel::chooseBestSum(300,3,arr);
#endif

#if 0
	std::vector<int> arr = {1,2,91,74,73,82,71};
	std::map<std::vector<int>,int> cache_keep_max;
	auto r=BestTravel::chooseBestSum(500,5,arr);
#endif
#if 0
	std::vector<int> arr = {100, 76, 56, 44, 89, 73, 68, 56, 64, 123, 2333, 144, 50, 132, 123, 34, 89 };
	//std::vector<int> arr = {100, 44, 89, 73, 68, 56, 64, 123, 34, 89 };
	auto r=BestTravel::chooseBestSum(500,5,arr);
#endif

#if 0
	std::vector<int> arr = { 91,74,73,85,73,81,87};
	auto r=BestTravel::chooseBestSum(331,5,arr);
#endif
#if 0
	std::vector<int> arr = { 91,74,73,85,73,81,87 };
	auto r=BestTravel::chooseBestSum(331,4,arr);
#endif
	//PRINTVAR(BestTravel::findLargestOne(std::vector<int>(),100,arr,cache_keep_max));

	//PRINT_DEBUG_INFO_PREFIX("================================================");
	//std::vector<int> a={1,2,3};
	//std::vector<int> b={1,3,2};
	//sort(b.begin(),b.end());
	//PRINTVAR((a==b));
	//PRINT_DEBUG_INFO_PREFIX("================================================");

	PRINTVAR(r);

	//
	//

	return 0;
}
