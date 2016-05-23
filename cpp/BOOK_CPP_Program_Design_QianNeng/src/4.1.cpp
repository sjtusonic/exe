#include <iostream>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include "lib.h"

using   namespace   std; 
int main4_1 () {

   time_t timer;
   struct tm *tblock;
   timer=time(NULL);
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;


   double now  =calc_use_do (1,1e-8);
   double ideal=calc_use_do (1,1e-14);
   double diff=ideal-now;
   
   cout<<ideal<<endl;
   printf("%e = %e - %e \n",diff,ideal,now);

   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   //cout<<(int)tblock<<endl;
   return 0;
}
