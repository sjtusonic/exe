#include <iostream>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include "lib.h"

using   namespace   std; 

int main4_3 () {

   time_t timer;
   struct tm *tblock;
   timer=time(NULL);
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   ////////////////////////////////////////////////
   for (int cnt=0;cnt<=1e4;cnt++) {
      if (is_tulip(cnt,3)) {
         cout<<cnt<<endl;
      }
   }
   ////////////////////////////////////////////////
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   //cout<<(int)tblock<<endl;
   return 0;
}
