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
#include <glob.h>

using namespace std;
#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define PRINT_ARRAY(a,len)  for(int u=0;u<len;u++) {std::cout<<u<<":\t"<<*a+u<<std::endl;}
#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<std::endl;}
#define PRINT_MAP(a)     std::cout<<#a<<":"<<std::endl;for(auto u:a) {std::cout<<u.first<<"\t->\t"<<u.second<<std::endl;}
#define PRINT_VECTOR_hor(a)  std::cout<<#a<<":";for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;


#define PRINT_POINTER1(a)  std::cout<<#a; \
	std::cout<<"\t= \t"<<a; \
std::cout<<"\t->\t"<<*a; \
std::cout<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;

#define PRINT_POINTER2(a)  std::cout<<#a; \
	std::cout<<"\t= \t"<<a; \
std::cout<<"\t->\t"<<*a; \
std::cout<<"\t->\t"<<**a; \
std::cout<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;

#define PRINT_POINTER3(a)  std::cout<<#a; \
	std::cout<<"\t= \t"<<a; \
std::cout<<"\t->\t"<<*a; \
std::cout<<"\t->\t"<<**a; \
std::cout<<"\t->\t"<<***a; \
std::cout<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;

#define PRINT_POINTER(a)  PRINT_POINTER1(a)


#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)
#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )

//inline std::vector<std::string> glob(const std::string& pat);

#include <stdio.h>  /* defines FILENAME_MAX */
// #define WINDOWS  /* uncomment this line to use it for windows.*/ 
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include<iostream>
 
std::string GetCurrentWorkingDir( void ) {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}
 
int main(){
  std::cout <<"CWD = "<< GetCurrentWorkingDir() << std::endl;
  return 1;
}
