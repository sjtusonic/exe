#include <math.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream> 
#include <sstream> 
#include <string>
#include <vector>
using namespace std;
static string legalChars="KANCEpqrst";

class WFF 
{
	public:
		WFF()         {
			WFF("");
		};
		WFF(string s) {
			//cout<<"Construct:"<<s<<"@"<<this<<endl;
			mForm=s ;
			mOp=' ';
		};
		~WFF() {
			//cout<<"Deconstruct:"<<mForm<<"@"<<this<<endl;
			for (WFF* p:mUnitWFFs)
			{
				delete p;
			}
		};
		string getMForm() {return mForm;};
		void setMForm(string s) {mForm=s;};
		bool isLegal();
		bool isLegal(int level);
		void show();
		void showMUnitWFFs(int indent=0);
		//void breakIntoUnitWFFs();
		bool calcValue(string cond)  ;
		vector<string> genTestPatterns();
	private:
		string mForm;
		char mOp;
		vector<WFF*> mUnitWFFs;
};
vector<int> findAllUpperLetterInString(string str);
vector<int> findAllMatchesInString(string str,string subStr);

//static vector<WFF> WFFs;
