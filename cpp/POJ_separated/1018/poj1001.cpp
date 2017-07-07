#include "include.top.h"
#include <math.h>
#include <iomanip>

using namespace std;

#include <fstream>

void poj1001 () 
{
	cout<<"-----------------------------------------------"<<endl;
	cout<<"poj1001"<<endl;
	//----------------------------------------------------------
	string filename="input/poj1001.in";
	std::ifstream infile(filename);
	if (!infile)
		std::cerr << "Couldn't open " << filename << " for reading\n";

	//----------------------------------------------------------
	string filename_out="output/poj1001.out";
	std::ofstream outfile(filename_out);
	if (!outfile)
		std::cerr << "Couldn't open " << filename_out << " for writing\n";

	//----------------------------------------------------------
	std::cout << "parsing " << filename << " ...\n";

	double a, b;
	double result;
	while (infile >> a >> b)
	{
		result=pow(a,b);
		outfile<<a<<"\t^\t"<<b<<"\t=\t"<<setprecision(3000)<<result<<setprecision(10)<<endl;
	}
	std::cout << "FINISH " << " \n";
	cout<<"-----------------------------------------------"<<endl;
}
