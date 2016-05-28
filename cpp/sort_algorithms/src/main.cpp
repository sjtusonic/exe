#include <math.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "1_bubble_sort.h"
#include "lib.h"
#include <list>
#include <algorithm>
#include <string>

using namespace std;


int PrintIt (string& StringToPrint) {
   cout <<StringToPrint <<" ";
}
int main() {
	cout<<"Hello world!"<<endl;
   int MAX_TRY_RUN=200;
   int LIST_LENGTH=5;
   int max_swap_cnt=0;
   int sum_swap_cnt=0;
   double avg_swap_cnt=0;
   int * list_that_caused_max_swap_cnt;

   list <string> list_swap_cnt; 
   //ms.push_back("v0");


   for (int i=0;i<MAX_TRY_RUN;i++) {
      int curr_swap_cnt=func_1_bubble_sort(LIST_LENGTH,i);
      stringstream ss;
      ss<<curr_swap_cnt;
      string curr_swap_cnt_str=ss.str();
      list_swap_cnt.push_back(curr_swap_cnt_str);
      if (max_swap_cnt<curr_swap_cnt ) {
         max_swap_cnt=curr_swap_cnt;
      }
      cout<<"max_swap_cnt="<<max_swap_cnt<<endl;
   }
   
   //int* r=gen_rand_array_int(0,3);
   //for(int i=0;i<=8;i++) {
   //   cout<<r[i]<<" ";
   //}
   //cout<<endl;
   

   for_each(list_swap_cnt.begin(),list_swap_cnt.end(),PrintIt);
   avg_swap_cnt=std::accumulate(list_swap_cnt.begin(),list_swap_cnt.end(),0.0)/list.size();
	return 0; 
}





//int main (void) {
//   list <string> ms; 
//   ms.push_back("v0");
//   ms.push_back("v1");
//   for_each(ms.begin(),ms.end(),PrintIt);
//}

