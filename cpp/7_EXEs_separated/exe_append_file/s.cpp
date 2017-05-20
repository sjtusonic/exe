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

inline std::vector<std::string> glob(const std::string& pat){
	using namespace std;
	glob_t glob_result;
	glob(pat.c_str(),GLOB_TILDE,NULL,&glob_result);
	vector<string> ret;
	for(unsigned int i=0;i<glob_result.gl_pathc;++i){
		ret.push_back(string(glob_result.gl_pathv[i]));
	}
	globfree(&glob_result);
	return ret;
}


int copy() {
    clock_t start, end;
    start = clock();

    ifstream source("from.ogv", ios::binary);
    ofstream dest("to.ogv", ios::binary);

    istreambuf_iterator<char> begin_source(source);
    istreambuf_iterator<char> end_source;
    ostreambuf_iterator<char> begin_dest(dest); 
    copy(begin_source, end_source, begin_dest);

    source.close();
    dest.close();

    end = clock();

    cout << "CLOCKS_PER_SEC " << CLOCKS_PER_SEC << "\n";
    cout << "CPU-TIME START " << start << "\n";
    cout << "CPU-TIME END " << end << "\n";
    cout << "CPU-TIME END - START " <<  end - start << "\n";
    cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";

    return 0;
}
int main()
{
	PRINT_DEBUG_INFO();

	std::fstream fs;
	// glob
	auto v=glob("/home/delon/workspace/exe/cpp/exe_append_file/*ist*");
	PRINT_VECTOR(v);
	PRINTVAR(v.size());
	PRINTVAR(v[0]);
	/////

	int found;
	string str=v[0];
	cout << "Splitting: " << str << endl;
	found=str.find_last_of("/\\");
	cout << " folder: " << str.substr(0,found) << endl;
	cout << " file: " << str.substr(found+1) << endl;

	/////
	// rename
	//std::string oldname="existing";
	std::string oldname=v[0];

	std::string newname="test.txt";
	int result=rename(oldname.c_str(),newname.c_str());
	assert(result==0);

	// append
	fs.open ("test.txt", std::fstream::app);
	fs << " more lorem ipsum "<<endl;

	fs.close();
	// copy
	copy();
}

