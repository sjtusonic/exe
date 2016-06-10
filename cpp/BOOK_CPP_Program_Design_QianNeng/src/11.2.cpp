#include "include.top.h"
using namespace std;

void f11_2(){
   Cat frisky;
   frisky.SetAge(5);
   frisky.Meow();
   cout <<"cat age="
      <<frisky.GetAge()
      <<endl;
   frisky.Meow();
}
