#ifndef INCLUDE_TOP_H

#define INCLUDE_TOP_H

//--------------------------------------
// macro
//--------------------------------------

#define PI 3.14159265358

#define GET_VALUE(x) (x)
#define SQUARE_VOLUME(a) (a*a*a)
#define SPHERE_VOLUME(a) (4/3*PI*a*a*a)

//--------------------------------------
// include lib files
//--------------------------------------
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream> 
#include <sstream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <assert.h>   

using namespace std;
//--------------------------------------
// include local files
//--------------------------------------
//#include "include/f13_2.h"
#include "lib.h"
#include "include.top.h"
#include "gnuplot_i.h"

#define PRINTVAR(a) cout<<#a<<"\t=\t"<<a<<endl;
#define PRINT_ARRAY(a,len)  for(int u=0;u<len;u++) {cout<<u<<":\t"<<*a+u<<endl;}
#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {cout<<*u<<endl;}
#define PRINT_VECTOR_hor(a)  for(auto u=a.begin();u!=a.end();u++) {cout<<*u<<"\t";};cout<<""<<endl;

 #define PRINT_DEBUG_INFO() \
  (::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)
//--------------------------------------

//--------------------------------------


#endif
