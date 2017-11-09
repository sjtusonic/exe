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

int cntSort=0;
int cntPushPop=0;
class Solution {
	public:
		vector<vector<int>> genPermRep(int numbers) {
			vector<vector<int>> r;
			int temp;
			int a[numbers], upto = numbers+1, temp2;
			for( temp2 = 1 ; temp2 <= numbers; temp2++){
				a[temp2]=1;
			}
			a[numbers]=0;
			temp=numbers;
			while(1){
				if(a[temp]==upto-1){
					temp--;
					if(temp==0)
						break;
				}
				else{
					a[temp]++;
					while(temp<numbers){
						temp++;
						a[temp]=1;
					}

					vector<int> r1;
					printf("(");
					for( temp2 = 1 ; temp2 <= numbers; temp2++){
						printf("%d", a[temp2]-1);
						r1.push_back(a[temp2]-1);
						cntPushPop++;
					}
					printf(")\n");
					r.push_back(r1);
					cntPushPop++;
				}
			}
			return r;
		}
		vector<vector<int>> genPermRep(vector<int> cand,int target) {
			DENTER;
			vector<vector<int>> r;
			int temp;
			int numbers=cand.size();
			DLOG(numbers);
			//int a[numbers],
			vector<int> a;
			for(int i=0;i<numbers;i++)
			{
				a.push_back(0);
				cntPushPop++;
			}
			int upto = numbers+1, ind2;
			for( ind2 = 1 ; ind2 < numbers; ind2++){
				//DEBUG_MARK;
				//DLOG(ind2);
				a[ind2]=1;
			}
			DEBUG_MARK;
			a[numbers]=0;
			temp=numbers;
			while(1){
				DEBUG_MARK;
				int localSum=0;
				if(a[temp]==upto-1){
					DEBUG_MARK;
					temp--;
					if(temp==0)
						break;
				}
				else{
					DEBUG_MARK;
					a[temp]++;
					while(temp<numbers){
						temp++;
						a[temp]=1;
					}

					vector<int> r1;
					printf("(");
					for( ind2 = 1 ; ind2 <= numbers; ind2++){
						printf("%d", a[ind2]-1);
						auto v=cand[a[ind2]-1];
						if(localSum<target)
						{
							DPRINT("PUSH"<<v);
							r1.push_back(v);
							cntPushPop++;
							localSum+=   v;
						}
						if(localSum==target)
						{
							DPRINT("PUSH!");
							break;
						}
						if(localSum>target)
							break;
					}
					printf(")\n");
					sort(r1.begin(),r1.end());
					cntSort++;
					if(localSum==target &&
							find(r.begin(),r.end(),r1)==r.end()
					  )
						r.push_back(r1);
					cntPushPop++;
				}
			}
			DEBUG_MARK;
			DRETURN;
			return r;
		}
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			DENTER;
			vector<vector<int>> ans;
			sort(candidates.begin(),candidates.end());
			cntSort++;
			vector<int> combination;
			searchInRange(candidates,target,ans,combination,0);
			DRETURN;
			return ans;
		}
		vector<vector<int>> search(vector<int>& cand, int target){
			DENTER;
			if(cand.size()==0)
				return {{}};
			if(cand[0]>target)
				return {{}};
			vector<vector<int>> r;
			vector<int> oneAns;
			int combination=target;
			int ind=0;
			int endInd=cand.size()-1;
			DRETURN;
			return {{0},{1,2,3}};
		}
		void searchInRange(vector<int>& cand,int target,vector<vector<int>>& res,vector<int>& combination,int from) {
			DENTER;
			DLOG(from);
			DLOG(target);
			if(target==0)
			{
				res.push_back(combination);
				DRETURN;
				return ;
			}
			if(target<cand[from])
			{
				DRETURN;
				return ;
			}
			vector<vector<int>> r;
			for(int i=from;i<cand.size();i++)
			{
				// use cand[i]
				DPRINT("use cand["<<i<<"]");
				int newTarget=target-cand[i];
				combination.push_back(cand[i]);
				searchInRange(cand,newTarget,res,combination,i);
				combination.pop_back();
				DLOG(r.size());
				DLOG(r);
			} //for(set i=from;i<cand.size;i++)
			DLOG(r.size());
			DLOG(r);
			DLOG(from);
			DLOG(target);
			DLOG(r);
			DRETURN;
			return ;
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

#if LNX
int main()
{
	clock_t start, end;
	start = clock();
	////////////////////////////////////////////////
	Solution sol;
	//vector<int> cand={1,2,3,6,7};
	//vector<int> cand={6,1,2,4};
	//vector<int> cand={1,2,4};
	vector<int> cand={48,22,49,24,26,47,33,40,37,39,31,46,36,43,45,34,28,20,29,25,41,32,23};
	//vector<int> cand={48,22,49,24,26,47,33,40,37,39,31};
	//auto ans=sol.combinationSum(cand,6);
	auto ans=sol.combinationSum(cand,69);
	DLOG(ans);
	//DLOG(sol.genPermRep(2));
	//DLOG(sol.genPermRep(cand));
	DLOG(cntSort);
	DLOG(cntPushPop);
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



