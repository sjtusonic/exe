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
using namespace std;

class BestTravel
{
	public:
		static int chooseBestSum(int t, int k, std::vector<int>& ls)
		{
			unsigned n = ls.size();    // size of set

			if( k > n )
				return -1;

			int best_sum = -1;
			int sum, j;

			// We represent a subset of ls (of size k) by a
			// strictly increasing sequence of indices into ls:
			vector<unsigned> indices(k);

			// The first subset to consider:
			for(int i=0; i<k; i++)
				indices[i] = i;

			// Iterate over all subsets of ls:
			for(;;)
			{
				PRINT_VECTOR_hor(indices);
				// Find the sum for this subset:
				sum = 0;
				for(j=0; j<k; j++)
					sum += ls[indices[j]];

				if( sum > best_sum && sum <= t)
					best_sum = sum;

				// Now move on to the next subset.
				if( indices[k-1] < n-1 )
				{
					++indices[k-1];
					continue;
				}

				// Find an index we can increment:
				for(j=k-2; j >=0 && indices[j] == indices[j+1]-1; j--)
					;

				if( j < 0 )
					break;

				++indices[j];
				//
				for(j++; j < k; j++)
					indices[j] = indices[j-1]+1;
			}

			return best_sum;
		}
};
std::vector<std::vector<unsigned>> gen_full_exhausive_indices (unsigned n,unsigned k) ;

std::vector<std::vector<unsigned>> gen_full_exhausive_indices (unsigned n,unsigned k) 
{
	PRINT_DEBUG_INFO();
	std::vector<std::vector<unsigned>> r;
	PRINT_DEBUG_INFO();
	//
	PRINT_DEBUG_INFO();
	// We represent a subset of ls (of size k) by a
	// strictly increasing sequence of indices into ls:
	std::vector<unsigned> indices(k);
	for(int i=0; i<k; i++)
		indices[i] = i;

	PRINT_VECTOR_hor(indices);
	// Iterate over all subsets of ls:
	int j;
	for(;;)
	{
		PRINT_VECTOR_hor(indices);
		r.push_back(indices);
		// Now move on to the next subset.
		if( indices[k-1] < n-1 )
		{
			++indices[k-1];
			continue;
		}

		// Find an index we can increment:
		for(j=k-2; j >=0 && indices[j] == indices[j+1]-1; j--)
			;

		if( j < 0 )
			break;

		++indices[j];
		for(j++; j < k; j++)
			indices[j] = indices[j-1]+1;
	}
	return r;
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
	auto r=BestTravel::chooseBestSum(331,3,arr);
#endif
	//PRINTVAR(BestTravel::findLargestOne(std::vector<int>(),100,arr,cache_keep_max));

	//PRINT_DEBUG_INFO_PREFIX("================================================");
	//std::vector<int> a={1,2,3};
	//std::vector<int> b={1,3,2};
	//sort(b.begin(),b.end());
	//PRINTVAR((a==b));

	std::vector<std::vector<unsigned>> vv=gen_full_exhausive_indices(6,2);

	PRINT_DEBUG_INFO_PREFIX("================================================");

	for(std::vector<unsigned> v:vv)
	{
		PRINT_VECTOR_hor(v);
	}

	PRINT_DEBUG_INFO_PREFIX("================================================");
	//
	//

	return 0;
}
