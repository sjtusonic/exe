#include <vector>
#include <string>
#include <iostream>
#include <map>

typedef std::map<int, std::map<int, std::map<int, int>>> TYPEMAP ;

class BestTravel
{
	public:
		static int chooseBestSum(int t, int k, std::vector<int>& ls);
		static int chooseBestSum(int start_from,int up_bound,int findItemCnt,std::vector<int>& ls, TYPEMAP& cache_keep_max);
		static int max(int a,int b) {return a>b?a:b;};
};

int BestTravel::chooseBestSum(int start_from,int up_bound,int findItemCnt,std::vector<int>& ls,TYPEMAP& cache_keep_max) // recur
{
	if(findItemCnt<=0)
		return 0;
	if(findItemCnt+start_from>ls.size())// cannot find findItemCnt items
		return -1;

	if( cache_keep_max.count(start_from)!=0 && 
		 cache_keep_max[start_from].count(up_bound)!=0 &&
		 cache_keep_max[start_from][up_bound].count(findItemCnt)!=0 
	  )
		return cache_keep_max[start_from][up_bound][findItemCnt];

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
			int left=chooseBestSum(start_from+1,up_bound-ls[start_from],findItemCnt-1,ls,cache_keep_max);
			int right =chooseBestSum(start_from+1,up_bound,findItemCnt,ls,cache_keep_max);

			int sum_of_left=(left==-1)?-1:(left+ ls[start_from]);
			sum= max( sum_of_left, right );
		}
	}
	cache_keep_max[start_from][up_bound][findItemCnt]=sum;
	return sum;
}

int BestTravel::chooseBestSum(int t, int k, std::vector<int>& ls)
{
	TYPEMAP cache_keep_max;
	std::vector<int> lsLessThanT;
	for(auto i:ls)
	{
		if(i<=0)
			return -1;
		if(i<=t)
			lsLessThanT.push_back(i);
	}
	if(k>lsLessThanT.size())
		return -1;
	auto ans= chooseBestSum(0,t,k,lsLessThanT,cache_keep_max);

	return ans;
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
#if 0
	std::vector<int> arr = {100, 76, 56, 44, 89, 73, 68, 56, 64, 123, 2333, 144, 50, 132, 123, 34, 89 };
	//std::vector<int> arr = {100, 44, 89, 73, 68, 56, 64, 123, 34, 89 };
	auto r=BestTravel::chooseBestSum(500,5,arr);
#endif

#if 0
	std::vector<int> arr = { 91,74,73,85,73,81,87};
	auto r=BestTravel::chooseBestSum(331,5,arr);
#endif
#if 1
	std::vector<int> arr = { 91,74,73,85,73,81,87 };
	auto r=BestTravel::chooseBestSum(331,4,arr);
#endif

	return 0;
}
