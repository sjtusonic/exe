#include "include.top.h"
#include <math.h>
#include <iomanip>
#include <map>
#include "poj1003.h"

using namespace std;

#include <fstream>

void poj1003 () 
{
	cout<<"-----------------------------------------------"<<endl;
	cout<<"poj1003"<<endl;
	//----------------------------------------------------------
	string filename="input/poj1003.in";
	std::ifstream infile(filename);
	if (!infile)
		std::cerr << "Couldn't open " << filename << " for reading\n";

	//----------------------------------------------------------
	string filename_out="output/poj1003.out";
	std::ofstream outfile(filename_out);
	if (!outfile)
		std::cerr << "Couldn't open " << filename_out << " for writing\n";

	//----------------------------------------------------------
	std::cout << "parsing " << filename << " ...\n";

	//----------------------------------------------------------
	// GET UPBOUND FOR GENERATING map_card2length
	float upbound=-1;
	
	string line;
	while (infile >> line)
	{
		float l=stof(line);
		if (l>upbound)
			upbound=l;
	}
	cout<<"get upbound="<<upbound<<" from file:"<<filename<<endl;
	cout<<"generating map_card2length ..."<<endl;
	//----------------------------------------------------------
	// gen map_card2length and map_length2card
	
	map<int,float> map_card2length;
	gen_map_card2length(map_card2length,upbound);

	map<float,int> map_length2card;
	for(auto it:map_card2length) 
	{
		auto f=it.first;
		auto s=it.second;
		map_length2card[s]=f;
		//cout<<s<<":\t"<<f<<endl;
	}
	//----------------------------------------------------------
	// dump output file

	outfile<<"====================="<<endl;
	double result;

	// read filename for the second time, a new file_handle infile1 is needed,
	//std::ifstream infile1(filename); 
	
	// or use clear() and seekg(0) to init the file_handle again
	infile.clear(); 
	infile.seekg(0);

	while (infile >> line)
	{
		//cout<<"GOT LINE"<<line<<endl;
		float l=stof(line);
		outfile<<line;
		outfile<<":\t";
		if (l<=0)
		{
			cout<<0<<endl;
			outfile<<0<<endl;
		}
		else if (map_length2card.count(l))
		{
			cout<<map_length2card[l]<<endl;
		}
		else 
		{
			for (auto it:map_length2card)
			{
				auto f=it.first;
				if (f>l)
				{
					cout<<it.second<<endl;
					outfile<<it.second<<endl;
					break;
				}
			}
		}
	}
	outfile<<"====================="<<endl;
	//----------------------------------------------------------

	std::cout << "FINISH " << " \n";
	cout<<"-----------------------------------------------"<<endl;
}

map<int,float> gen_map_card2length(map<int,float> & map_card2length,float upbound=5.2) 
{
	map<int,float> r;
	for(int n=1;n<=1000000;n++)
	{
		float m=calc_center(n,map_card2length);
		if (n%10000==0)
			cout<<n<<":\t"<<m<<endl;
		r[n]=m;
		if (m>upbound)
			break;
	}
	return r;
}

float calc_center(float n,map<int,float> &map_card2length) 
{
	if (n==1)
	{
		map_card2length[1]=0.5;
		return 0.5;
	}
	else 
	{
		//return 0.5*(1/n)+calc_center(n-1);
		float m= 0.5*(1/n)+map_card2length[n-1];
		map_card2length[n]=m;
		return m;
	}
}
