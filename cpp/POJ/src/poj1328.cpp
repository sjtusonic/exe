#include "include.top.h"
#include <math.h>
#include <iomanip>
#include <map>


#include <fstream>
using namespace std;

void poj1328 () 
{
	cout<<"-----------------------------------------------"<<endl;
	cout<<"poj1328"<<endl;
	//----------------------------------------------------------
	string filename="input/poj1328.in";
	std::ifstream infile(filename);
	if (!infile)
		std::cerr << "Couldn't open " << filename << " for reading\n";

	//----------------------------------------------------------
	string filename_out="output/poj1328.out";

// clean the file "output/poj1328.out"
	std::ofstream outfile_init(filename_out);
	outfile_init.close();

	std::ofstream outfile(filename_out,ios::app);
	if (!outfile)
		std::cerr << "Couldn't open " << filename_out << " for writing\n";


	//----------------------------------------------------------
	std::cout << "parsing " << filename << " ...\n";
	float a,b;
	float x,y,r;

	int n;
	bool flag_end_of_one_case=false;
	bool flag_start_of_one_case=true;
	string line;
	//while(infile >> line)
	vector<Case> cases;
	Case c;
	Point p;
	set<Point>::iterator it;
	while(getline(infile,line))
	{
		//cout<<"LINE:"<<endl;
		PRINTVAR(line);
		PRINTVAR(flag_end_of_one_case);
		if (line == "") // end of one case
		{
			flag_end_of_one_case=true;
		}
		else
		{
			float a=stof(split(line," ")[0]);
			float b=stof(split(line," ")[1]);
			if(a==0 && b==0)// end
				break;
			if(flag_start_of_one_case)
			{
				cout<<"NEW CASE HERE!"<<endl;
				int N=a;
				float D=b;
				PRINTVAR(N);
				PRINTVAR(D);
				c.N=N;
				c.D=D;
				cases.push_back(c);
			}
			else 
			{
				// body:
				p.setLoc(a,b);

				it=cases[cases.size()-1].islands.first;

				cases[cases.size()-1].islands.insert(it,p);
			}
			if(flag_end_of_one_case)
			{
				flag_end_of_one_case=false;
			}
		}
		flag_start_of_one_case=flag_end_of_one_case;
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
}

std::vector<std::string> split(std::string str,std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	string str_bk=str,str_no_repeat_blank;
	//PRINTVAR(str);
	for (auto it=str.begin();it!=str.end();it++)
	{
		if(it!=str.begin() && *it==' ' && *(it-1)==' ')
			;
		else
			str_no_repeat_blank+=*it;
	}
	//PRINTVAR(str_no_repeat_blank);
	str=str_no_repeat_blank;
	str+=pattern;
	int size=str.size();

	for(int i=0; i<size; i++)
	{
		pos=str.find(pattern,i);
		if(pos<size)
		{
			std::string s=str.substr(i,pos-i);
			result.push_back(s);
			i=pos+pattern.size()-1;
		}
	}
	return result;
}
