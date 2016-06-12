#include <stdio.h>
#include <math.h>
#include <iostream>
#include "4.8.h"
#include "lib.h"

using   namespace   std;

int f4_8 () {
   time_t timer;
   struct tm *tblock;
   timer=time(NULL);
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   ////////////////////////////////////////////////


   int width=40;
   for (int i=0;i<=width/2;i+=2) {
      print_font_in_the_mid(width,i+1,'#');
   }

   cout<<endl;
   cout<<endl;
   width=40;
   for (int i=15;i>=8;i-=1) {
      print_font_in_the_mid(width,i+1,'x');
   }
   ////////////////////////////////////////////////
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   //cout<<(int)tblock<<endl;
   return 0;
}

void print_font_in_the_mid(int line_width, int c_cnt, char c) {
   int mid=line_width/2;
   int begin=mid-1*c_cnt+1;
   for (int i=0;i<=begin;i++) {
      cout<<" ";
   }
   for (int i=0;i<c_cnt;i++) {
      cout<<c<<" ";
   }
   cout<<endl;
}
