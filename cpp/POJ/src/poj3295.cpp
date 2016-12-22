#include "include.top.h"
#include "gnuplot_i.h"
#include "poj3295.h"
#include "WFF.class.h"
#include <math.h>
#include <iomanip>
#include <map>

#include <fstream>
using namespace std;

void poj3295 () 
{
#if 1
	cout<<"-----------------------------------------------"<<endl;
	cout<<"poj3295"<<endl;
	//----------------------------------------------------------
	string filename="input/poj3295.in";
	std::ifstream infile(filename);
	if (!infile)
		std::cerr << "Couldn't open " << filename << " for reading\n";
	//----------------------------------------------------------
	string filename_out="output/poj3295.out";
	// clean the file "output/poj3295.out"
	std::ofstream outfile_init(filename_out);
	outfile_init.close();
	std::ofstream outfile(filename_out,ios::app);
	if (!outfile)
		std::cerr << "Couldn't open " << filename_out << " for writing\n";
	//----------------------------------------------------------
	std::cout << "parsing " << filename << " ...\n";

	string line;

	while(getline(infile,line))
	{
		cout<<"-------------------------------------"<<endl;
		//cout<<"LINE:"<<endl;
		//PRINTVAR(flag_end_of_one_case);
		if (line == "0") // end of one case
		{
			break;
		}
		else
		{
			PRINTVAR(line);
			WFF w(line);
			w.show();
			assert(w.isLegal());
			//cout<<"w_breakIntoUnitWFFs"<<endl;
			//w.breakIntoUnitWFFs();
			
			cout<<"w_showMUnitWFFs---------------------------"<<endl;
			//PRINT_DEBUG_INFO();
			w.showMUnitWFFs();
			auto patterns=w.genTestPatterns();
			vector<bool> values;
			cout<<"----------------"<<endl;
			cout<<"TRUTH TABLE:"<<endl;
			for(auto p:patterns)
			{
				bool v=w.calcValue(p);
				cout<<v<<":\t"<<p<<endl;;
				values.push_back(v);
			}
			cout<<"----------------"<<endl;
			bool flag_all1=true,flag_all0=true;
			for(auto v:values)
			{
				if(v==true)
					flag_all0=false;
				if(v==false)
					flag_all1=false;
			}
			if(flag_all1)
				cout<<"Tautology:\t"<<w.getMForm()<<endl;
			else if(flag_all0)
				cout<<"Inv-Tautology:\t"<<w.getMForm()<<endl;
			else
				cout<<"Non-Tautology:\t"<<w.getMForm()<<endl;
		}
	}

	//----------------------------------------------------------
	// dump output file

	outfile<<"====================="<<endl;
	//----------------------------------------------------------
	// dump output file
	outfile<<"====================="<<endl;
	//----------------------------------------------------------


	std::cout << "FINISH " << " \n";
	cout<<"-----------------------------------------------"<<endl;
	outfile.close();

	//for(int cnt=0;cnt<=100;cnt++)
	//{
	//float rx=((float)(random()%100))/100;
	//float ry=((float)(random()%100))/100;
	//cout<<rx<<" "<<ry<<endl;
	//}
#endif
}
