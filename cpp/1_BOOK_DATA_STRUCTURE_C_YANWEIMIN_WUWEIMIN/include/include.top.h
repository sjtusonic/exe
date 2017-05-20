#ifndef INCLUDE_TOP_H
#define INCLUDE_TOP_H

#define VNAME(name) (#name) // a macro that can print var out
#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;

#define PRINT_DEBUG_INFO() \
    (::std::cout<<"zjc debug: " \
    <<":\tFUNC="<<__PRETTY_FUNCTION__ \
    <<":\tFILE=" <<__FILE__<<":\tLINE=" <<__LINE__ \
    <<":\tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)

#define PRINT_DEBUG_INFO_PREFIX(p) \
    (::std::cout<<p<<"\tzjc debug: " \
    <<":\tFUNC="<<__PRETTY_FUNCTION__ \
    <<":\tFILE=" <<__FILE__<<":\tLINE=" <<__LINE__ \
    <<":\tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include <assert.h>

#include "2.1_linear_list.h"
#include "2.1_func.h"
#include "2.1_MyStack.h"
#include "2.3_link_list.h"

using namespace std;

#endif // INCLUDE_TOP_H
