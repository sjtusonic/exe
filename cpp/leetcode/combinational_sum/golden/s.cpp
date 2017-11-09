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
//Accepted 16ms c++ solution use backtracking for Combination Sum:

int cntSort=0;
int cntPushPop=0;
class Solution1 {
	public:
		std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
			DENTER;
			std::sort(candidates.begin(), candidates.end());
			cntSort++;
			std::vector<std::vector<int> > res;
			std::vector<int> combination;
			combinationSum(candidates, target, res, combination, 0);
			DRETURN;
			return res;
		}
	private:
		void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
			DENTER;
			DLOG1(target);
			DLOG1(begin);
			DLOG(res);
			if (!target) {
				DPRINT("res.push_back");
				res.push_back(combination);
				cntPushPop++;
				DRETURN;
				return;
			}
			for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
				combination.push_back(candidates[i]);
				DLOG(combination );
				combinationSum(candidates, target - candidates[i], res, combination, i);
				combination.pop_back();
				cntPushPop+=2;
			}
			DRETURN;
		}
};
//Accepted 12ms c++ solution use backtracking for Combination Sum II:

class Solution2 {
	public:
		std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
			std::sort(candidates.begin(), candidates.end());
			std::vector<std::vector<int> > res;
			std::vector<int> combination;
			combinationSum(candidates, target, res, combination, 0);
			return res;
		}
	private:
		void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
			if (!target) {
				res.push_back(combination);
				return;
			}
			for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
				if (i == begin || candidates[i] != candidates[i - 1]) {
					combination.push_back(candidates[i]);
					combinationSum(candidates, target - candidates[i], res, combination, i + 1);
					combination.pop_back();
				}
		}
};
//Accepted 0ms c++ solution use backtracking for Combination Sum III:

class Solution3 {
	public:
		std::vector<std::vector<int> > combinationSum(int k, int n) {
			std::vector<std::vector<int> > res;
			std::vector<int> combination;
			combinationSum(n, res, combination, 1, k);
			return res;
		}
	private:
		void combinationSum(int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin, int need) {
			if (!target) {
				res.push_back(combination);
				return;
			}
			else if (!need)
				return;
			for (int i = begin; i != 10 && target >= i * need + need * (need - 1) / 2; ++i) {
				combination.push_back(i);
				combinationSum(target - i, res, combination, i + 1, need - 1);
				combination.pop_back();
			}
		}
};

#if LNX
int main()
{
	clock_t start, end;
	start = clock();
	////////////////////////////////////////////////
	Solution1 sol;
	//vector<int> cand={1,2,3,6,7};
	//vector<int> cand={1,2,4,7,8,9,10,11,12,13,14};
	vector<int> cand={48,22,49,24,26,47,33,40,37,39,31,46,36,43,45,34,28,20,29,25,41,32,23};
	//vector<int> cand={48,22,49,24,26,47,33,40,37,39,31};
	//auto ans=sol.combinationSum(cand,2);
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
