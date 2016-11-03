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
	cout<<"=============="<<""<<endl;
	cout<<"pointer of pointer"<<endl;
	int d=1;
	int* j=&d;
	int cnt=0;
	while(cnt<10)
	{
	cout<<"--------------"<<""<<endl;
		cout<<"ITER= "<<cnt<<""<<endl;
		cout<<"j= "<<j<<""<<endl;
		cout<<"sizeof(j)= "<<sizeof(j)<<""<<endl;
		j=(int*)&j;
		cnt++;
	}


   return 0; 
}
