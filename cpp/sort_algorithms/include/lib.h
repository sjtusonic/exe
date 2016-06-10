#ifndef LIB_CPP
#define LIB_CPP
#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <list>
#include <algorithm>

double myfac (int n) ;
double calc_sum_of_power (int n,int power=3) ;
bool is_tulip (int n, int power=3) ;
bool is_prime (int n, int print=0) ;
bool is_full_num (int n, int print=0) ;
double calc_use_do (double x, double stop=1e-8) ;
bool is_int (double v) ;
//double integral(double from,double to);
bool item_is_in_array (int i,int a[] ,int a_length) ;
void show_array(double a[],int size,bool in_a_line=true,int num_of_marker=0, int  marker[]=0) ;
void show_array(int    a[],int size,bool in_a_line=true,int num_of_marker=0, int  marker[]=0) ;
void sort_bubble(int return_list[],double a [],int size) ;
int* gen_rand_array_int (int from,int to,int seed_incr) ;
int* gen_rand_array_int (int from,int to) ;
std::string int2string(int n);
#endif
