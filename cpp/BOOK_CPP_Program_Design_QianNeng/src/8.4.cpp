#include "include.top.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;


void f8_4() {//FUNC
   cout<<"=================="<<endl;
   cout<<"encrypt and decrypt"<<endl;
   cout<<"=================="<<endl;
   char c[200];
   char k[20];
   strcpy(c,"the result of 3 and 2 is not 8#");
   strcpy(k,"4962873");
   //cout<<"encrypt:"<<encrypt(&c,3)<<endl;
   //int len_str=sizeof(c)/sizeof(char);
   //int len_key=sizeof(k)/sizeof(char);
   cout<<"String input:"<<c<<endl;
   cout<<"Key input   :"<<k<<endl;

   f_encrypt(c,50,k,7);
   cout<<"encrypt:"<<c<<endl;
}

void f_encrypt (char *c,int string_len,char* offset_list,int offset_list_len) {
   for (int ind_string=0;ind_string<string_len;ind_string++) {
      int ind_offset_list = ind_string%offset_list_len;
      int curr_int_key=*(offset_list+ind_offset_list)-48;
      char after=*(c+ind_string)+curr_int_key;
      while (after>122) {
         after-=122;
      }
      while (after<32) {
         after+=32;
      }
      if (*(c+ind_string)=='#') {break;}
      //printf("ind_string=%d;s=%c;ind_offset_list=%d;key=%d;after=%c\n",ind_string,*(c+ind_string),ind_offset_list,curr_int_key,after);
      printf("%3d:(%c)%4d+%d\t=\t(%c)%4d\n",ind_string,*(c+ind_string),*(c+ind_string),curr_int_key,after,after);
      *(c+ind_string)=after;
   }
}

void f_decrypt(char*c,int offset){
}
