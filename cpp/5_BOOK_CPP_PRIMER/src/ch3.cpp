#include "include.top.h"
//using std::string;
using namespace std;
void ch3(){
	string s="hello CH3!";
	PRINTVAR(s);
	for(int i=0;i<=10;i++) {
		string s2(i,'*');
		cout<<""<<s2<<""<<endl;
	}
}
