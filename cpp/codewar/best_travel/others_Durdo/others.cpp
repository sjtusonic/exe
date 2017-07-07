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

/*  
 *  Stop giving me classes with only
 *  one static method! Geez....
 */
namespace BestTravel
{

	static int CALL_LEVEL=0;
	void getBestValue(std::vector<int> &dist, int max, int depth,
			int curValue, int lastIdx, int &sum)
	{
		CALL_LEVEL++;
		PRINT_COUT(CALL_LEVEL);
		for(int i=CALL_LEVEL;i>0;i--)
			PRINT_COUT("\t");
		PRINT_COUT("-->");
		PRINTVAR_hor(max);
		PRINTVAR_hor(depth);
		PRINTVAR_hor(curValue);
		PRINTVAR_hor(lastIdx);
		PRINTVAR_hor(sum);
		PRINT_ENDL();
		for(auto i=0;i<dist.size();i++)
		{
			if(i!=lastIdx)
				PRINT_COUT(dist[i]);
			else
				std::cout<<dist[i]<<"*\t";
		}
		PRINT_ENDL();
		// start in the begining
		int i = 0;
		// generic name, waiting for the code review
		int value;

		// let's go!
		for (std::vector<int>::iterator it = dist.begin();
				it < dist.end(); it++, i++)
		{
			// there is no looking back now
			if (i <= lastIdx)
				continue;

			// best result achieved, get out of here!
			if (sum == max && sum != -1)
				break;

			// maybe I should store this
			value = curValue + (*it);
			PRINTVAR_hor(i);
			PRINTVAR_hor((*it));
			PRINTVAR_hor(value);
			PRINT_ENDL();

			// nah, too big
			if (value > max)
				continue;

			// should I go deeper?
			if (depth > 1)
				getBestValue(dist, max, depth - 1, value, i, sum);

			// I hope this is the one!
			if (depth == 1 && value > sum)
				sum = value;
		}
		PRINT_COUT(CALL_LEVEL);
		for(int i=CALL_LEVEL;i>0;i--)
			PRINT_COUT("\t");
		PRINT_COUT("<--");
		PRINTVAR_hor(sum);
		PRINT_ENDL();
		//PRINTVAR(sum);
		CALL_LEVEL--;
	}

	int chooseBestSum(int t, int k, std::vector<int>& ls)
	{
		CALL_LEVEL=0;
		// final result
		int sum = -1;
		// start BIG!
		PRINT_VECTOR_hor(ls);
		//std::sort(ls.rbegin(), ls.rend());
		PRINT_VECTOR_hor(ls);

		// did i say recursion?
		getBestValue(ls, t, k, 0, -1, sum);
		//void getBestValue(std::vector<int> &dist, 
		//                   int max,
		//                      int depth,
		//                         int curValue,
		//                            int lastIdx,
		//                                int &sum)

		//gg
		return sum;
	}

};

int main ()
{

	//std::vector<int> arr = {17, 0, -4, 3, 15};
	//std::vector<int> arr = {3,4,8,9,10};

#if 0
	std::vector<int> arr = {91,74,73,73,73,73,73};
	std::map<std::vector<int>,int> cache_keep_max;
	auto r=BestTravel::chooseBestSum(300,3,arr);
#endif

#if 1
	std::vector<int> arr = {1,8,3,6,5,4,7,2,9};
	std::map<std::vector<int>,int> cache_keep_max;
	auto r=BestTravel::chooseBestSum(30,5,arr);
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
