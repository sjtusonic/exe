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
			clear();
			cout<<""<<""<<endl;
			cout<<""<<""<<endl;
			cout<<""<<""<<endl;
			cout<<"========================================================================================================================="<<""<<endl;
			cout<<"\t\t\tTetrix\t\t\t"<<""<<endl;
			cout<<"========================================================================================================================="<<""<<endl;
			cout<<""<<""<<endl;
			cout<<""<<""<<endl;
			cout<<""<<""<<endl;
		};
		void showBoard(Matrix* m){
			m->show(1);
		};
	private:
};
