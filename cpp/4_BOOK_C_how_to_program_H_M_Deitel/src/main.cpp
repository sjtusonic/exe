#include "include.top.h"
//using namespace std;


using std::string;
using std::stringstream;
namespace rtlgen_debug {
	extern stringstream ss;

	extern string debug_prompt(string info,
			bool echo = 1,
			string mode = "",
			string file = "",
			int line = -1,
			int adjust_indent = 0);

}


#define DEBUG_ECHO    1
#define DEBUG_INDENT  " > "
#define SS 				 rtlgen_debug::ss
#define DEBUG_PROMPT_old  rtlgen_debug::debug_prompt
#define DEBUG_STACK   rtlgen_debug::print_stack

	
#define RtlGen_DEBUG
#define AuxilarySignalGen_DEBUG

#ifdef AuxilarySignalGen_DEBUG
	#define AuxilarySignalGen_DEBUG_bool 1
#else
	#define AuxilarySignalGen_DEBUG_bool 0
#endif

#ifdef RtlGen_DEBUG 
	#define PRINT_DEBUG_INFO(msg,enter_or_return)    \
	SS.str(""); \
	SS << msg;	\
	DEBUG_PROMPT_old(SS.str(), DEBUG_ECHO, enter_or_return, __FILE__, __LINE__);
#else
	#define PRINT_DEBUG_INFO(msg,enter_or_return)    
#endif

#ifdef RtlGen_DEBUG
	#define PRINT_DEBUG_cond(cond,msg,enter_or_return)    \
		if (cond) { \
	SS.str(""); \
			SS << msg;	\
			DEBUG_PROMPT_old(SS.str(), DEBUG_ECHO, enter_or_return, __FILE__, __LINE__); \
		} 
#else
	#define PRINT_DEBUG_cond(cond,msg,enter_or_return)
#endif
		
#ifdef RtlGen_DEBUG
	#define DEBUG_PROMPT_new(cond_def,msg,enter_or_return)    \
		if (cond_def##_bool) { \
	SS.str(""); \
			SS << msg;	\
			SS <<__FUNCTION__; \
			SS <<"()"; \
			DEBUG_PROMPT_old(SS.str(), DEBUG_ECHO, enter_or_return, __FILE__, __LINE__); \
		} 
#else
	#define DEBUG_PROMPT_new(cond_def,msg,enter_or_return)
#endif
		
//-----------------------------------------------
#define macro1
#define macro2
#ifdef RtlGen_DEBUG 
vector<bool> macro_is_set() 
{
	vector<bool> r;
#ifdef macro1
	r.push_back(1);
#else
	r.push_back(0);
#endif
#ifdef macro2
	r.push_back(1);
#else
	r.push_back(0);
#endif
	//cout<<"r size="<<r.size()<<""<<endl;
	return r;
}
#else
inline vector<bool> macro_is_set() {}
#endif
//-----------------------------------------------

//-----------------------------------------------
// define in define : wrong
# if 0
#define apply_bool() \
	bool macro_value_bool 1
#endif
//-----------------------------------------------
//-----------------------------------------------
// recur define
#define set_recur1(M1,...) \
	cout<<"set1 "<<M1<<""<<endl; \
	set_recur2(__VA_ARGS__) \

#define set_recur2(M1,...) \
	cout<<"set2 "<<M1<<""<<endl; \
	set_recur1(__VA_ARGS__) \
//-----------------------------------------------



//\#ifdef cond \
//\#endif
	
stringstream rtlgen_debug::ss;

string rtlgen_debug::debug_prompt(string info,
		bool echo,
		string mode,
		string file,
		int line,
		int adjust_indent)
{
	cout<<"calling rtlgen_debug::debug_prompt"<<""<<endl;
	PRINTVAR(info);
	PRINTVAR(echo);
	PRINTVAR(mode);
	PRINTVAR(file);
	PRINTVAR(line);
	PRINTVAR(adjust_indent);
	return "";
}


	

int main() {
   cout<<"Hello world!"<<endl;
   //f13_2();
   //f13_3();
	//f13_6();

#if 1
	cout<<"1--------------------"<<""<<endl;
	SS << "AuxilarySignalGen::PipelineEnableSignalGen()";
	DEBUG_PROMPT_old(SS.str(), DEBUG_ECHO, "return", __FILE__, __LINE__);

	cout<<"2--------------------"<<""<<endl;
	PRINT_DEBUG_INFO("AuxilarySignalGen::PipelineEnableSignalGen()","return");
	cout<<"3--------------------"<<""<<endl;
	PRINT_DEBUG_cond(AuxilarySignalGen_DEBUG_bool,"AuxilarySignalGen::PipelineEnableSignalGen()","return");
	cout<<"4--------------------"<<""<<endl;
	//DEBUG_PROMPT_new(AuxilarySignalGen_DEBUG,"AuxilarySignalGen::PipelineEnableSignalGen()","return");

	DEBUG_PROMPT_new(AuxilarySignalGen_DEBUG,"","return");

	vector<bool> r=macro_is_set();
	cout<<"r size="<<r.size()<<""<<endl;
	for(auto i:r)
	{
		cout<<"ITER:"<<i<<""<<endl;
	}

	PRINTVAR(AuxilarySignalGen_DEBUG_bool)

	cout<<"end--------------------"<<""<<endl;
	set_recur1(1,2,3,4);

#endif

#if 0
	int x[10]     ;
	int y[10][10] ;
	cout<<"x:"<<x[3]<<""<<endl;
	cout<<"y:"<<y[3][0]<<""<<endl;
	cout<<"y count:"<<y.count()<<""<<endl;
#endif

   return 0; 
}
