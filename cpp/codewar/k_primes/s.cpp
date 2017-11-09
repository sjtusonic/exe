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
#define DLOG(x) PRINTVAR(x)
//#define SIMPLE_LOG

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
#include <regex>
#include <assert.h>
#include <math.h>
using namespace std;

class KPrimes
{
	public:
		static std::vector<long long> countKprimes(int k, long long start, long long end);
		static int puzzle(int s);
		static bool isPrime(long long n);
		static void genVPrime(long long n);
		static bool getAllFactors(int n,vector<int>& v,int threshold=-1 );
		//private:
		static vector<int> mVecPrime;
		static vector<int> mVecExceedPrimeCntr;
		static long long   mVecPrime_upbound;
		static map<long long,vector<int>>* mPtr_MAP_n_all_fac;
};
vector<int> KPrimes::mVecPrime={};
vector<int> KPrimes::mVecExceedPrimeCntr={};
long long   KPrimes::mVecPrime_upbound=-1;
map<long long,vector<int>>* KPrimes::mPtr_MAP_n_all_fac=new map<long long,vector<int>>;
std::vector<long long> KPrimes::countKprimes(int k, long long start, long long end)
{
	PRINTVAR_hor(k);PRINTVAR_hor(start);PRINTVAR_hor(end);
	cout<<endl;
	auto ans=new std::vector<long long> ;
	for(long long i=start;i<=end;i++)
	{
		if(i==1)
			continue;
		std::vector<int> v;
		int count=mPtr_MAP_n_all_fac->count(i);
		if(count==0)
		{
			bool r=getAllFactors(i,v,k);
			if(r)
				(*mPtr_MAP_n_all_fac)[i]=v;
			else
				mVecExceedPrimeCntr.push_back(i);
		}
		else
		{
			PRINT_DEBUG_INFO_PREFIX("SPEED UP!");
			v=(*mPtr_MAP_n_all_fac)[i];
		}
		//cout<<"i:"<<i<<"\t";
		PRINTVAR_hor(i);
		PRINT_VECTOR_hor(v);
		long long tobe=1;
		int size=v.size();
		PRINTVAR(size);
		PRINTVAR(k);
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
		PRINTVAR(tobe);
		PRINTVAR(i);
		if(tobe==i)
			ans->push_back(i);
	}
	return *ans;
}
int KPrimes::puzzle(int s)
{
	cout<<"CALL puzzle: ";
	DLOG(s);
	vector<long long > v1=countKprimes(1,0,s);
	KPrimes::mVecExceedPrimeCntr={};
	vector<long long > v3=countKprimes(3,0,s);
	KPrimes::mVecExceedPrimeCntr={};
	vector<long long > v7=countKprimes(7,0,s);
	PRINT_VECTOR_hor(v1);
	PRINT_VECTOR_hor(v3);
	PRINT_VECTOR_hor(v7);
	int cnt=0;
	for(auto i1:v1)
		for(auto i3:v3)
			for(auto i7:v7)
				if(i1+i3+i7==s)
				{
					PRINTVAR(i1);
					PRINTVAR(i3);
					PRINTVAR(i7);
					cnt++;
				}
	return cnt;
}
bool KPrimes::isPrime(long long n)
{
	if(n<=mVecPrime_upbound)
	{
		auto result=find(mVecPrime.begin(),mVecPrime.end(),n);
		if(result!=mVecPrime.end())
		{
			PRINT_DEBUG_INFO_PREFIX("GOT Prime fast!");
			PRINTVAR(n);
			return true;
		}
		else
		{
			return false;
		}
	}
	else 
	{
		for(int i=2;i<(int)sqrt(n)+1;i++)
		{
			if((int)((double)n/i)==(double)((double)n/i))
				return false;
		}
		mVecPrime.push_back(n);
		return true;
	}
}
void KPrimes::genVPrime(long long n)
{
	if(n<=mVecPrime_upbound)
		return;

	// gen map
	map<long long,bool> MAP_i2isPrime;
	for(int i=2;i<=n;i++)
		MAP_i2isPrime[i]=1;
	// mark numbers which is not prime
	for(int i=2;i<=n;i++)
	{
		long long mul=2;
		while(mul*i<=n)
		{
			MAP_i2isPrime[mul*i]=0;
			mul++;
		}
	}
	// store primes into mVecPrime 
	mVecPrime={};
	for(int i=2;i<=n;i++)
		if(MAP_i2isPrime[i])
			mVecPrime.push_back(i);
	PRINTVAR(mVecPrime.size());
	mVecPrime_upbound=n;
}
bool KPrimes::getAllFactors(int n,vector<int>& v,int threshold )
{
	cout<<endl;
	cout<<"-->getAllFactors  ";
	PRINTVAR_hor(n);
	PRINTVAR_hor(threshold);
	cout<<"v=";
	PRINT_VECTOR_hor(v);
	cout<<endl;
	if(threshold!=-1 && v.size()>threshold )
		return false;
	if(n<=1)
		return true;
	// use exceed cache
	auto result=find(mVecExceedPrimeCntr.begin(),mVecExceedPrimeCntr.end(),n);
	PRINT_DEBUG_INFO();
	if(threshold!=-1 && result!=mVecExceedPrimeCntr.end())
	{
		PRINT_DEBUG_INFO();
		return false;
	}
	if(threshold!=-1 && v.size()>threshold )
	{
		PRINT_DEBUG_INFO();
		return false; // prime # exceed threshold 
	}
	//PRINT_DEBUG_INFO_PREFIX("getAllFactors");

	// use n2allfac cache 
	int count=mPtr_MAP_n_all_fac->count(n);
	if(count!=0)
	{
		PRINT_DEBUG_INFO();
		PRINT_DEBUG_INFO_PREFIX("SPEED UP2!");
		PRINTVAR(n);
		auto tmpv=(*mPtr_MAP_n_all_fac)[n]; // use cache
		// concat tmpv into v
		for(auto i:tmpv)
		{
			if(isPrime(i))
			{
				cout<<"PUSH "<<i<<endl;
				v.push_back(i); // there is a bug
			}
		}
		if(threshold!=-1 && v.size()>threshold )
			return false;
		return true;
	}
	PRINT_DEBUG_INFO();
	if(isPrime(n))
		v.push_back(n);
	if(threshold!=-1 && v.size()>threshold )
		return false;
	for(int i=2;i<(int)sqrt(n)+1;i++)
	{
		PRINT_DEBUG_INFO();
		if(
				(int)((double)n/i)==(double)((double)n/i)
				&& isPrime(i)
		  )
		{
			v.push_back(i);
			PRINTVAR(i);
			if(getAllFactors(n/i,v)==false)
				return false;
			(*mPtr_MAP_n_all_fac)[n]=v; // store into cache
			break;
		}
	}
	if(threshold!=-1 && v.size()>threshold )
		return false;
	PRINT_DEBUG_INFO();
	return true;
}
int main ()
{
	clock_t start, end;
	start = clock();
	//PRINTVAR(KPrimes::isPrime(3));
	//PRINTVAR(KPrimes::isPrime(4));
	//PRINTVAR(KPrimes::isPrime(5));
	//PRINTVAR(KPrimes::isPrime(97));

	vector<int> v;
	//KPrimes::getAllFactors(12,v,3); PRINT_VECTOR_hor(v);
	//auto b=KPrimes::getAllFactors(12,v,2); PRINT_VECTOR_hor(v); PRINTVAR(b);

	//auto cv=KPrimes::countKprimes(2,29,31); PRINT_VECTOR_hor(cv);
	//auto cv=KPrimes::countKprimes(2,0,100); PRINT_VECTOR_hor(cv);
	//auto cv=KPrimes::countKprimes(3,0,1000); PRINT_VECTOR_hor(cv);
	auto cv=KPrimes::countKprimes(5,500,600); PRINT_VECTOR_hor(cv);

	//auto cv=KPrimes::countKprimes(5,6610309,6611738); PRINT_VECTOR_hor(cv);

	v={};
	KPrimes::mVecExceedPrimeCntr={};
	KPrimes::mVecPrime_upbound=0;
	KPrimes::mVecPrime={};
	//KPrimes::(*mPtr_MAP_n_all_fac)={}; // need to be init
	PRINT_VECTOR_hor(v);
	auto succ=KPrimes::getAllFactors(567,v); PRINT_VECTOR_hor(v); PRINTVAR(succ);
	//PRINTVAR(KPrimes::puzzle(138));
	//PRINTVAR(KPrimes::puzzle(143));
	//PRINTVAR(KPrimes::puzzle(250));

	//KPrimes::genVPrime(6611738);
	//PRINT_VECTOR_hor(KPrimes::mVecPrime);
	end = clock();
	std::cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";
	return 0;
}
