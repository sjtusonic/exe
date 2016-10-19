#include "include.top.h"
//using namespace std;

namespace rtlgen_debug {
	
}



#define DEBUG_ECHO    1
#define DEBUG_INDENT  " > "
#define SS            rtlgen_debug::ss
#define DEBUG_PROMPT  rtlgen_debug::debug_prompt
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
	SS << msg;	\
	DEBUG_PROMPT(SS.str(), DEBUG_ECHO, enter_or_return, __FILE__, __LINE__);
#else
	#define PRINT_DEBUG_INFO(msg,enter_or_return)    
#endif

#ifdef RtlGen_DEBUG
	#define PRINT_DEBUG_cond(cond,msg,enter_or_return)    \
		if (cond) { \
			SS << msg;	\
			DEBUG_PROMPT(SS.str(), DEBUG_ECHO, enter_or_return, __FILE__, __LINE__); \
		} 
#else
	#define PRINT_DEBUG_cond(cond,msg,enter_or_return)
#endif
		
		

//\#ifdef cond \
//\#endif
	
	

int main() {
   cout<<"Hello world!"<<endl;
   //f13_2();
   //f13_3();
   //f13_6();
	
#if 1
	cout<<"1--------------------"<<""<<endl;
   SS << "AuxilarySignalGen::PipelineEnableSignalGen()";
	DEBUG_PROMPT(SS.str(), DEBUG_ECHO, "return", __FILE__, __LINE__);

	cout<<"2--------------------"<<""<<endl;
	PRINT_DEBUG_INFO("AuxilarySignalGen::PipelineEnableSignalGen()","return");
	cout<<"3--------------------"<<""<<endl;
	PRINT_DEBUG_cond(AuxilarySignalGen_DEBUG_bool,"AuxilarySignalGen::PipelineEnableSignalGen()","return");

PRINTVAR(AuxilarySignalGen_DEBUG_bool)
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
