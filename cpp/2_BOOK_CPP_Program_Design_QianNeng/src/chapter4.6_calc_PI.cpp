#include <iostream>
#include <math.h>
#include <iomanip>
#include <time.h>
using   namespace   std; 
typedef int INT;

int f_ch4_6 () {

   time_t timer;
   struct tm *tblock;
   timer=time(NULL);
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;


   INT cnt=0;
   const int width=20;
   int i,sig;
   long double pi=0;
   long double incr;

   sig=-1;
   while (true) {
      //if (cnt>=1e6) {break;}
      //if (cnt%2==0) { sig=1;
      //} else {sig=-1;}
      sig=-sig;

      incr=(long double)sig*1/(2*cnt+1);
      //cout<<"plus 1/"<<sig*(2*cnt+1)<<" = "<<incr<<endl;
      pi+=incr;
      cnt++;
      if (fabs(incr)<1e-10) {break;}
   }
   pi*=4;
   cout<<setprecision(100)<<"PI = "<<pi<<endl;

   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   //cout<<(int)tblock<<endl;
   return 0;
}
