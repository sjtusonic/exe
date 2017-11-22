#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
#include <regex>
#include <map>
#include <assert.h>

#include "../../include/include.h"
using namespace std;

//=========================================================================================

int cntCompare=0;
class ShellSorting {
	public:
		template <class T>  
			T less(T& a,T& b) {
				cntCompare++;
				//DPRINT("less:"<<a<<","<<b);
				auto r= a<b?1:0;
				//DLOG(r);
				return r;
			}
		template <class T>  
			void exch(T&a,T&b)
			{
				//DPRINT("exch:"<<a<<","<<b);
				T tmp=a;
				a=b;
				b=tmp;
			}
		double getRandData(int min,int max,unsigned seed)
		{
			//unsigned seed=(unsigned)time(NULL)*1000;
			srand(seed);
			double m1=(double)(rand()%101)/101;                        // 计算 0，1之间的随机小数,得到的值域近似为(0,1)
			min++;                                                                             //将 区间变为(min+1,max),
			double m2=(double)((rand()%(max-min+1))+min);    //计算 min+1,max 之间的随机整数，得到的值域为[min+1,max]
			m2=m2-1;                                                                        //令值域为[min,max-1]
			return m1+m2;                                                                //返回值域为(min,max),为所求随机浮点数
		}
		vector<double> genRandom(int n)
		{
			vector<double> r;
			while(n>0)
			{
				unsigned seed=(unsigned)time(NULL)*1000+n;
				r.push_back(getRandData(0,100,seed));
				n--;
			}
			return r;
		}
		template <class T>  
			int count(vector<T> a, int n)
			{
				int r=0;
				for(auto i:a)
				{
					if(i==n)
						r++;
				}
				return r;
			}
		template <class T>  
			bool check (vector<T> a,vector<T> b)
			{
				for(T i:a)
				{
					int c1=count(a,i);
					int c2=count(b,i);
					if(c1!=c2)
					{
						DPRINT("check fail:"
								<<"i:"<<i
								<<",c1:"<<c1
								<<",c2:"<<c2
								);
						return false;
					}
				}
				return true;
			}
		template <class T>  
			void sort(vector<T>& a)
			{
				//DLOG(a);
				int h=0;
				int N=a.size();
				while(h<=N/3)
					h=h*3+1;
				while(h>=1)
				{
					for(int i=h;i<N;i+=1)
					{
						for(int j=i;j>=h && less(a[j],a[j-h]);j-=h)
						{
							//DPRINT("i:"<<i<<",j:"<<j<<",h:"<<h);
							exch(a[j-h],a[j]);
							//DLOG(a);
						}
					}
					int len=N/h;
					DLOG(len);
					DLOG(cntCompare );
					DLOG(cntCompare/len);
					cntCompare=0;
					DLOG(h);
					h/=3;
				}
				//DLOG(a);
				return;
			}
};


#if LNX
int main()
{
	clock_t start, end;
	start = clock();
	////////////////////////////////////////////////
	ShellSorting sol;
	//vector<int> height={2,0,3,0,7,11,22,33,44444,55,66,77,1,2,0,3,0,7,1,5,8,2};
	int SIZE=20000;
	vector<double> dvec=sol.genRandom(SIZE);
	auto bk=dvec;
	//height={2,0,3};
	//auto ans=sol.combinationSum(height,6);
	DLOG(dvec);
	sol.sort(dvec);
	DLOG(dvec);
	DLOG(sol.check(dvec,bk));
	DLOG(cntCompare );
	DLOG((double)cntCompare/SIZE);
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
