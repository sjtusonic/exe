
#include <vector>
#include <string>
#include <iostream>
#include <assert.h>

class Johnann
{
	public:
		static std::vector<long long> john(long long n);
		static std::vector<long long> ann(long long n);
		static long long sumJohn(long long n);
		static long long sumAnn(long long n);

		static void compose(long long n);
	private:
		static std::vector<long long> v_john;
		static std::vector<long long> v_ann;
};
std::vector<long long> Johnann::v_john;
std::vector<long long> Johnann::v_ann;

std::vector<long long> Johnann::john(long long n)
{
	compose(n);
	n--;
	//return john(n,0);
	std::vector<long long>::const_iterator first=v_john.begin();
	std::vector<long long>::const_iterator last =v_john.begin()+n+1;
	std::vector<long long> r(first,last);
	return r;
}
//-------------------------------------------------------------------------
std::vector<long long> Johnann::ann(long long n)
{
	compose(n);
	n--;
	//return ann(n,0);
	std::vector<long long>::const_iterator first=v_ann.begin();
	std::vector<long long>::const_iterator last =v_ann.begin()+n+1;
	std::vector<long long> r(first,last);
	return r;
}
//-------------------------------------------------------------------------
long long Johnann::sumJohn(long long n)
{
	long long r=0;
	for(auto v:john(n))
		r+=v;
	return r;
}
long long Johnann::sumAnn(long long n)
{
	long long r=0;
	for(auto v:ann(n))
		r+=v;
	return r;
}

void Johnann::compose(long long n)
{
	for(long long i=0;i<n;i++)
	{
		v_john.push_back(-1);
		v_ann.push_back(-1);
	}
	v_john[0]=0;
	v_ann[0]=1;
	for(long long i=1;i<n;i++)
	{
		v_john[i]=i-v_ann [v_john[i-1]];
		v_ann[i] =i-v_john[ v_ann[i-1]];
	}
}
int main ()
{

	//Johnann::ann(6);
	//{1, 1, 2, 2, 3, 3};
	//Johnann::john(11);
	//{0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6};

	//Johnann::compose(11);
	Johnann::ann(6);
	Johnann::john(11);
	//Johnann::john(1);
	//Johnann::john(4);
	//Johnann::john(3,0);
	//Johnann::ann(6,0);
	//Johnann::ann(4,0);
	//Johnann::ann(2,0);
	//Johnann::ann(10000);
	return 0;
}
