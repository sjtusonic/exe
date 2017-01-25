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


#include "Display.class.h"
#include "Control.class.h"
#include "TetrisCalc.class.h"
#include "Matrix.class.h"

using namespace std;
//--------------------------------------
// include local files
//--------------------------------------
//#include "include/f13_2.h"
//#include "lib.h"
//#include "include.top.h"
//#include "gnuplot_i.h"

#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define PRINT_ARRAY(a,len)  for(int u=0;u<len;u++) {std::cout<<u<<":\t"<<*a+u<<std::endl;}
#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<std::endl;}
#define PRINT_VECTOR_hor(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;

#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)
//--------------------------------------

int main()
{
	PRINT_DEBUG_INFO();
	Display* d=new Display();
	d->showTitle();
	return 0;
}
