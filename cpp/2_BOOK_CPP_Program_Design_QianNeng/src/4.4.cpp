#include <iostream>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include "lib.h"

using   namespace   std; 

int main4_4 () {

   time_t timer;
   struct tm *tblock;
   timer=time(NULL);
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   ////////////////////////////////////////////////
   int up_bound=100000;
   cout<<"计算"<<up_bound<<"以内完数："<<endl;
   for(int n=1;n<=up_bound;n++) {
      if (is_full_num(n)) {
         cout<<setw(4)<<"="<<n<<""<<endl;
      }
   }
   ////////////////////////////////////////////////
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   //cout<<(int)tblock<<endl;
   return 0;
}
