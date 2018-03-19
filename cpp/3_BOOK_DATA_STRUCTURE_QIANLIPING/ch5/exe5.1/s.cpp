#include "h.h"
int f(int n)
{
	DENTERV(n);
	if(n==0) {
		DRETURN;
		return 0;
	}
	if(n%2==0)
	{
		auto r= f(n/2);
		DRETURN;
		return r;
	}
	{
		auto r= 1+f(n-1);
		DRETURN;
		return r;
	}
}
int f2(int n)
{
	DENTERV(n);
	if(n<=1) 
	{
		DRETURN;
		return n;
	}
	if(n%2==0)
	{
		auto r= n+f2(n/2);
		DRETURN;
		return r;
	}
	auto r= f2((n+1)/2)+f2((n-1)/2);
	DRETURN;
	return r;
}
int exe5p1e1(){
	f(1);
	f(2);
	f(3);
	f(99);
	f(100);
	f(128);
	f(197);
}
int exe5p1e2(){
	f2(1);
	f2(2);
	f2(3);
	f2(4);
	f2(5);
	f2(6);
	f2(197);
}
int main()
{
	//exe5p1e1();
	exe5p1e2();
	return 0;
}
