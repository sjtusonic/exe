#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include "4.10.h"
#include "5.9.h"
#include "lib.h"

using   namespace   std;

int f5_9 (int year) {
   time_t timer;
   struct tm *tblock;
   timer=time(NULL);
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   ////////////////////////////////////////////////
   for (int n=0;n<=year;n++) {
      cout<<"head of year:"<<n<<"\tsum:"<<sum(n)<<"\tsum_big:"<<sum_big(n)<<endl;
   }

   cout<<"------------------------"<<endl;
   ////////////////////////////////////////////////
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   //cout<<(int)tblock<<endl;
   return 0;
}

int sum(int n) {
   if (n==0) {
      return 1;
   } else {
      return sum(n-1)+new_born(n);
   }
}
int sum_big(int n) {
   if (n<=3) {
      return 0;
   } else {
      return sum(n-4);
   }
}

int sum_small(int n) {
   return sum(n)-sum_big(n);
}
int new_born(int n) {
   return sum_big(n);
}
