
#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define PRINT_ARRAY(a,len)  for(int u=0;u<len;u++) {std::cout<<u<<":\t"<<*a+u<<std::endl;}
#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<std::endl;}
#define PRINT_VECTOR_hor(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;

#define PRINT_POINTER1(a)  std::cout<<#a; \
std::cout<<"\t= \t"<<a; \
std::cout<<"\t->\t"<<*a; \
std::cout<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;

#define PRINT_POINTER2(a)  std::cout<<#a; \
std::cout<<"\t= \t"<<a; \
std::cout<<"\t->\t"<<*a; \
std::cout<<"\t->\t"<<**a; \
std::cout<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;

#define PRINT_POINTER(a)  PRINT_POINTER1(a)

#include <iostream>
#include <map>
using namespace std;
void f(int** pptr);
void print_ptr(int* j);

int main()
{
	std::cout<<"------------------------------"<<std::endl;
	std::cout<<"SHOW:"<<std::endl;
	int i=1;
	int* ptr=&i;
	int ** pptr=&ptr;
	PRINT_POINTER2(pptr);
	f(pptr);
	PRINT_POINTER2(pptr);
	std::cout<<"------------------------------"<<std::endl;
	PRINT_POINTER1(*pptr);
	std::cout<<"------------------------------"<<std::endl;
}

void f(int** pptr)
{
	int* u=new int(2);
	//int* ptr=*pptr;
	PRINT_POINTER(pptr);
	*pptr=u;
	PRINT_POINTER(pptr);
}

//void print_ptr(int*j)
//{
//	cout<<"=============="<<""<<endl;
//	cout<<"pointer of pointer"<<endl;
//	//int* j;
//	//j=(int *)&j1;
//	cout<<"j\t=\t"<<j;
//	cout<<"\t->\t"<<*j;
//	int cnt=0;
//	void* jbk;
//	//while(cnt<10)
//	//{   
//	//	//cout<<"--------------"<<""<<endl;
//	//	//cout<<"ITER= "<<cnt<<""<<endl;
//	//	//cout<<"j= "<<j<<""<<endl;
//	//	//cout<<"sizeof(j)= "<<sizeof(j)<<""<<endl;
//	//	jbk=j;
//	//	j=(int*)&j;
//	//	if(j==jbk)
//	//		break;
//	//	cout<<"\t->\t"<<j;
//	//	cnt++;
//	//}   
//}							
