#ifndef LIB_CPP
#define LIB_CPP
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "lib.h"

using namespace std;

double myfac (int n) {// FUNC
   if (n<=1) {return 1;
   } else {
      double r=n*myfac(n-1);
      cout <<"myfac "<<n<<" = "<<r<<endl;
      return r;
   }
}

double calc_sum_of_power (int n,int power=3) {// FUNC
   double sum=0;
   while (n!=0) {
      int curr=n%10;
      double p=pow(curr,power);
      sum+=p;
      n=n/10;
   }
   return sum;
}

bool is_tulip (int n, int power=3) {// FUNC
   return (n==calc_sum_of_power(n,power));
}

bool is_prime (int n, int print=0) {// FUNC
   int up_bound=(int)sqrt(n);
   for (int i=2;i<=up_bound;i++) {
      if(n%i==0) {
         return false;
      }
   }
   return true;
}

bool is_full_num (int n, int print=0) {// FUNC
   //计算100000以内完数：
   //1 2 3    =6
   //1 2 4 7 14    =28
   //1 2 4 8 16 31 62 124 248    =496
   //1 2 4 8 16 32 64 127 254 508 1016 2032 4064    =8128
   int n_left=n;
   int up_bound=n-1;
   for (int i=1;i<=up_bound;i++) {

      if (n%i==0) {
         if (print==1) printf("%d ",i);
         n_left-=i;
      }
   }
   if (n_left==0 && !print) {
      is_full_num (n,1);
      return true;
   } else {
      return false;
   }
}

double calc_use_do (double x, double stop=1e-8) {// FUNC
   double r=0;
   int n=0;
   double incr;
   do {
      incr=pow(-1,n+1)*pow(x,n)/ myfac(n);
      r+=incr;
      //cout<<"ITER:"<<n<<";incr="<<incr<<";r="<<r<<endl;
      n++;
      //cout<<"fabs(incr)="<<fabs(incr)<<endl;
   } while (fabs(incr) >= stop);
   cout<<"calc_use_do return="<<r<<endl;
   return r;
}

bool is_int (double v) {// FUNC
   return ((int)v==v);
}

//double integral(double from,double to){// FUNC
//   cout<<"calc integral from: "<<from<<" to: "<<to<<endl;
//   cout<<" target func: f("<<from<<")= "<<target_func(from)
//       <<" target func: f("<<to  <<")= "<<target_func(to  )<<endl;
//   return 1.1;
//}

bool item_is_in_array (int item,int array[] ,int a_length) {// FUNC
   bool tag=false;
   for (int j=0;j<a_length;j++) {
      if (item==array[j]) {tag=true;break;}
   }
   return tag;
}

void show_array(double a[],int size,bool in_a_line=true,int num_of_marker=0, int  marker[]=0) {// FUNC
   //int size=sizeof(a)/sizeof(double);
   if (in_a_line) {
      for (int i=0;i<size;i++) {// print index line
         //cout<<"swap:"<<","<<a[i+1]endl;
         char tag;
         if (item_is_in_array(i,marker,num_of_marker)) {
            tag='M';
         }else{
            tag=' ';
         }
         printf("%9d%1c,",i,tag);
      }
      printf("\n");
      for (int i=0;i<size;i++) {// print value line
         //cout<<"swap:"<<","<<a[i+1]endl;
         printf("%10.2f,",a[i]);
      }
      printf("\n");
   } else {
      printf("--------------\n");
      printf("show array of size %d\n",size);
      for (int i=0;i<size;i++) {
         char tag;
         if (item_is_in_array(i,marker,num_of_marker)) {
            tag='M';
         }else{
            tag=' ';
         }
         //cout<<"swap:"<<","<<a[i+1]endl;
         printf("array[%5d](%10.2f)%10c\n",i,a[i],tag);
      }
      printf("--------------\n");
   }
}

void show_array(int a[],int size,bool in_a_line=true,int num_of_marker=0, int  marker[]=0) {// FUNC
   double da[size];
   for (int i=0;i<size;i++) {// convert int to double
      da[i]=(double)a[i];
   }
   show_array(da,size,in_a_line,num_of_marker,marker);
}

void show_array(bool a[],int size,bool in_a_line=true,int num_of_marker=0, int  marker[]=0) {// FUNC
   if (in_a_line) {
      for (int i=0;i<size;i++) {// print index line
         //cout<<"swap:"<<","<<a[i+1]endl;
         char tag;
         if (item_is_in_array(i,marker,num_of_marker)) {
            tag='M';
         }else{
            tag=' ';
         }
         printf("%9d%1c,",i,tag);
      }
      printf("\n");
      for (int i=0;i<size;i++) {// print value line
         //cout<<"swap:"<<","<<a[i+1]endl;
         //printf("%10.2f,",a[i]);
         if(a[i]) {printf("%10s,","A");
         } else {printf("%10s,","_");}
      }
      printf("\n");
   } else {
      printf("--------------\n");
      printf("show array of size %d\n",size);
      for (int i=0;i<size;i++) {
         char tag;
         if (item_is_in_array(i,marker,num_of_marker)) {
            tag='M';
         }else{
            tag=' ';
         }
         //cout<<"swap:"<<","<<a[i+1]endl;
         printf("array[%5d](%10.2f)%10c\n",i,a[i],tag);
      }
      printf("--------------\n");
   }
}

void sort_bubble(double a [],int size,int return_list[]) {// FUNC
   //int return_list[2];
   int swap_cnt=0;
   int diff_cnt=0;
   bool swap_tag=1;
   int pass=1;
   while (swap_tag) {
      cout<<"ITER from 0,1 to $-1,"<<size-pass<<endl;
      swap_tag=0;
      for (int i=0;i<size-pass;i++) {
         if (a[i]<a[i+1]) {
            swap_tag=1;
            //cout<<"swap:"<<","<<a[i+1]endl;
            //printf("swap a[%d](%10.2f) a[%d](%10.2f)\n",i,a[i],i+1,a[i+1]);
            int tmp[]={i,i+1};
            show_array(a,size,true,2,tmp);
            double temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            show_array(a,size,true,2,tmp);
            swap_cnt++;
         }
         diff_cnt++;
      }
      //cout<<"diff_cnt="<<diff_cnt<<endl;
      //cout<<"swap_cnt="<<swap_cnt<<endl;
      return_list[0]=diff_cnt;
      return_list[1]=swap_cnt;
      show_array(return_list,2,false);
      pass++;
   }
   //return return_list;
}

#endif
