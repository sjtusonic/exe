#include <stdio.h>
#include <iostream>
//#include <iostream.h>
#include "1_bubble_sort.h"
#include "lib.h"
using   namespace   std;

int func_1_bubble_sort(int* r_cnt) {//FUNC
   return func_1_bubble_sort(r_cnt,10);
}
int func_1_bubble_sort(int*r_cnt,int LENGTH) {//FUNC
   return func_1_bubble_sort(r_cnt,LENGTH,0);
}
int func_1_bubble_sort(int*r_cnt,int LENGTH,int seed_incr) {//FUNC
   int len=LENGTH;
   //double a[]={3,2,1,4,6,-8,100,10};
   //double a[]={8,7,6,5,4,3,2,1};
   //double a[]={1,2,3,4,5,6,7,8};
   int* r=gen_rand_array_int(0,8,seed_incr);
   double a[LENGTH];
   int* r_bk=r;
   for(int i=0;i<=LENGTH;i++) {
      a[i]=(double)*r++;
   }
   r=r_bk;
   //cout<<"before, r:"<<endl;
   //show_array(r,len,true,0);
   cout<<"before:"<<endl;
   //int len=sizeof(a)/sizeof(*a);
   cout<<"length:"<<len<<endl;
   show_array(a,len,true,0);
   //int r_list[2];
   sort_bubble(r_cnt,a,len);
   cout<<"after:"<<endl;
   show_array(a,len,true,0);
   cout <<"diff_cnt,swap_cnt="<<r_cnt[0]<<","<<r_cnt[1]<<endl;
   return 0;
}

