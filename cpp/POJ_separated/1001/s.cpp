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

#define SIMPLE_LOG 


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
#define PRINT_COUT(p) 
#endif

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>
#include <assert.h>

typedef std::map<int, std::map<int, std::map<int, int>>> TYPEMAP ;

class BestTravel
{
	public:
		static int chooseBestSum(int t, int k, std::vector<int>& ls);
		static int chooseBestSum(int start_from,int up_bound,int findItemCnt,std::vector<int>& ls,
				TYPEMAP& cache_keep_max);
		// cache_keep_max : MAP: start_from,up_bound,findItemCnt -> sum
		static int findLargestOne(std::vector<int> keepInd,int up_bound,                std::vector<int>& ls,
				TYPEMAP& cache_keep_max);
		static int max(int a,int b) {
			//std::cout<<"MAX:"<<a<<" , "<<b<<std::endl;
			return a>b?a:b;};
		static int CALL_LEVEL;
		static std::vector<int> ANS_LIST;
};
int BestTravel::CALL_LEVEL=0;

int BestTravel::chooseBestSum(int start_from,int up_bound,int findItemCnt,std::vector<int>& ls,TYPEMAP& cache_keep_max) // recur
{
	if(findItemCnt<=0)
		return 0;
	if(findItemCnt+start_from>ls.size())// cannot find findItemCnt items
		return -1;

	//PRINTVAR(cache_keep_max.size());
	if( cache_keep_max.count(start_from)!=0 && 
			cache_keep_max[start_from].count(up_bound)!=0 &&
			cache_keep_max[start_from][up_bound].count(findItemCnt)!=0 
	  )
	{
#ifndef SIMPLE_LOG
		std::cout<<"USE CACHE: cache_keep_max";
		std::cout<<"\t"<<start_from;
		std::cout<<"\t"<<up_bound;
		std::cout<<"\t"<<findItemCnt;
		std::cout<<"=\t"<<cache_keep_max[start_from][up_bound][findItemCnt];
		PRINT_ENDL();
#endif
		return cache_keep_max[start_from][up_bound][findItemCnt];
	}


	CALL_LEVEL++;
#ifndef SIMPLE_LOG
	std::cout<<CALL_LEVEL<<")\t";
	for(int i=CALL_LEVEL;i>0;i--)
		std::cout<<"  .";
	PRINT_COUT("-->");
	PRINT_COUT(__FUNCTION__);
	PRINTVAR_hor(start_from);
	PRINTVAR_hor(up_bound);
	PRINTVAR_hor(findItemCnt);
	PRINTVAR_hor(ls.size());
	PRINT_ENDL();
	//PRINT_VECTOR_hor(keepInd);
	//PRINT_VECTOR_hor(ls);
	std::cout<<"ls:\t";
	int cntr=0;
	for(auto u=ls.begin();u!=ls.end();u++) {
		bool keep=0;
		if(start_from==cntr)
			std::cout<<cntr<<":"<<*u<<"*\t";
		else
			std::cout<<cntr<<":"<<*u<<"\t";
		cntr++;
	}
	std::cout<<""<<std::endl;
#endif

	int sum;
	if(start_from>=ls.size()-1) // the last one item;
	{
		if(ls[start_from]>up_bound)
			sum=-1;
		else 
			sum= ls[start_from];
	}
	else 
	{
		if(ls[start_from]>up_bound)
			sum= chooseBestSum(start_from+1,up_bound,findItemCnt,ls,cache_keep_max);
		else 
		{
			PRINT_COUT(start_from);
			PRINT_DEBUG_INFO_PREFIX("left\t");
			int left=chooseBestSum(start_from+1,up_bound-ls[start_from],findItemCnt-1,ls,cache_keep_max);
			PRINT_COUT(start_from);
			PRINT_DEBUG_INFO_PREFIX("right\t");
			int right =chooseBestSum(start_from+1,up_bound,findItemCnt,ls,cache_keep_max);
			PRINTVAR(left);
			PRINTVAR(right);
			PRINTVAR(ls[start_from]);

			int sum_of_left=(left==-1)?-1:(left+ ls[start_from]);
			sum= max(
					sum_of_left,
					right 
					);
		}
	}
	PRINTVAR(sum);
	//cache_keep_max[keepInd]=sum;
#ifndef SIMPLE_LOG
	std::cout<<CALL_LEVEL<<")\t";
	for(int i=CALL_LEVEL;i>0;i--)
		std::cout<<"  .";
	PRINT_COUT("<--");
	PRINT_COUT(__FUNCTION__);
	PRINTVAR_hor(sum);
	PRINT_ENDL();
#endif
	CALL_LEVEL--;
	cache_keep_max[start_from][up_bound][findItemCnt]=sum;
	return sum;
}

int BestTravel::chooseBestSum(int t, int k, std::vector<int>& ls)
{
	PRINT_DEBUG_INFO();
	clock_t start, end;
	start = clock();
	TYPEMAP cache_keep_max;
	std::vector<int> lsLessThanT;
	for(auto i:ls)
	{
		if(i<=0)
			return -1;
		if(i<=t)
			lsLessThanT.push_back(i);
	}
	PRINTVAR(ls.size());
	PRINTVAR(lsLessThanT.size());
	if(k>lsLessThanT.size())
		return -1;
	end = clock(); std::cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";
	auto ans= chooseBestSum(0,t,k,lsLessThanT,cache_keep_max);
	end = clock();

	//std::cout << "CLOCKS_PER_SEC " << CLOCKS_PER_SEC << "\n";
	//std::cout << "CPU-TIME START " << start << "\n";
	//std::cout << "CPU-TIME END " << end << "\n";
	//std::cout << "CPU-TIME END - START " <<  end - start << "\n";
	std::cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";
#if 0
	verbose_PRINT_VECTOR_hor(ls);
	verbose_PRINT_VECTOR_hor(lsLessThanT);
	PRINTVAR(lsLessThanT.size());
	verbose_PRINTVAR_hor(t);
	verbose_PRINTVAR_hor(k);
	verbose_PRINT_DEBUG_INFO_PREFIX("=====================");
	verbose_PRINTVAR(ans);
#endif
	//std::cout<<std::endl;

	verbose_PRINT_DEBUG_INFO_PREFIX("=====================");

	PRINTVAR(cache_keep_max.size());
	for(auto v1:cache_keep_max)
		for(auto v2:v1.second)
			for(auto v3:v2.second)
			{
				//PRINTVAR_hor(v1.first);
				//PRINTVAR_hor(v2.first);
				//PRINTVAR_hor(v3.first);
				//PRINTVAR_hor(v3.second);
				PRINT_COUT(v1.first);
				PRINT_COUT(v2.first);
				PRINT_COUT(v3.first);
				PRINT_COUT(v3.second);
				PRINT_ENDL();
			}
	verbose_PRINT_DEBUG_INFO_PREFIX("=====================");
	return ans;
}

void check(std::vector<int>& arr,int sum){
	for(int i1=0;i1<arr.size();i1++)
		for(int i2=i1+1;i2<arr.size();i2++)
			for(int i3=i2+1;i3<arr.size();i3++)
				for(int i4=i3+1;i4<arr.size();i4++)
					for(int i5=i4+1;i5<arr.size();i5++)
					{
						if(
								arr[i1]+
								arr[i2]+
								arr[i3]+
								arr[i4]+
								arr[i5]==sum
						  )
						{
							PRINTVAR(i1);
							PRINTVAR(i2);
							PRINTVAR(i3);
							PRINTVAR(i4);
							PRINTVAR(i5);
							return;
						}
					}
	PRINT_DEBUG_INFO_PREFIX("NO MATCH!");
}
int main ()
{

	//std::vector<int> arr = {17, 0, -4, 3, 15};
	//std::vector<int> arr = {3,4,8,9,10};

#if 0
	std::vector<int> arr = {91,74,73,73,73,73,73};
	std::map<std::vector<int>,int> cache_keep_max;
	auto r=BestTravel::chooseBestSum(300,3,arr);
#endif

#if 0
	std::vector<int> arr = {1,2,91,74,73,82,71};
	std::map<std::vector<int>,int> cache_keep_max;
	auto r=BestTravel::chooseBestSum(500,5,arr);
#endif
#if 1
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

	check(arr,r);
	check(arr,331);
	//
	//

	return 0;
}
