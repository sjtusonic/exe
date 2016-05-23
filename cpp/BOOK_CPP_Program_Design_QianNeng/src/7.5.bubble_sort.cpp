#include <stdio.h>
#include <iostream>
//#include <iostream.h>
#include "7.5.h"
#include "lib.h"
using   namespace   std;

int f7_5() {
   //double a[]={3,2,1,4,6,-8,100,10};
   //double a[]={8,7,6,5,4,3,2,1};
   double a[]={1,2,3,4,5,6,7,8};
   cout<<"before:"<<endl;
   int len=sizeof(a)/sizeof(double);
   cout<<"length:"<<len<<endl;
   show_array(a,len,true,0);
   int r_list[2];
   sort_bubble(a,len,r_list);
   cout<<"after:"<<endl;
   show_array(a,len,true,0);
   cout <<"diff_cnt,swap_cnt="<<r_list[0]<<","<<r_list[1]<<endl;
}

