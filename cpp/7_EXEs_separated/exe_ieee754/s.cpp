#include <math.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream> 
#include <sstream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <assert.h>   
#include <glob.h>

using namespace std;
#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define PRINT_ARRAY(a,len)  for(int u=0;u<len;u++) {std::cout<<u<<":\t"<<*a+u<<std::endl;}
#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<std::endl;}
#define PRINT_MAP(a)     std::cout<<#a<<":"<<std::endl;for(auto u:a) {std::cout<<u.first<<"\t->\t"<<u.second<<std::endl;}
#define PRINT_VECTOR_hor(a)  std::cout<<#a<<":";for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;


#define PRINT_POINTER1(a)  std::cout<<#a; \
	std::cout<<"\t= \t"<<a; \
std::cout<<"\t->\t"<<*a; \
std::cout<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;

#define PRINT_POINTER2(a)  std::cout<<#a; \
	std::cout<<"\t= \t"<<a; \
std::cout<<"\t->\t"<<*a; \
std::cout<<"\t->\t"<<**a; \
std::cout<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;

#define PRINT_POINTER3(a)  std::cout<<#a; \
	std::cout<<"\t= \t"<<a; \
std::cout<<"\t->\t"<<*a; \
std::cout<<"\t->\t"<<**a; \
std::cout<<"\t->\t"<<***a; \
std::cout<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;

#define PRINT_POINTER(a)  PRINT_POINTER1(a)


#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)
#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )

//inline std::vector<std::string> glob(const std::string& pat);

#include <stdint.h>
#include <stdio.h>

void convert_hex(char* myString)
{
	uint32_t num;
	float f;
	sscanf(myString, "%x", &num);  // assuming you checked input
	f = *((float*)&num);
	//printf("the hexadecimal 0x%08x becomes %.3f as a float\n", num, f);
	printf("hex=0x%08x\n",num);
	printf("flo=%.3f\n",f);
	printf("dec=%d\n",num);

	string bin="";
	string bin_with_delim="";
	printf("bin=");
	int n=num;
	int cntr=0;
	while (n) {
		if(cntr%8==0)
			bin_with_delim+=" ";
		if (n & 1)
		{
			bin+="1";
			bin_with_delim+="1";
		}
		else
		{
			bin+="0";
			bin_with_delim+="0";
		}

		n >>= 1;
		cntr--;
	}
	int diff=32-bin.size();
	while (diff!=0)
	{
		bin+="0";
		bin_with_delim+="0";
		diff--;
	}
	std::reverse(bin.begin(),bin.end());
	std::reverse(bin_with_delim.begin(),bin_with_delim.end());
	std::cout<<bin_with_delim;
	printf("\n");
	return;
}
int main()
{
	PRINT_DEBUG_INFO();

	//int a=0x4435e984;
	//float f=(float)a;
	//PRINTVAR(a);
	//PRINTVAR(f);



	//char myString[]="0x4435e984";
	char myString[]="0x43000000";
	//myString=scanf();
	std::cout<<"input :\t";
	scanf("%s",myString);
	convert_hex(myString);
	//printf("bin=%b\n",num);
}
