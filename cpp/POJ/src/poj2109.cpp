#include "include.top.h"
//#include "gnuplot_i.h"
#include "poj2109.h"
#include "bigInt.h"

#include <math.h>
#include <iomanip>
#include <map>

#include <fstream>
using namespace std;

#define SHOW_BIG_INT(x) cout << #x << " : Hex Value = " << x.toStr0xHex() << ", Hex Digits = " << x.getActualHexDigits() << "; Dec Value = " << x.toStrDec() << ", Dec Digits = " << x.getActualDecDigits() << std::endl << std::endl
#define SHOW_DOUBLE(x)  cout << #x << " : " << std::fixed << x << std::endl << std::endl

void poj2109 () 
{
	cout<<"-----------------------------------------------"<<endl;
	cout<<"poj2109"<<endl;
	//----------------------------------------------------------
	string filename="input/poj2109.in";
	std::ifstream infile(filename);
	if (!infile)
		std::cerr << "Couldn't open " << filename << " for reading\n";

	//----------------------------------------------------------
	string filename_out="output/poj2109.out";

	// clean the file "output/poj2109.out"
	std::ofstream outfile_init(filename_out);
	outfile_init.close();

	std::ofstream outfile(filename_out,ios::app);

	if (!outfile)
		std::cerr << "Couldn't open " << filename_out << " for writing\n";


	//----------------------------------------------------------
	std::cout << "parsing " << filename << " ...\n";

	string line;
	int n;
	string pstr;
	//long p;
	BigInt::Rossi p ("224f3e07282886cce82404b6f8", BigInt::DEC_DIGIT);
	SHOW_BIG_INT(p);
	while(infile >> n >> pstr)
	{
		cout<<"LINE-------"<<endl;
		PRINTVAR(n);
		PRINTVAR(p);

		if(n<1 || n>200 || p<1 || p>pow(10,101))
		{
			cout<<"Error: illegal inputs: "<<endl;
			PRINTVAR(n);
			PRINTVAR(p);
			break;
		}
		int ans=0;
		solve_root(ans,p,n,1,pow(10,9));
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

//--------------------------------------
// DEF
int solve_root(int &ans, long p,int n,int k1,int k2)
{
	PRINT_DEBUG_INFO();
	int k;
	int is_bigger; // -1:smaller;0=get answer;1=bigger
	if(k1==0 && k2==0)
		k=pow(10,5);
	else
		k=(int)((k1+k2)/2);
	int bound1=pow(k1,n)	;
	int bound2=pow(k2,n)	;

	PRINTVAR_hor(k1);
	PRINTVAR_hor(k2);
	PRINTVAR_hor(k);
	cout<<endl;

	if(bound1>p && bound2>p)
		return 1;
	if(bound1<p && bound2<p)
		return -1;

	int bound_mid=pow(k,n);
	if(bound_mid>p)
	{
		return solve_root(ans,p,n,k1,k);
	}
	else if(bound_mid<p)
	{
		return solve_root(ans,p,n,k,k2);
	}
	else 
	{
		ans=k;
		return 0;
	}	

}
