#ifndef INCLUDE_TOP_H

#define INCLUDE_TOP_H

//--------------------------------------
// macro
//--------------------------------------

#define PI 3.14159265358

#define GET_VALUE(x) (x)
#define SQUARE_VOLUME(a) (a*a*a)
#define SPHERE_VOLUME(a) (4/3*PI*a*a*a)

#define PRINTVAR(a) cout<<#a<<"\t=\t"<<a<<endl;

//--------------------------------------
// include lib files
//--------------------------------------
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream> 
#include <string> 
#include <algorithm> 

using namespace std;
//--------------------------------------
// include local files
//--------------------------------------
//#include "include/f13_2.h"
#include "lib.h"
#include "exe_2.3.1.h"
#include "include.top.h"

//--------------------------------------


#endif