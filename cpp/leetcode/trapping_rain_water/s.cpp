#define SIMPLE_LOG 0
#define LNX 1

#if (!SIMPLE_LOG)
#define DLOG(x) cout<<#x<<"="<<x<<" @"<<__LINE__<<endl;
#define DLOG1(x) cout<<#x<<"="<<x<<"\t";
#else
#define DLOG(x)
#define DLOG1(x)
#endif

#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";

#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<"VEC:\t"<<#a<<"="<<*u<<std::endl;}
#define PRINT_VECTOR_hor(a)  std::cout<<#a<<":\t";for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;

#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)

#if (!SIMPLE_LOG)
#define DENTER \
	LVCALL++; PRLVCALL; ::std::cout<<"-->"<<__FUNCTION__<<::std::endl; 
#define DRETURN \
	PRLVCALL; ::std::cout<<"<--"<<__FUNCTION__<<"@" <<__LINE__<<::std::endl; LVCALL--;
#endif

#define DEBUG_MARK PRINT_DEBUG_INFO()
#define PRINT_COUT(p) \
	(::std::cout<<p<<"\t"   )
#define PRINT_ENDL() \
	(::std::cout<<::std::endl)
#define DPRINT(x) \
	(::std::cout<<x<<::std::endl   )
#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )



#define verbose_PRINT_VECTOR_hor(a)  std::cout<<#a<<":\t";for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;
#define verbose_PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define verbose_PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define verbose_PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )

#if SIMPLE_LOG
#define PRINTVAR(a)
#define PRINTVAR_hor(a)
#define PRINT_VECTOR(a)  
#define PRINT_VECTOR_hor(a) 
#define PRINT_DEBUG_INFO()

#define DEBUG_MARK 
#define PRINT_DEBUG_INFO_PREFIX(p)
#define DPRINT(x)
#define PRINT_COUT(p) 

#define DENTER 
#define DRETURN 
#endif

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
#include <regex>
#include <map>
#include <assert.h>
using namespace std;

#if !SIMPLE_LOG
static int LV=0;
static int LVCALL=-1;
//#define PRLV     std::cout<<LV<<"\t"; for(int u12=LV;    u12>0;u12--) {std::cout<<" .. ";}
#define PRLV                          for(int u12=LV;    u12>0;u12--) {std::cout<<" .. ";}
#define PRLVCALL std::cout<<"L"<<LVCALL<<"\t"; for(int u12=LVCALL;u12>0;u12--) {std::cout<<" .. ";}
	template <class U>
std::ostream & operator <<(std::ostream &os, const std::vector<U> &m)
{
	if(m.size()==0)
		return os;
	os << std::endl;
	PRLV(LV);
	os << "->";
	os << std::endl;
	LV++;
	PRLV(LV);
	for (const auto &p : m)
	{
		os << p << ", " ;
	}
	os << std::endl;
	LV--;
	PRLV(LV);
	os << "<-";

	return os;
}

	template <class U, class V>
std::ostream & operator <<(std::ostream &os, const std::map<U, V> &m)
{
	os << "->";
	os << std::endl;
	for (const auto &p : m)
	{
		os << p.first << ": " << p.second;
		os << std::endl;
	}
	os << "<-";

	return os;
}
#endif
//=========================================================================================

class Solution {
	public:

		template <class T>  
			T min(T& a,T& b) {
				return a>b?b:a;
			}


		vector<int> search(vector<int>& height, bool left) {// left==1 from left to right

			DENTER;
			DLOG(left);
			vector<int> r;
			vector<int> lv;
			bool flagIn=0;
			int hEdge=-1;
			if(!left) // from right to left
			{
				//int size=height.size();
				int curMax=0;
				for(int i=height.size()-1;i>=0;i-- )
				{
					if(height[i]>curMax)
						curMax=height[i];
					lv.push_back(curMax);
				}
				std::reverse(lv.begin(),lv.end());
			}
			else 
			{
				int curMax=0;
				for(int i=0;i<height.size();i++ )
				{
					if(height[i]>curMax)
						curMax=height[i];
					lv.push_back(curMax);
				}
			}
			DLOG(lv);
			DLOG(r);
			DRETURN;
			return lv;
		};
		int trap(vector<int>& height) {
			DLOG(height);
			auto l1=search(height,1);
			auto l2=search(height,0);
			auto l=l1;
			auto depth=l1;
			int r=0;
			for(int i=0;i<l.size();i++)
			{
				if(l[i]>l2[i])
					l[i]=l2[i];
				depth[i]=l[i]-height[i];
				r+=depth[i];
			}
			DLOG(l);
			DLOG(depth);
			return r;
		};
};


#if LNX
int main()
{
	clock_t start, end;
	start = clock();
	////////////////////////////////////////////////
	Solution sol;
	vector<int> height={2,0,3,0,7,1,5};
	            height={0,1,0,2,1,0,1,3,2,1,2,1};
	//auto ans=sol.combinationSum(height,6);
	auto ans=sol.trap(height);
	DLOG(ans);
	//DLOG(cntSort);
	//DLOG(cntPushPop);
	////////////////////////////////////////////////
	end = clock();

	cout << "CLOCKS_PER_SEC " << CLOCKS_PER_SEC << "\n";
	cout << "CPU-TIME START " << start << "\n";
	cout << "CPU-TIME END " << end << "\n";
	cout << "CPU-TIME END - START " <<  end - start << "\n";
	cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";
}
#endif

#if 0
#endif



