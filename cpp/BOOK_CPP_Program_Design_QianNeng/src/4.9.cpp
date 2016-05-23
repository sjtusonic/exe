#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include "4.9.h"
#include "lib.h"

using   namespace   std;

int f4_9 () {
   time_t timer;
   struct tm *tblock;
   timer=time(NULL);
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   ////////////////////////////////////////////////

   
   cout<<"------------------------"<<endl;
   for (int i=1;i<=9;i++) {
      for (int j=1;j<=9;j++) {
         cout<<setw(4)<<i*j;
         //cout<<i*j;
      }
      cout<<endl;
   }

   cout<<"------------------------"<<endl;
   for (int i=1;i<=9;i++) {
      for (int j=1;j<=9;j++) {
         if (i>=j) {
            cout<<setw(4)<<i*j;
         }
         //cout<<i*j;
      }
      cout<<endl;
   }

   cout<<"------------------------"<<endl;
   for (int i=1;i<=9;i++) {
      for (int j=1;j<=9;j++) {
         if (i<=j) {
            cout<<setw(4)<<i*j;
         } else {
            cout<<setw(4)<<"";
         }
         //cout<<i*j;
      }
      cout<<endl;
   }
   ////////////////////////////////////////////////
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   //cout<<(int)tblock<<endl;
   return 0;
}

