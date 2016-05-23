#include <iostream>
#include <math.h>
#include <iomanip>
using   namespace   std; 
typedef int INT;

int main3_5 () {
   INT cnt=0;
   const int width=20;

   cout<<setw(3*width)<<setfill('-')<<" "<<endl;
   cout<<setfill(' ');
   cout<<setw(width)<<"x"
      <<setw(width)<<"%3"
      <<setw(width)<<"%5"
      <<setw(width)<<"%7"
      <<endl;
   string can_div_by_3;
   string can_div_by_5;
   string can_div_by_7;
   string tag;
   for (int x=7;x<=20;x++) {

can_div_by_3=" ";
can_div_by_5=" ";
can_div_by_7=" ";

      if (x%3==0) {can_div_by_3="3";      }
      if (x%5==0) {can_div_by_5="5";      }
      if (x%7==0) {can_div_by_7="7";      }

      if (can_div_by_3==" "
        && can_div_by_5==" "
        && can_div_by_7==" "
         ) {
         tag="X";
      } else {
         tag="";
      }

      cout
      <<setw(width)<<x
      <<setw(width)<<can_div_by_3
      <<setw(width)<<can_div_by_5
      <<setw(width)<<can_div_by_7
      <<setw(width)<<tag
      <<endl;
   }


   return 0;
}
