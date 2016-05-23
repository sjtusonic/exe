#include <iostream>
#include <math.h>
#include <iomanip>
using   namespace   std; 
typedef int INT;

int main3_4 () {
   INT cnt=0;
   const int width=20;

   cout<<setw(3*width)<<setfill('-')<<" "<<endl;
   cout<<setfill(' ');
   cout<<setw(width)<<"x"<<setw(width)<<"f(x)=x*(x+2)"<<endl;
   for (int x=2;x<=10;x++) {
      cout<<setw(width)<<x<<setw(width)<<x*(x+2)<<endl;
   }

   cout<<setw(3*width)<<setfill('-')<<" "<<endl;
   cout<<setfill(' ');
   cout<<setw(width)<<"x"<<setw(width)<<"f(x)=2*x"<<endl;
   for (int x=-1;x<=2;x++) {
      cout<<setw(width)<<x<<setw(width)<<x*2<<endl;
   }

   cout<<setw(3*width)<<setfill('-')<<" "<<endl;
   cout<<setfill(' ');
   cout<<setw(width)<<"x"<<setw(width)<<"f(x)=x-1"<<endl;
   for (int x=-7;x<=-1;x++) {
      cout<<setw(width)<<x<<setw(width)<<x-1<<endl;
   }

   return 0;
}
