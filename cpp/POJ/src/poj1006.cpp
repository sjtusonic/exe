#include "include.top.h"
#include <math.h>
#include <iomanip>
#include <map>

using namespace std;

#include <fstream>

const int T_p=23;
const int T_e=28;
const int T_i=33;
void poj1006 () 
{
	cout<<"-----------------------------------------------"<<endl;
	cout<<"poj1006"<<endl;
	//----------------------------------------------------------
	string filename="input/poj1006.in";
	std::ifstream infile(filename);
	if (!infile)
		std::cerr << "Couldn't open " << filename << " for reading\n";

	//----------------------------------------------------------
	string filename_out="output/poj1006.out";
	std::ofstream outfile(filename_out);
	if (!outfile)
		std::cerr << "Couldn't open " << filename_out << " for writing\n";


	//----------------------------------------------------------
	std::cout << "parsing " << filename << " ...\n";

	//----------------------------------------------------------
	// dump output file

	outfile<<"====================="<<endl;
	double result;
	int p,e,i,d;
	int cntr_case=1;

		int common_peak=-999;
	while (infile >> p >>e >>i >>d)
	{
		if (p==-1
				&& e==-1
				&& i==-1
				&& d==-1
			)
			break;
		common_peak=calc_next_triple_peak(p,e,i,d);
		cout<<"Case "<<cntr_case<<": the next triple peak occurs in "<<common_peak<<" days."<<endl;
		outfile<<"Case "<<cntr_case<<": the next triple peak occurs in "<<common_peak<<" days."<<endl;

cntr_case++;
	}
	outfile<<"====================="<<endl;
	//----------------------------------------------------------

	std::cout << "FINISH " << " \n";
	cout<<"-----------------------------------------------"<<endl;
}

int calc_next_triple_peak (int p_last,int e_last,int i_last,int d_start) 
{
	for(int j=d_start+1;j<=d_start+T_p*T_i*T_e;j++)
	{
#if 0
		cout<<j<<":\t";
		if(is_divided(j-p_last,T_p))
			cout<<"\tp";
		if(is_divided(j-e_last,T_e))
			cout<<"\te";
		if(is_divided(j-i_last,T_i))
			cout<<"\ti";
		cout<<endl;
#endif
		if(is_divided(j-p_last,T_p))
			if(is_divided(j-e_last,T_e))
				if(is_divided(j-i_last,T_i))
				{
					//analyze_is_divided(j-p_last,T_p);
					//analyze_is_divided(j-e_last,T_e);
					//analyze_is_divided(j-i_last,T_i);
					//cout<<j<<":\t is the common peak!"<<endl;
					return j-d_start;
				}
	}
}
bool is_divided(int a,int b)
{
	return !(a%b);
}
void analyze_is_divided(int a,int b)
{
	cout<<a<<"/"<<b<<"="<<a/b<<endl;
}
