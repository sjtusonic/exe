#include "include.top.h"
//using namespace std;

string reverse_str(string str) {
	reverse(str.begin(),str.end());
# if 0
	string sss;
	for(auto c:str) {
		PRINTVAR(c);
		sss.push_back(c);
	}
#endif

	return str;
}
string exe1 (string str) {
	PRINTVAR(str)
	string newstr=reverse_str(str);
	PRINTVAR(newstr)
	return newstr;
}

int main() {
	exe1("Hello!");

   return 0; 
}
