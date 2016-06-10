#include "8.2.h"
#include "include.top.h"
#include <iostream>
using namespace std;


void f8_2() {//FUNC
   cout<<"=================="<<endl;
   cout<<"Joseph Game"<<endl;
   cout<<"=================="<<endl;
   int N;
   do {
      N=10;
      cout<<"please enter num of children(10):"<<endl;
      cin>>N;
      //cout<<"GET strN="<<strN<<endl;
      cout<<"GET N="<<N<<endl;
   } while(N<1);

   int D;
   do {
      D=3;
      cout<<"please enter distance of count(3):"<<endl;
      cin>>D;
      cout<<"GET D="<<D<<endl;
   } while(D<1 || D>N);

   bool * array;
   if((array=new bool[N])==NULL) {
      cout<<"can't allocate more mem, terminating.\n";
      exit(1);
   }
   //cout<<"TRUE:"<<(double)true<<endl;
   //cout<<"FALSE:"<<(double)false<<endl;

   for (int i=0;i<N;i++) {
      array[i]=true;
   }
   //show_array(array,N) ;

   int curr_loc=0;
   //int*mark_loc_list=&curr_loc;
   int curr_num=1;
   int alive_cnt=N;
   int ITER_CNT=0;
   int next_loc=-1;
   int next_num=-1;
   do {
      bool flag_die=false;
      // update loc:
      if (curr_loc==N-1) {
         next_loc=0;
      } else {
         next_loc=curr_loc+1;
      }
      // update num:
      if (array[curr_loc]==true) {
         next_num=curr_num+1;
         // update living status:
         if(curr_num==D) {
            next_num=1;
            array[curr_loc]=false;
            alive_cnt--;
            flag_die=true;
         }
      } else {
         next_num=curr_num;
      }

      // show:
      //cout<<curr_num<<"!"<<endl;
      //// update alive
      //if(curr_num==D) {
      //   curr_num=1;
      //   array[curr_loc]=false;
      //   alive_cnt--;
      //}
      //// show:
      if (array[curr_loc]==true || flag_die) {
         cout<<"========================"<<endl;
         cout<<"curr_loc:"<<curr_loc<<" curr_num:"<<curr_num<<endl;
         //cout<<"curr_loc:"<<curr_loc<<" DEAD"<<endl;
         show_array(array,N,true,1,&curr_loc) ;
         cout<<alive_cnt<<" alive"<<endl;
         cout<<"========================"<<endl;
      }
      ITER_CNT++;
      curr_loc=next_loc;
      curr_num=next_num;
   } while (alive_cnt>=D && ITER_CNT<100);

   delete [] array;
}
