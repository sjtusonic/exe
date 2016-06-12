#include "8.1.h"
#include <iostream>
using namespace std;


void f8_1() {
   int a[10] ={1,2,3,6,4,3,2,1,8,-2};
   int * maxaddr;
   int idx;
   show_array_with_addr(a,sizeof(a)/sizeof(*a));
   maxaddr=findmax(a,sizeof(a)/sizeof(*a),&idx);
   cout<<"index="<<idx<<endl
       <<"max address="<<maxaddr<<endl
       <<"value of it="<<a[idx]<<endl;
}

void show_array_with_addr(int* array,int size) {
   for(int i=0;i<size;i++) {
      int v=*(array+i);
      int *addr=array+i;
      cout<<"index:"<<i<<" addr:"<<addr<<" value:"<<v<<endl;
   }
}

int* findmax(int* array,int size,int* index) {
   int max_v=-99999;
   for(int i=0;i<size;i++) {
      if(*(array+i)>max_v) {
         *index=i;
         max_v=*(array+i);
      }
   }
   return (array+*index);
}
