#include <utility.h>
#include <life.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

Life::Life(int w, int h) {
   width=w;
   height=h;
   cout_table_width=3;

   origin_col=1;
   origin_row=1;

   big_col=w-1;
   big_row=h-1;

   SHOW_WIDTH=big_col-origin_col;
   SHOW_HEIGHT=big_row-origin_row;
   init();
}
void Life::make_live(int show_col, int show_row) {
   matrix[origin_col+show_col][origin_row+show_row]=1;
}
void Life::make_dead(int show_col, int show_row) {
   matrix[origin_col+show_col][origin_row+show_row]=0;
}

void Life::init() {
   cout<<"calling Life::init()"<<endl;
}
int Life::calc_neighbour_cnt (int show_col, int show_row) {
   //cout<<"calling Life::calc_neighbour_cnt("<<show_col<<","<<show_row<<")"<<endl;
   int cnt=0;
   for (int i=show_col-1;i<=show_col+1;i++){
      for (int j=show_row-1;j<=show_row+1;j++){
         if (j==show_row&&i==show_col) {continue;}
         if (matrix[origin_col+i][origin_row+j] ) {
            cnt++;
         }
      }
   }
   //cout<<"calling Life::calc_neighbour_cnt return "<<cnt<<endl;
   neighbour_cnt[origin_col+show_col][origin_row+show_row]=cnt;
   return cnt;
}
void Life::update_neighbour_cnt() {
   // calc:
   cout<<"calling Life::update_neighbour_cnt()"<<endl;
   printf("%d,%d\n",SHOW_HEIGHT,SHOW_WIDTH);
   for (int r=0;r<SHOW_HEIGHT;r++){
      for (int c=0;c<SHOW_WIDTH;c++){
         int nc=calc_neighbour_cnt(c,r);
         //cout<<"calling Life::update_neighbour_cnt ("<<c<<","<<r<<") ="<<nc<<endl;
      }
   }
   //cout<<"return of Life::update_neighbour_cnt()"<<endl;
}
void Life::update() {
   cout<<"calling Life::update()"<<endl;
   update_neighbour_cnt();
   // update live or dead:
   SHOW_WIDTH=big_col-origin_col;
   SHOW_HEIGHT=big_row-origin_row;
   for (int r=0;r<SHOW_HEIGHT;r++){
      for (int c=0;c<SHOW_WIDTH;c++){
         int curr_neighbour_cnt=neighbour_cnt[origin_col+c][origin_row+r];
         if (curr_neighbour_cnt==3) {
            make_live(c,r);
         } else if (curr_neighbour_cnt==2 && matrix[origin_col+c][origin_row+r]) {
            make_live(c,r);
         } else {
            make_dead(c,r);
         }
      }
   }
   // calc:
   for (int r=0;r<SHOW_HEIGHT;r++){
      for (int c=0;c<SHOW_WIDTH;c++){
         calc_neighbour_cnt(c,r);
      }
   }
}
void Life::show() {
   cout<<"calling Life::show()"<<endl;
   cout<<setw(cout_table_width)<<"";
   cout<<setw(cout_table_width)<<"Cl=";
   for (int i=origin_col;i<big_col;i++){
      cout<<setw(cout_table_width)<<i-1;
   }
   cout<<endl;
   for (int j=origin_row;j<big_row;j++){
      cout<<setw(cout_table_width)<<"Rw="<<setw(cout_table_width)<<j-1;
      for (int i=origin_col;i<big_col;i++){
         char c;
         if (matrix[i][j]) {
            c='*';
         } else {c=' ';}
         cout<<setw(cout_table_width)<<c;
      }
      cout<<endl;
   }
}
void Life::show_neighbour_cnt() {
   cout<<"calling Life::show_neighbour_cnt()"<<endl;
   update_neighbour_cnt();
   cout<<setw(cout_table_width)<<"";
   cout<<setw(cout_table_width)<<"Cl=";
   for (int i=-1;i<SHOW_WIDTH;i++){
      cout<<setw(cout_table_width)<<i;
   }
   cout<<endl;
   for (int j=-1;j<SHOW_HEIGHT;j++){
      cout<<setw(cout_table_width)<<"Rw="<<setw(cout_table_width)<<j;
      for (int i=-1;i<SHOW_WIDTH;i++){
         string s;
         int curr_neighbour_cnt=neighbour_cnt[origin_col+i][origin_row+j];
         if(curr_neighbour_cnt==0) {
            s="";
         } else {
            char temp[3];
            sprintf(temp,"%d",curr_neighbour_cnt);
            string s1(temp);
            s=s1.c_str();
         }
         cout<<setw(cout_table_width)<<s;
      }
      cout<<endl;
   }
}
