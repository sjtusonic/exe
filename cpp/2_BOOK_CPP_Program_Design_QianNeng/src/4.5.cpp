#include <stdio.h>
#include <iostream>
#include "4.5.h"
#include "lib.h"

using   namespace   std;

int f4_5 () {
   time_t timer;
   struct tm *tblock;
   timer=time(NULL);
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   ////////////////////////////////////////////////
   int start_point=100;
   int up_bound=20;
   double h=start_point,sum=0;
   int cnt_hit_gnd=0;
   cout<<"计算"<<up_bound<<"次自由落体反弹："<<endl;
   for(int n=0;n<=up_bound;n++) {
      cnt_hit_gnd=n+1;
      double incr;
      if(n==0) {
         incr=h;
      } else {
         incr=h*2;
      }
      sum+=incr;
      printf("hit gnd:%d times, incr:%f, total:%f\n",cnt_hit_gnd,incr,sum);
      h=h/2;
   }
   ////////////////////////////////////////////////
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   //cout<<(int)tblock<<endl;
   return 0;
} 
