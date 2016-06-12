#include "utility.h"
#include <iostream>
using namespace std;
bool user_say_yes() {//FUNC
   cout<<"do you want update board?"<<endl;
   char a;
   cin>>a;
   if (a=='y' ||a=='Y') {
      return true;
   } else {
      return false;
   }
} 
