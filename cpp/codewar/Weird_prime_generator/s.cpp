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

#define SIMPLE_LOG 


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
#define PRINT_COUT(p) 
#endif

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>
#include <assert.h>




#define PRINT_ARRAY(a,len)  for(int u=0;u<len;u++) {::std::cout<<u<<":\t"<<*a+u<<::std::endl;}
#define PRINTVAR(a) ::std::cout<<#a<<"\t=\t"<<a<<"\t@["<<__LINE__<<"]:["<<__FUNCTION__<<"]\t@\tFUNC="<<__PRETTY_FUNCTION__<<"\t@"<<__FILE__<<":"<<__LINE__<<::std::endl;

#define PRINTVAR_hor(a) ::std::cout<<#a<<"("<<a<<")\t";

#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<std::endl;}
#define PRINT_VECTOR_hor(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;
#define PRINT_MAP_TMP(a) std::cout<<"PRINT_MAP_TMP: "<<#a<<std::endl;for(auto it=a.begin();it!=a.end();++it) { std::cout<<it->first<<"->"; for(auto i:it->second) { std::cout<<"\t"<<i<<endl; } }

#define MEM_B(x) (*((byte*)(x)))
#define MEM_W(x) (*((WORD*)(x)))

#if 0
#define PRINT_DEBUG_INFO() \
	(::std::cout<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)

#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"\tzjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)
#endif
#define PRINT_DEBUG_INFO() \
	(::std::cout<<"zjc debug: " \
	 <<":\tFUNC="<<__PRETTY_FUNCTION__ \
	 <<":\tLINE=" <<__LINE__ \
	 <<":\tFILE=" <<__FILE__ \
	 <<":\tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)

#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"\tzjc debug: " \
	 <<":\tFUNC="<<__PRETTY_FUNCTION__ \
	 <<":\tLINE=" <<__LINE__ \
	 <<":\tFILE=" <<__FILE__ \
	 <<":\tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)



using namespace std;
class WeirdPrimeGen
{
	public:
		static long long countOnes(long long n);
		static long long maxPn(long long n);
		static int anOverAverage(long long n);
		static long long gcd(long long a,long long b);
		static vector<long long>* an(long long n);
		static vector<long long>* gn(long long n);
		//static vector<long long>* pn(long long n);
		static vector<long long>* anOver(long long n);
};
long long WeirdPrimeGen::gcd(long long a, long long b){ return a == 0 ? b : gcd(b % a, a); } 
vector<long long>* WeirdPrimeGen::an(long long n)
{
	if(n==1)
	{
		auto r=new vector<long long>();;
		r->push_back(7);
		return r;
	}
	else
	{
		auto r=an(n-1);
		auto anm1=r->back();
		auto new_item=anm1+gcd(n,anm1);
		r->push_back(new_item);
		PRINTVAR(new_item);
		PRINT_VECTOR_hor((*r));
		return r;
	}
};

vector<long long>* WeirdPrimeGen::gn(long long n)
{

	auto r=new vector<long long>();
	for(int i=0;i<n;i++)
		r->push_back(1);

	auto anv=*(an(n));
	PRINT_VECTOR_hor(anv);
	auto it=r->begin();
	it++;
	for(int i=0;i<n;i++)
	{
		*it=anv[i+1]-anv[i];
		it++;
	}
	PRINT_VECTOR_hor((*r));

	return r;
};

long long WeirdPrimeGen::countOnes(long long n)
{

	long long cntr=0;
	auto p=gn(n);
	for(auto it=p->begin();it!=p->end();it++)
		if(*it==1)
			cntr++;
	return cntr;
};

long long WeirdPrimeGen::maxPn(long long n)
{
	auto gnsize=n;
	vector<long long>* g;
	while(1)
	{
		g=gn(gnsize);
		if(gnsize-countOnes(gnsize)>=n)
			break;
		gnsize*=2;
		PRINTVAR(gnsize-countOnes(gnsize)-n);
	}

	PRINTVAR(gnsize-countOnes(gnsize)-n);
	PRINTVAR(gnsize);
	PRINTVAR(n);

	long long maxV=0;
	auto p=g;
	int p_item_cntr=0;
	for(auto it=p->begin();it!=p->end();it++)
	{
		if(*it!=1)
			p_item_cntr++;
		if(p_item_cntr>n)
			break;

		if(*it>maxV)
			maxV=*it;
	}
	return maxV;
};
int WeirdPrimeGen::anOverAverage(long long n)
{
	auto gnsize=n;
	while(1)
	{
		auto g=gn(gnsize);
		if(gnsize-countOnes(gnsize)==n)
			break;
		gnsize++;
	}

	long long maxV=0;
	auto p=gn(gnsize);
	long long cntr=0;
	for(auto it=p->begin();it!=p->end();it++)
	{
		if(*it!=1)
		{
			//float anOver=*it/cntr;
			float anOver=2/3;
			PRINTVAR_hor((*it));
			PRINTVAR_hor(cntr);
			PRINTVAR(anOver);
		}
		cntr++;
	}

	return maxV;
};
int main ()
{
	WeirdPrimeGen::gn(10);
	WeirdPrimeGen::maxPn(10);
	//WeirdPrimeGen::anOverAverage(20);
	return 0;
}
