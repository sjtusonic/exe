#include <iostream>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include "lib.h"

using   namespace   std; 


int main4_2 () {

   time_t timer;
   struct tm *tblock;
   timer=time(NULL);
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   ////////////////////////////////////////////////

   double sum=0;
   for (int cnt=1;cnt<=15;cnt++) {
      double incr=myfac(cnt);
      sum+=incr;
      printf("ITER:%20d \tincr:%20.0f \tsum:%20.0f\n",cnt,incr,sum);
   }

   ////////////////////////////////////////////////
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   //cout<<(int)tblock<<endl;
   return 0;
}
