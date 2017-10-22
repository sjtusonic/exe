//#define SIMPLE_LOG 
#ifdef SIMPLE_LOG
#define DBG 0
#else
#define DBG 1
#endif

#if (DBG)
#define DLOG(x) cout<<#x<<"="<<x<<" @"<<__LINE__<<endl;
#else
#define DLOG(x)
#endif

#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";

#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<"VEC:\t"<<#a<<"="<<*u<<std::endl;}
#define PRINT_VECTOR_hor(a)  std::cout<<#a<<":\t";for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;

#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)

#if (DBG)
#define DENTER \
	LVCALL++; PRLVCALL; ::std::cout<<"-->"<<__FUNCTION__<<::std::endl; 
#define DRETURN \
	PRLVCALL; ::std::cout<<"<--"<<__FUNCTION__<<::std::endl; LVCALL--;
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

#ifdef SIMPLE_LOG
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

#if DBG
static int LV=0;
static int LVCALL=0;
#define PRLV     for(int u12=LV;    u12>0;u12--) {std::cout<<" .. ";}
#define PRLVCALL for(int u12=LVCALL;u12>0;u12--) {std::cout<<" .. ";}
	template <class U>
std::ostream & operator <<(std::ostream &os, const std::vector<U> &m)
{
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
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			DENTER;
			auto r= searchInRange(candidates,target,0);
			DRETURN;
			return r;
		}
		vector<vector<int>> search(vector<int>& cand, int target){
			DENTER;
			if(cand.size()==0)
				return {{}};
			if(cand[0]>target)
				return {{}};
			vector<vector<int>> r;
			vector<int> oneAns;
			int res=target;
			int ind=0;
			int endInd=cand.size()-1;
			DRETURN;
			return {{0},{1,2,3}};
		}
		vector<vector<int>> searchInRange(vector<int>& cand,int target,int from) {
			DENTER;
			DLOG(from);
			DLOG(target);
			if(target<cand[from])
			{
				DRETURN;
				return {{-1}};
			}
			vector<vector<int>> r;
			int endInd=cand.size()-1;
			if(from==endInd )
			{
				if(target==cand[endInd])
				{
					DRETURN;
					DLOG(endInd);
					return {{endInd}};
				}
				else
				{
					DRETURN;
					return {{}};
				}
			}
			else 
			{
				// use cand[from]
				int newTarget=target-cand[from];
				auto newAns=searchInRange(cand,newTarget,from+1);
				DLOG(newAns.size());
				for(auto v1:newAns)
				{
					auto v1add=v1;
					v1add.push_back(from);
					r.push_back(v1add);
				}
				DLOG(r);
				// not use cand[from]
				auto newAns2=searchInRange(cand,target,from+1);
				DLOG(newAns2.size());
				for(auto v1:newAns2)
				{
					auto v1add=v1;
					v1add.push_back(from);
					r.push_back(v1add);
				}
				DLOG(r);
			}
			DLOG(from);
			DLOG(target);
			DLOG(r);
			DRETURN;
			return r;
		}
		int binSearch(vector<int>& cand, int target,int from,int to){
			DENTER;
			if(cand[from]>target)
				return -1;
			if(cand[to]<target)
				return -1;
			if(from>to)
				return -1;

			while(1)
			{
				DLOG(from);
				DLOG(to);
				if(to-from<5)
				{
					for(int i=0;i<cand.size();i++)
						if(cand[i]==target)
							return i;
					return -1;
				}
				int mid=(from+to)/2;
				if(cand[mid]==target)
					return mid;
				else if(cand[mid]>target)
				{
					to=mid;
				}
				else //cand[mid]<target
				{
					from=mid;
				}
			}
			return -1;
		}
};
//=========================================================================================
int main ()
{
	Solution sol;
	vector<int> cand={0,1,2,3,4,5,6,7,8,9,10};
	DLOG(cand);
	PRINT_VECTOR_hor(cand);
	//DLOG(sol.binSearch(cand,13,0,cand.size()-1));
	auto ans=sol.combinationSum(cand, 7);
	DLOG(ans);
	return 0;
}
