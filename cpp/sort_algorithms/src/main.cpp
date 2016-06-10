#include <math.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "1_bubble_sort.h"
#include "lib.h"
#include <list>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

using namespace std;


int PrintIt (string& StringToPrint) {
   cout <<StringToPrint <<" ";
}
int main() {
	cout<<"Hello world!"<<endl;
   int MAX_TRY_RUN=1000;
   int LIST_LENGTH=20;
   int max_assign_cnt=0;
   int max_cmpr_cnt=0;
   //int * list_that_caused_max_assign_cnt;

   list <string> list_assign_cnt_str; 
   list <int> list_assign_cnt,list_cmpr_cnt; 
   //ms.push_back("v0");


   for (int i=0;i<MAX_TRY_RUN;i++) {
      int r_cnt[3];
      func_1_bubble_sort(r_cnt,LIST_LENGTH,i);
      int curr_cmpr_cnt=r_cnt[0];
      int curr_assign_cnt=r_cnt[1];
      //stringstream ss;
      //ss<<curr_assign_cnt;
      //string curr_assign_cnt_str=ss.str();
      list_cmpr_cnt.push_back(curr_cmpr_cnt);
      list_assign_cnt.push_back(curr_assign_cnt);

      string curr_assign_cnt_str=int2string(curr_assign_cnt);
      list_assign_cnt_str.push_back(curr_assign_cnt_str);
      if (max_assign_cnt<curr_assign_cnt ) {max_assign_cnt=curr_assign_cnt;}
      if (max_cmpr_cnt<curr_cmpr_cnt ) {max_cmpr_cnt=curr_cmpr_cnt;}
   }
   
   //int* r=gen_rand_array_int(0,3);
   //for(int i=0;i<=8;i++) {
   //   cout<<r[i]<<" ";
   //}
   //cout<<endl;
   

   for_each(list_assign_cnt_str.begin(),list_assign_cnt_str.end(),PrintIt);
   cout<<endl;
   double avg_assign_cnt=0;
   double avg_cmpr_cnt=0;
   avg_assign_cnt=std::accumulate(list_assign_cnt.begin(),list_assign_cnt.end(),0.0)/ list_assign_cnt.size();
   avg_cmpr_cnt=std::accumulate(list_cmpr_cnt.begin(),list_cmpr_cnt.end(),0.0)/ list_cmpr_cnt.size();
   cout<<"LIST_LENGTH="<<LIST_LENGTH<<endl;
   cout<<"max_cmpr_cnt="<<max_cmpr_cnt<<endl;
   cout<<"avg_cmpr_cnt="<<avg_cmpr_cnt<<endl;
   cout<<"max_assign_cnt="<<max_assign_cnt<<endl;
   cout<<"avg_assign_cnt="<<avg_assign_cnt<<endl;
	return 0; 
}





//int main (void) {
//   list <string> ms; 
//   ms.push_back("v0");
//   ms.push_back("v1");
//   for_each(ms.begin(),ms.end(),PrintIt);
//}

