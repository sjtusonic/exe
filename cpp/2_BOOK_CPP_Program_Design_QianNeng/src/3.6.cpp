#include <iostream>
#include <math.h>
#include <iomanip>
using   namespace   std; 
typedef int INT;

int main3_6 () {
   INT cnt=0;
   const int width=20;
   int i;
   while (true) {
      cin>>i;

      if (i>100 ) {         cout<<"Error"<<endl;
      } else if (i<0 ) {    cout<<"Error"<<endl;
      } else if (i>=90 ) {  cout<<"A"<<endl;
      } else if (i>=80) {  cout<<"B"<<endl;
      } else if (i>=70) {  cout<<"C"<<endl;
      } else if (i>=60) {  cout<<"D"<<endl;
      } else if (i>=0) {  cout<<"E"<<endl;
      } else {       cout <<"Error"<<endl;}
   }

   return 0;
}
