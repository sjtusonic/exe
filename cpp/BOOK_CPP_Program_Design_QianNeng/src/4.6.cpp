#include <stdio.h>
#include <iostream>
#include "4.6.h"
#include "lib.h"

using   namespace   std;

int f4_6 () {
   time_t timer;
   struct tm *tblock;
   timer=time(NULL);
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   ////////////////////////////////////////////////
   for (int ans=1;ans<=10000;ans++) {
      double left=ans;
      for (int day=1;day<=10;day++) {
         //cout<<"DAY "<<day<<"morning, peach left="<<left<<endl;
         if (left==1 && day==10) {
            cout <<"GET ANSWER: "<<ans<<"----------------"<<endl;
            break;
         }
         left=left/2-1;
         //cout<<"DAY "<<day<<"night,   peach left="<<left<<endl;
         if(left<0) {
            //cout<<"got negative, break:"<<left<<endl;
            break;
         }
         if(!is_int(left)) {
            //cout<<"got non int, break:"<<left<<endl;
            break;
         }
      }
   }
////////////////////////////////////////////////
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   //cout<<(int)tblock<<endl;
   return 0;
} 
