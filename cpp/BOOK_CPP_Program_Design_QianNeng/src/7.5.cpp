#include "7.5.h"
#include <iostream>
using namespace std;
void f7_5() {
   double u[10][10]={{1,2,3},{3,4,1},{9,4,2}};
   cout<<calc_diag_sum(u,3)<<endl;
}

double calc_diag_sum(double a[][10],int n) {
   double sum=0;
   for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
         cout<<a[i][j]<<"\t";
      }
      cout<<endl;
   }
   for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
         double v=a[i][j];
         if (i==j) {
            cout<<"ADD:"<<v<<endl;
            sum+=v;
         }
         if(i+j==n-1) {
            cout<<"ADD:"<<v<<endl;
            sum+=v;
         }
      }
   }
   if(n%2==1) {
      int ind=n/2;
      double repeated_value=a[ind][ind];
      cout<<"MINUS:"<<repeated_value<<endl;
      sum-=repeated_value;
   }
   return sum;
}
