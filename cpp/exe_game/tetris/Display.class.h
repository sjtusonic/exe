//--------------------------------------
// include lib files
//--------------------------------------
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

#include "Matrix.class.h"

using namespace std;
class Display {
	public:
		Display(){
		};
		~Display(){
		};
		void clear() {system("clear");};
		void showTitle(){
			//clear();
			cout<<""<<""<<endl;
			cout<<""<<""<<endl;
			cout<<""<<""<<endl;
			cout<<"========================================================================================================================="<<""<<endl;
			cout<<"\t\t\tTetrix\t\t\t"<<""<<endl;
			cout<<"========================================================================================================================="<<""<<endl;
			cout<<""<<""<<endl;
			cout<<""<<""<<endl;
			cout<<""<<""<<endl;
			PRINT_DEBUG_INFO();
		};
		//void showBoard(Matrix* m){
		//m->show(1);
		//};
		void show(bool compacted=1);
		void show(int markRow,int markCol, string marker="X");
		Matrix* m;
	private:
};
