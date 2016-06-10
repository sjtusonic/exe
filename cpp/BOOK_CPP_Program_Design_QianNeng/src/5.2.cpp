#include <stdio.h>
#include <math.h>
#include <iostream>
#include "5.2.h"
#include "lib.h"

using   namespace   std;

int f5_2 () {
   time_t timer;
   struct tm *tblock;
   timer=time(NULL);
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   ////////////////////////////////////////////////
   cout<<"INTEGRAL= "<<integral(0,1)<<endl;
   ////////////////////////////////////////////////
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   //cout<<(int)tblock<<endl;
   return 0;
}

double target_func (double x) {
   double y=exp(x)/(1+x*x);
   //double y=sin(x);
   return y;
}

double integral (double from,double to) {
   int n=1;
   double h=(to-from)/n;
   double t=h/2*(target_func(from)+target_func(to));
   double r=t;
   double r_next=t,t_next=t;
   while(true) {
      n*=2;
      h=(to-from)/n;
      double sigma=0;
      for (int j=0;j<=n-1;j++) {
         sigma+=target_func(from+h*j+h/2);
      }
      t_next=t/2+h/2*(sigma);
      r=r_next;
      r_next=(4*t_next-t)/3;
      cout<<"r_next="<<r_next<<endl;
      if (fabs(r_next-r)<1e-8) {break;}
   }

   return r;
}
