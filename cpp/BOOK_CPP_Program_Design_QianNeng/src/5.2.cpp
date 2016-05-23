#include <stdio.h>
#include <math.h>
#include <iostream>
#include "5.1.h"
#include "lib.h"

using   namespace   std;

int f5_2 () {
   time_t timer;
   struct tm *tblock;
   timer=time(NULL);
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   ////////////////////////////////////////////////
   //cout<<integral(6,7)<<endl;
   ////////////////////////////////////////////////
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   //cout<<(int)tblock<<endl;
   return 0;
}

double target_func (double x) {
   double y=exp(x)/(1+x*x);
   return y;
}

