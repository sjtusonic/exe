#include <iostream>
#include "5.6.h"
using namespace std;

void f5_6() {
   for (int ni=0; ni<10;ni++) {
      cout<<"===================="<<endl;
      for (int xi=0;xi<5;xi++) {
         double n=(double)ni;
         double x=(double)xi;
         cout<<"POLY("<<ni<<","<<xi<<") ="<<poly(n,x)<<endl;
      }
   }
}

double poly(double n, double x) {
   if(n==0) {
      return 1.0;
   } else if(n==1) {
      return x;
   } else {
      return ((2*n-1)*x*poly(n-1,x)-(n-1)*poly(n-2,x))/n;
   }
}
