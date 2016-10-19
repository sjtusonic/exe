#include "include.top.h"
using namespace std;
using std::string;

string choose_larger_string(string s1,string s2) {
	return s1>s2?s1:s2;
}

string choose_longer_string(string s1,string s2) {
	return s1.length()>s2.length()?s1:s2;
}

void exe_3_2() {
#if 0
	cout<<"==============="<<endl;
	cout<<"exe_3_2:"<<<<""<<endl;
	cout<<"==============="<<endl;
	cout<<"read line;"<<endl;
	string s;
	getline(cin,s);
	PRINTVAR(s);
	cout<<"read words;"<<endl;
	string word;
	while(cin>>word) {
		cout<<"word:"<<word<<""<<endl;
	}
#endif
	cout<<"==============="<<endl;
	cout<<"exe_3_4:"<<""<<endl;
	cout<<"==============="<<endl;
	string s1("abcde"),s2("wxyz");
	cout<<"larger="<<choose_larger_string(s1,s2)<<""<<endl;
	cout<<"longer="<<choose_longer_string(s1,s2)<<""<<endl;

	for(auto c:s1) {
		cout<<"ITER: "<<c<<""<<endl;
	}
}


