#include "include.top.h"
using namespace std;

#include <fstream>

void poj1000 () 
{
	cout<<"-----------------------------------------------"<<endl;
	cout<<"poj1000"<<endl;
	//----------------------------------------------------------
	string filename="input/poj1000.in";
	std::ifstream infile(filename);
	if (!infile)
		std::cerr << "Couldn't open " << filename << " for reading\n";

	//----------------------------------------------------------
	string filename_out="output/poj1000.out";
	std::ofstream outfile(filename_out);
	if (!outfile)
		std::cerr << "Couldn't open " << filename_out << " for writing\n";

	//----------------------------------------------------------
	std::cout << "parsing " << filename << " ...\n";

	int a, b;
	int sum;
	while (infile >> a >> b)
	{
		sum=a+b;
		//cout<<"sum="<<sum<<endl;
		outfile<<a<<"\t+\t"<<b<<"\t=\t"<<sum<<endl;
	}
	std::cout << "FINISH " << " \n";
	cout<<"-----------------------------------------------"<<endl;
}
