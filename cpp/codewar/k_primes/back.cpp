
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>
#include <regex>
#include <assert.h>
#include <math.h>
using namespace std;

class KPrimes
{
	public:
		static std::vector<long long> countKprimes(int k, long long start, long long end);
		static int puzzle(int s);
		static bool isPrime(int n);
		static void getAllFactors(int n,vector<int>& v );
		static vector<int> vprime;
		static map<int,vector<int>>* pmap_n_all_fac;
};
vector<int> KPrimes::vprime={};
map<int,vector<int>>* KPrimes::pmap_n_all_fac=new map<int,vector<int>>;
std::vector<long long> KPrimes::countKprimes(int k, long long start, long long end)
{
//auto map_n_all_fac=*pmap_n_all_fac;
	auto ans=new std::vector<long long> ;
	for(int i=start;i<=end;i++)
	{
		if(i==1)
			continue;
		std::vector<int> v;
		int count=pmap_n_all_fac->count(i);
		if(count==0)
		{
			getAllFactors(i,v);
			(*pmap_n_all_fac)[i]=v;
		}
		else
		{
			v=(*pmap_n_all_fac)[i];
		}
		long long tobe=1;
		int size=v.size();
		if(size>k)
			continue;  
		else if(v.size()==1)
			tobe=pow(v[0],k);
		else if(v.size()<k) // <k and !=1
			continue;
		else
		{
			for(auto n:v)
			{
				tobe*=n;
			}
		}
		if(tobe==i)
			ans->push_back(i);
	}
	return *ans;
}
int KPrimes::puzzle(int s)
{
	vector<long long > v1=countKprimes(1,0,s);
	vector<long long > v3=countKprimes(3,0,s);
	vector<long long > v7=countKprimes(7,0,s);
	int cnt=0;
	for(auto i1:v1)
		for(auto i3:v3)
			for(auto i7:v7)
				if(i1+i3+i7==s)
				{
					cnt++;
				}
	return cnt;
}
bool KPrimes::isPrime(int n)
{
	auto result=find(vprime.begin(),vprime.end(),n);
	if(result!=vprime.end())
	{
		return true;
	}
	for(int i=2;i<(int)sqrt(n)+1;i++)
	{
		if((int)((double)n/i)==(double)((double)n/i))
			return false;
	}
	vprime.push_back(n);
	return true;
}
void KPrimes::getAllFactors(int n,vector<int>& v )
{
	if(n<=1)
		return;
	if(isPrime(n))
		v.push_back(n);
	for(int i=2;i<n;i++)
	{
		if(
				(int)((double)n/i)==(double)((double)n/i)
				&& isPrime(i)
		  )
		{
			v.push_back(i);
			getAllFactors(n/i,v);
			break;
		}
	}
	return;
}
