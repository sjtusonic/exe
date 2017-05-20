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


class BestTravel
{
	public:
		static int chooseBestSum(int t, int k, std::vector<int>& ls);
		static int chooseBestSum(std::vector<int>& keepInd,int up_bound,int findItemCnt,std::vector<int>& ls,std::map<std::vector<int>,int>& cache_keep_max);
		static int findLargestOne(std::vector<int> keepInd,int up_bound,                std::vector<int>& ls,std::map<std::vector<int>,int>& cache_keep_max);
};

int BestTravel::findLargestOne(std::vector<int> keepInd,int up_bound,std::vector<int>& ls,std::map<std::vector<int>,int>& cache_keep_max)
{
	sort(keepInd.begin(),keepInd.end());
	if(cache_keep_max.count(keepInd)!=0)
	{
#ifndef SIMPLE_LOG
		std::cout<<"USE CACHE: cache_keep_max";
		for (auto v:keepInd)
			std::cout<<"\t"<<v;
		std::cout<<"=\t"<<cache_keep_max[keepInd];
		PRINT_ENDL();
#endif
		return cache_keep_max[keepInd];
	}

	int sum=0;
	for(auto i:keepInd) // add sum of index kept
		sum+=ls[i];
	int max=-1;
	for(int i=0;i<ls.size();i++)
	{
		if(std::find(keepInd.begin(),keepInd.end(),i)!=keepInd.end())
			continue;
		if(ls[i]+sum>up_bound)
			continue;
		max=ls[i];
		break;
	}
	if(max==0)
		return max;

	for(int i=0;i<ls.size();i++)
	{
		if(std::find(keepInd.begin(),keepInd.end(),i)!=keepInd.end())
			continue;
		if(max<ls[i] && ls[i]+sum<=up_bound)
			max=ls[i];
	}
	//PRINT_VECTOR_hor(keepInd);
	//PRINTVAR(max);

	cache_keep_max[keepInd]=max;
	return max;
}
int BestTravel::chooseBestSum(std::vector<int>& keepInd,int up_bound,int findItemCnt,std::vector<int>& ls,std::map<std::vector<int>,int>& cache_keep_max)
{
#ifndef SIMPLE_LOG
	PRINT_COUT("-->");
	PRINT_COUT(__FUNCTION__);
	PRINTVAR_hor(up_bound);
	PRINTVAR_hor(findItemCnt);
	PRINT_ENDL();
	//PRINT_VECTOR_hor(keepInd);
	//PRINT_VECTOR_hor(ls);
	std::cout<<"ls:\t";
	int cntr=0;
	for(auto u=ls.begin();u!=ls.end();u++) {
		bool keep=0;
		for(auto i:keepInd)
			if(i==cntr)
			{
				keep=1;
				break;
			}
		if(keep)
			std::cout<<cntr<<":"<<*u<<"*\t";
		else
			std::cout<<cntr<<":"<<*u<<"\t";
		cntr++;
	}
	std::cout<<""<<std::endl;
#endif

	sort(keepInd.begin(),keepInd.end());
	if(cache_keep_max.count(keepInd)!=0)
	{
#ifndef SIMPLE_LOG
		std::cout<<"USE CACHE top: cache_keep_max";
		for (auto v:keepInd)
			std::cout<<"\t"<<v;
		std::cout<<"=\t"<<cache_keep_max[keepInd];
		PRINT_ENDL();
#endif
		return cache_keep_max[keepInd];
	}

	//std::cout<<std::endl;
	//PRINT_DEBUG_INFO_PREFIX("=====================");
	int sum=0;
	for(auto i:keepInd) // add sum of index kept
		sum+=ls[i];
	//PRINTVAR_hor(sum);
	if(sum>up_bound)
		return -1; // means that the sum of index kept will > up_bound
	//PRINT_DEBUG_INFO_PREFIX("ENTER chooseBestSum ====================>");


	int sum_bk=sum;
	if(findItemCnt==1) // find the largest one
	{
		auto value=findLargestOne(keepInd,up_bound,ls,cache_keep_max);
		if(value!=-1)
			sum+=value;
		else 
			sum=-1;
	}
	else // 
	{
		int maxValue=-1;
		for(int choose_next_fixed_ind=0; choose_next_fixed_ind!=ls.size();choose_next_fixed_ind++)
		{
			int i=choose_next_fixed_ind;
			if(std::find(keepInd.begin(),keepInd.end(),i)!=keepInd.end())
				continue;
			std::vector<int> newKeepInd=keepInd;
			newKeepInd.push_back(i);
			int newSum=0;
			for(auto i:newKeepInd) // add newSum of index kept
				newSum+=ls[i];

			//PRINT_DEBUG_INFO_PREFIX("CALL-----");
			//PRINT_VECTOR_hor(keepInd);
			//PRINT_VECTOR_hor(newKeepInd);
			//PRINTVAR(up_bound);
			//PRINTVAR(newSum);

			auto tmp=chooseBestSum(newKeepInd,up_bound,findItemCnt-1,ls,cache_keep_max); // recur
			if(tmp==-1)
				continue;
			if(maxValue<tmp)
				maxValue=tmp;
		}
		PRINTVAR(maxValue);
		if(maxValue==-1)
			return -1;
		if(maxValue>sum)
			sum=maxValue;
	}
	PRINTVAR(sum);
	cache_keep_max[keepInd]=sum;
	return sum;
}

int BestTravel::chooseBestSum(int t, int k, std::vector<int>& ls)
{
	clock_t start, end;
	start = clock();
	std::map<std::vector<int>,int> cache_keep_max;
	std::vector<int> lsLessThanT;
	for(auto i:ls)
	{
		if(i<=t)
			lsLessThanT.push_back(i);
	}
	PRINTVAR(ls.size());
	PRINTVAR(lsLessThanT.size());
	if(k>lsLessThanT.size())
		return -1;
	std::vector<int> keepInd;
	end = clock(); std::cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";
	auto ans= chooseBestSum(keepInd,t,k,lsLessThanT,cache_keep_max);
	PRINT_VECTOR_hor(ls);
	PRINT_VECTOR_hor(lsLessThanT);
	PRINTVAR_hor(t);
	PRINTVAR_hor(k);
	PRINT_DEBUG_INFO_PREFIX("=====================");
	PRINTVAR(ans);
	//std::cout<<std::endl;
	end = clock();

	//std::cout << "CLOCKS_PER_SEC " << CLOCKS_PER_SEC << "\n";
	//std::cout << "CPU-TIME START " << start << "\n";
	//std::cout << "CPU-TIME END " << end << "\n";
	//std::cout << "CPU-TIME END - START " <<  end - start << "\n";
	std::cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";
	return ans;
}

int main ()
{

	//std::vector<int> arr = {17, 0, -4, 3, 15};
	//std::vector<int> arr = {3,4,8,9,10};

#if 0
	std::vector<int> arr = {91,74,73,73,73,73,73};
	std::map<std::vector<int>,int> cache_keep_max;
	BestTravel::chooseBestSum(300,3,arr);
#endif

	std::vector<int> arr = {100, 76, 56, 44, 89, 73, 68, 56, 64, 123, 2333, 144, 50, 132, 123, 34, 89 };
	auto r=BestTravel::chooseBestSum(880,8,arr);

	//PRINTVAR(BestTravel::findLargestOne(std::vector<int>(),100,arr,cache_keep_max));

	//PRINT_DEBUG_INFO_PREFIX("================================================");
	//std::vector<int> a={1,2,3};
	//std::vector<int> b={1,3,2};
	//sort(b.begin(),b.end());
	//PRINTVAR((a==b));
	//PRINT_DEBUG_INFO_PREFIX("================================================");

	PRINTVAR(r);

	return 0;
}
