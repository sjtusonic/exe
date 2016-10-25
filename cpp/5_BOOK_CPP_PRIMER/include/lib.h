#include <math.h>
#include <stdio.h>
#include "include.top.h"

#define PRINT_DEBUG_INFO() \
	(std::cout<<"DEBUG: FILE=" <<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<" compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<std::endl)

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
void show_array(bool   a[],int size,bool in_a_line=true,int num_of_marker=0, int  marker[]=0) ;
void sort_bubble(double a [],int size,int return_list[]) ;
void sort_bubble(double a [],int size,int return_list[]) ;
std::string dec2bin(int n);
std::string stringToUpper(std::string s);
