#include <iostream>
#include "include.top.h"
using namespace std;
const int size=10;

#if 0
int f9_1()
{
   int a[size];
   int n=0;

   unsigned seed=(unsigned)time(NULL)*1000;
   srand(seed);

   cout<<"please input:"<<size<<"datas:"<<endl;
   for(int i=0;i<size;i++)
   {
      //cin>>a[i];
      a[i]=rand()%100;
      cout<<a[i]<<", ";
   }
   cout<<endl;
   //findmax_use_ptr(a,size,0,&n);
   int(&a_ref)[size]=a; //<==> reference an array!
   //findmax_use_ref(a_ref[size],size,0,&n);
   findmax_use_ref(a_ref,size,0,&n);
   cout<<"max:"<<a[n]<<"index:"<<n<<endl;
   return 0;
}

void findmax_use_ptr(int*a,int size, int i, int*pk)
{
   if(i<size)
   {
      if(a[i]>a[*pk])
      {
         *pk=i;
      }
      findmax_use_ptr(a,size,i+1,&(*pk));
   }
}
void findmax_use_ref(int(&a)[size],int size, int i, int&pk)
{
   //if(i<size)
   //{
   //   if(a[i]>a[pk])
   //   {
   //      pk=i;
   //   }
   //   findmax_use_ptr(a,size,i+1,pk);
   //}
}


#endif

