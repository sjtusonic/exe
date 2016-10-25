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
	cout<<"exe_3_2:"<<""<<endl;
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
	cout<<"==============="<<endl;
	cout<<"exe use reference:"<<""<<endl;
	cout<<"==============="<<endl;
	string s3="Hello world!!";
	for(auto &c:s3) {
		c=toupper(c);
	}
	PRINTVAR(s3);

	cout<<"==============="<<endl;
	cout<<"exe_3_6:"<<""<<endl;
	cout<<"==============="<<endl;
	string s6("This is 1 string!");
	PRINTVAR(s6);
	for(char &c:s6) 
	{
		if(isalpha(c)) {
			//c=toupper(c);
			c='X';
		}
	}
	PRINTVAR(s6);
	cout<<"==============="<<endl;
	cout<<"exe_3_8:"<<""<<endl;
	cout<<"==============="<<endl;
	cout<<"use while:"<<endl;
	string s8("This is 1 string!");
	PRINTVAR(s8);
	int cnt=0;
	char c;
	while(s8[cnt]) {
		//cout<<"s8[cnt]="<<s8[cnt]<<""<<endl;
		c=s8[cnt];
		if(isalpha(c)) {
			//cout<<"X"<<""<<endl;
			s8[cnt]='X';
		}
		cnt++;
	}
	PRINTVAR(s8);
	cout<<"use traditional for:"<<endl;
	string s81("This is 1 string!");
	PRINTVAR(s81);
	for(decltype(s8.size()) cnt=0;cnt<s8.size();cnt++)
	{
		//cout<<"s81[cnt]="<<s81[cnt]<<""<<endl;
		c=s81[cnt];
		if(isalpha(c)) {
			//cout<<"X"<<""<<endl;
			s81[cnt]='X';
		}
	}
	PRINTVAR(s81);

	cout<<"==============="<<endl;
	cout<<"exe_3_10:"<<""<<endl;
	cout<<"==============="<<endl;
	string s10("this is a sting, with , . ; ) and [");
	PRINTVAR(s10);
	for(char &c:s10) 
	{
		if(isalpha(c)) {
			//c=toupper(c);
			//c='X';
		} else {
			c=' ';
		}
	}
	PRINTVAR(s10);

}


