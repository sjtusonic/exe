#include <stdio.h>
#include <math.h>
#include <iostream>
#include "4.7.h"
#include "lib.h"

using   namespace   std;

int f4_7 (double a=2) {
   time_t timer;
   struct tm *tblock;
   timer=time(NULL);
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   ////////////////////////////////////////////////
   double after=10;
   double before;
   
   for (int ans=1;ans<=10000;ans++) {
      before=after;
      after=0.5*(before+a/before);
      double diff=fabs(before-after);
      cout<<"diff="<<diff<<endl;
      if (fabs(diff)<1e-19) {
         break;
      }
   }

   cout<<a<<"^0.5="<<after<<endl;
////////////////////////////////////////////////
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   //cout<<(int)tblock<<endl;
   return 0;
} 
