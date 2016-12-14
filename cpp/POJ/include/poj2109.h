#ifndef POJ2109_H
#define POJ2109_H
#include "include.top.h"
#include "bigInt.h"
//#include "gnuplot_i.h"

typedef BigInt::Rossi R;

void poj2109();
int solve_root(R& ans,BigInt::Rossi p,int n,R p1=R(0),R p2=R(0));

R pow(int k , int n);
R pow(R   k , int n);
R pow(int k , R n);

#endif
