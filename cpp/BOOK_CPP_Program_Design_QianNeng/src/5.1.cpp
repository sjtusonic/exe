#include <stdio.h>
#include <math.h>
#include <iostream>
#include "5.1.h"
#include "lib.h"

using   namespace   std;

int f5_1 () {
   time_t timer;
   struct tm *tblock;
   timer=time(NULL);
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   ////////////////////////////////////////////////
   cout<<is_prime(6)<<endl;
   ////////////////////////////////////////////////
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   //cout<<(int)tblock<<endl;
   return 0;
}

