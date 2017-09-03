
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
#define PRINT_COUT(p) \
	(::std::cout<<p<<"\t"   )
#define PRINT_ENDL() \
	(::std::cout<<::std::endl)

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

using namespace std;

class Solution {
	public:
		int callLevel;
		void initCallLevel() {callLevel=0;}
		int isIncremental(vector<int>& nums,int from,int to)
		{
			for(int i=from;i<=to-1;i++)
			{
				if(nums[i]>nums[i+1])
					return false;
			}
			return true;
		}
		void printIndentByCallLevel( int callLevel  ) {
			if(!DBG) {return;}
			int i=callLevel;
			while(i>0)
			{
				cout<<" .";
				i--;
			}
		}
		void getMaxIncr(vector<int>&nums,int from,int to,int lowBound,vector<int>&vInd)
		{
			callLevel++;
			printIndentByCallLevel(callLevel );
			if(DBG)
				cout<<"->"<<from<<","<<to<<",lb="<<lowBound<<endl;
			//vIndIn={};
			//vIndHead={};
			if(from>to)
			{
				printIndentByCallLevel(callLevel--);
				if(DBG)
					cout<<"<-"<<from<<","<<to<<"lb="<<lowBound<<",size="<<vInd.size()<<endl;
				return;
			}

			if(from==to && nums[from]>lowBound)
			{
				vInd.push_back(from);
				printIndentByCallLevel(callLevel--);
				if(DBG)
					cout<<"<-"<<from<<","<<to<<"lb="<<lowBound<<",size="<<vInd.size()<<endl;
				return;
			}

			//  from < to:
			//      with from:
			vector<int> vIndSub1,vIndSub2;

			if(nums[from]>lowBound)
			{
				vIndSub1.push_back(from);
				getMaxIncr(nums,from+1,to,nums[from],vIndSub1);    
			}

			if(DBG)
			{
				cout<<"sub1=";for(auto i:vIndSub1) cout<<"\t("<<i<<")"<<nums[i];cout<<endl;
			}
			//      without from:
			getMaxIncr(nums,from+1,to,lowBound,vIndSub2);

			auto added=(vIndSub1.size()>vIndSub2.size())?vIndSub1:vIndSub2;
			for(auto i:added)
			{
				vInd.push_back(i);
			}
			if(DBG)
			{
				cout<<"sub2=";for(auto i:vIndSub2) cout<<"\t("<<i<<")"<<nums[i];cout<<endl;
				cout<<"resu=";for(auto i:vInd) cout<<"\t("<<i<<")"<<nums[i];cout<<endl;
			}

			printIndentByCallLevel(callLevel--);
			if(DBG)
			{
				cout<<"<-"<<from<<","<<to<<"lb="<<lowBound<<",size="<<vInd.size()<<endl;
			}

		}

		int lengthOfLIS(vector<int>& nums) {
			if(nums.size()==0)
				return 0;
			////////////////
			bool ordered=true;
			for(int i=0;i<nums.size()-1;i++)
			{
				DLOG(i);
				if(nums[i]>=nums[i+1])
				{
					ordered=false;
					break;
				}
			}
			if(ordered)
			{
				return nums.size();
			}
			////////////////
			vector<int> vInd;
			cout<<"nums=";
			int ind=0;
			for(auto i:nums) {cout<<"\t("<<ind++<<")"<<i;}cout<<endl;
			getMaxIncr(nums,0,nums.size()-1,-9999,vInd);
			return vInd.size();
		}
};

int main() 
{
	DLOG(DBG);
	vector<int> v={3,2,5,4,1,7};
	//vector<int> v={1,2,3,4};
	//vector<int> v={2,2};
	Solution s;
	s.initCallLevel();
	int R=s.lengthOfLIS(v);
	DLOG(R);
}
