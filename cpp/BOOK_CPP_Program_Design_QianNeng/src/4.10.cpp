#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include "4.10.h"
#include "lib.h"

using   namespace   std;

int f4_10 (int year) {
   time_t timer;
   struct tm *tblock;
   timer=time(NULL);
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   ////////////////////////////////////////////////


   cout<<"------------------------"<<endl;
   int sum=1;
   int count_of_birthable=0;
   int sum_old1=0;
   int sum_old2=0;
   int sum_old3=0;
   int sum_old4=0;
   int sum_old5=0;
   for (int n=0;n<=year;n++) {
      //if (n>=4) {
      //   count_of_birthable=1;
      //}
      int new_birth_of_4_years_ago=sum_old4-sum_old5;
      count_of_birthable+=new_birth_of_4_years_ago;
      sum+=count_of_birthable;
      cout<<"the head of year"<<setw(4)<<n<<" sum:"<<sum<<" count_of_birthable:"<<count_of_birthable<<endl;
      cout<<setw(5)
         <<"_"<<sum
         <<"_"<<sum_old1
         <<"_"<<sum_old2
         <<"_"<<sum_old3
         <<"^"<<sum_old4
         <<"_"<<sum_old5
         <<"_"<<endl;

      sum_old5=sum_old4;
      sum_old4=sum_old3;
      sum_old3=sum_old2;
      sum_old2=sum_old1;
      sum_old1=sum;
   }

   cout<<"------------------------"<<endl;
   ////////////////////////////////////////////////
   tblock=localtime(&timer);
   cout<<asctime(tblock)<<endl;
   //cout<<(int)tblock<<endl;
   return 0;
}

