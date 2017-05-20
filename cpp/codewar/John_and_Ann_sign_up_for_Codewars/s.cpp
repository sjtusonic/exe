#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;

#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<"VEC:\t"<<#a<<"="<<*u<<std::endl;}

#define PRINT_VECTOR_hor(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;
//#define PRINT_VECTOR_hor(a) 
#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)

#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )

#include <vector>
#include <string>
#include <iostream>
#include <assert.h>

class Johnann
{
	public:
		static std::vector<long long> john(long long n);
		static std::vector<long long> ann(long long n);
		static std::vector<long long> john(long long n,int hier);
		static std::vector<long long> ann(long long n,int hier);
		static long long sumJohn(long long n);
		static long long sumAnn(long long n);

		static void compose(long long n);
		static std::vector<long long> v_john;
		static std::vector<long long> v_ann;
	private:
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
	PRINT_VECTOR(r);
	return r;
}
//-------------------------------------------------------------------------
std::vector<long long> Johnann::john(long long ind,int hier)
{
	int hierbk=hier;
	std::string indent="";
	while(hierbk>0) {indent+="  ."; hierbk--;}

	std::cout<<indent<<">-----------------------"<<std::endl;
	std::cout<<indent<<"CALL john("<<ind<<")"<<std::endl;
	assert(ind>=0);
	std::vector<long long>& v_ann_ref=v_ann;
	std::vector<long long>& v_john_ref=v_john;
	PRINTVAR(v_john_ref.size());
	PRINTVAR(v_ann_ref.size());
	PRINT_VECTOR(v_john_ref);
	PRINT_VECTOR(v_ann_ref);
	if(v_john_ref.size()>=ind+1)
	{
		PRINT_DEBUG_INFO_PREFIX("FAST john\t");
		std::vector<long long>::const_iterator first=v_john_ref.begin();
		std::vector<long long>::const_iterator last =v_john_ref.begin()+ind+1;
		std::vector<long long> r(first,last);
		PRINTVAR(v_ann_ref.size());
		PRINTVAR(r.size());
		return r;
	}

	if(ind==0)
	{
		v_john_ref.push_back(0);
	}
	else
	{
		john(ind-1,hier+1);
		ann(v_john_ref[ind-1],hier+1);

		v_john_ref.push_back(ind-v_ann_ref[v_john_ref[ind-1]]);
	}
	PRINTVAR(v_john_ref.size());
	PRINTVAR(v_ann_ref.size());
	PRINT_VECTOR(v_john_ref);
	PRINT_VECTOR(v_ann_ref);
	std::cout<<indent<<"<john"<<ind<<" = "<<v_john_ref[v_john_ref.size()-1]<<std::endl;
	std::cout<<indent<<"<-----------------------"<<std::endl;
	PRINT_DEBUG_INFO();
	PRINTVAR(ind);
	std::vector<long long>::const_iterator first=v_john_ref.begin();
	std::vector<long long>::const_iterator last =v_john_ref.begin()+ind+1;
	std::vector<long long> r(first,last);
	PRINTVAR(v_john_ref.size());
	PRINTVAR(r.size());
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
	PRINT_VECTOR(r);
	return r;
}
//-------------------------------------------------------------------------
std::vector<long long> Johnann::ann(long long ind,int hier)
{
	int hierbk=hier;
	std::string indent="";
	while(hierbk>0) {indent+="  ."; hierbk--;}

	std::cout<<indent<<">-----------------------"<<std::endl;
	std::cout<<indent<<"CALL ann("<<ind<<")"<<std::endl;
	assert(ind>=0);
	std::vector<long long>& v_john_ref=v_john;
	std::vector<long long>& v_ann_ref=v_ann;
	PRINTVAR(v_ann_ref.size());
	PRINTVAR(v_john_ref.size());
	PRINT_VECTOR(v_ann_ref);
	PRINT_VECTOR(v_john_ref);
	if(v_ann_ref.size()>=ind+1)
	{
		PRINT_DEBUG_INFO_PREFIX("FAST ann\t");
		std::vector<long long>::const_iterator first=v_ann_ref.begin();
		std::vector<long long>::const_iterator last =v_ann_ref.begin()+ind+1;
		std::vector<long long> r(first,last);
		return r;
	}

	if(ind==0)
	{
		v_ann_ref.push_back(1);
	}
	else
	{
		ann(ind-1,hier+1);
		john(v_ann_ref[ind-1],hier+1);

		v_ann_ref.push_back(ind-v_john_ref[v_ann_ref[ind-1]]);
	}
	PRINTVAR(v_ann_ref.size());
	PRINTVAR(v_john_ref.size());
	PRINT_VECTOR(v_ann_ref);
	PRINT_VECTOR(v_john_ref);
	std::cout<<indent<<"<ann"<<ind<<" = "<<v_ann_ref[v_ann_ref.size()-1]<<std::endl;
	std::cout<<indent<<"<-----------------------"<<std::endl;

	std::vector<long long>::const_iterator first=v_ann_ref.begin();
	std::vector<long long>::const_iterator last =v_ann_ref.begin()+ind+1;
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
	PRINTVAR(n);
	for(auto v:ann(n))
		r+=v;
	PRINTVAR(r);
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
	//PRINT_VECTOR(Johnann::v_john);
	//PRINT_VECTOR(Johnann::v_ann);
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
