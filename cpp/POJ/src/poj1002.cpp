#include "include.top.h"
#include <math.h>
#include <iomanip>
#include <map>

using namespace std;

#include <fstream>

void poj1002 () 
{
	cout<<"-----------------------------------------------"<<endl;
	cout<<"poj1002"<<endl;
	//----------------------------------------------------------
	string filename="input/poj1002.in";
	std::ifstream infile(filename);
	if (!infile)
		std::cerr << "Couldn't open " << filename << " for reading\n";

	//----------------------------------------------------------
	string filename_out="output/poj1002.out";
	std::ofstream outfile(filename_out);
	if (!outfile)
		std::cerr << "Couldn't open " << filename_out << " for writing\n";

	//----------------------------------------------------------
	std::cout << "parsing " << filename << " ...\n";

	string line;
	string out;
	int line_cntr=1;
	//int total_number_cnt;

	map<string,string> map_char2digit=
	{
		{"A","2"},
		{"B","2"},
		{"C","2"},
		{"D","3"},
		{"E","3"},
		{"F","3"},
		{"G","4"},
		{"H","4"},
		{"I","4"},
		{"J","5"},
		{"K","5"},
		{"L","5"},
		{"M","6"},
		{"N","6"},
		{"O","6"},
		{"P","7"},
		{"Q","-1"},
		{"R","7"},
		{"S","7"},
		{"T","8"},
		{"U","8"},
		{"V","8"},
		{"W","9"},
		{"X","9"},
		{"Y","9"},
		{"Z","-1"}
	};
	map<string,int> map_num2freq;
	map<string,string> map_decode;

	while (infile >> line)
	{
		if(line_cntr==1)
		{
			//total_number_cnt=stoi(line);
			outfile<<"got "<<line<<" tele numbers:"<<endl;
		}
		else
		{
			outfile<<"\t"<<line<<"\t"<<"\t";
			//-------------------------------------------
			cout<<"got\tchar:";
			for(auto c:line)
			{
				if (c=='-' || c=='Q' || c== 'Z')
					continue;
				string s_tmp=string(1,c);
				cout<<s_tmp<<"\t";
				//outfile<<map_char2digit[s_tmp];
			}
			cout<<endl;
			//-------------------------------------------
			cout<<"trans\tchar:";
			string translated_number="";
			for(auto c:line)
			{
				if (c=='-' || c=='Q' || c== 'Z')
					continue;
				string s_tmp;
				if (!isdigit(c))
				{
					s_tmp=string(1,c);
					cout<<map_char2digit[s_tmp]<<"\t";
					translated_number=translated_number+map_char2digit[s_tmp];
				}
				else 
				{
					s_tmp=string(1,c);
					cout<<c<<"\t";
					translated_number=translated_number+s_tmp;
				}
			}
			PRINTVAR(translated_number);

			map_decode[line]=translated_number;

			if (!map_num2freq[translated_number])
				map_num2freq[translated_number]=1;
			else
				map_num2freq[translated_number]++;

			cout<<endl;
			//-------------------------------------------
			outfile<<endl;
		}

		++line_cntr;
	}
	outfile<<"====================="<<endl;

	bool flag_duplicate=false;
	for (auto pair:map_num2freq)
	{
		auto key=pair.first;
		auto v=pair.second;
		if (v>1)
		{
			flag_duplicate=true;
			cout<<key<<":\t"<<v;
			outfile<<key<<":\t"<<v;
			cout<<":ORIGIN NUM:";
			outfile<<":ORIGIN NUM:";
			for (auto pair2:map_decode)
			{
				auto key2=pair2.first;
				auto v2=pair2.second;
				//cout<<key<<":\t"<<v<<endl;
				if (v2==key)
				{
					cout<<":"<<key2<<"\t";
					outfile<<":"<<key2<<"\t";
				}
			}
			cout<<endl;
			outfile<<endl;
		}
	}
	if (!flag_duplicate)
		outfile<<"No duplicate"<<endl;

	outfile<<"====================="<<endl;

#if 0
	for (auto pair:map_num2freq)
	{
		auto key=pair.first;
		auto v=pair.second;
		cout<<key<<":\t"<<v<<endl;
	}

	for (auto pair:map_decode)
	{
		auto key=pair.first;
		auto v=pair.second;
		cout<<key<<":\t"<<v<<endl;
	}
#endif
	std::cout << "FINISH " << " \n";
	cout<<"-----------------------------------------------"<<endl;
}

