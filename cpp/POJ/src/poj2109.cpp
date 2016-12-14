#include "include.top.h"
//#include "gnuplot_i.h"
#include "poj2109.h"
#include "bigInt.h"

#include <math.h>
#include <iomanip>
#include <map>

#include <fstream>
using namespace std;

//typedef BigInt::Rossi R;
#define SHOW_BIG_INT(x) cout << #x << " : Hex Value = " << x.toStr0xHex() << ", Hex Digits = " << x.getActualHexDigits() << "; Dec Value = " << x.toStrDec() << ", Dec Digits = " << x.getActualDecDigits() << std::endl << std::endl
#define SHOW_DOUBLE(x)  cout << #x << " : " << std::fixed << x << std::endl << std::endl


#define PRINTVAR_BIG(a) cout<<#a<<"\t=\t"<<a.toStrDec()<<endl;
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

	std::ostream& o_stream=std::cout;
	SET_START_TEST_NAME(o_stream);
	string line;
	int N;
	string pstr;
	R p("4357186184021382204544", BigInt::DEC_DIGIT);

	while(infile >> N >> pstr)
	{
		cout<<"LINE-------"<<endl;
		PRINTVAR(N);
		PRINTVAR(pstr);
		p=R(pstr,BigInt::DEC_DIGIT);
		//SHOW_BIG_INT(p);
		PRINTVAR(p);

		R p_down_limit=R("1",BigInt::DEC_DIGIT);
		R p_up_limit  =R::pow(R("10",BigInt::DEC_DIGIT),R(101));

		if(N<1 || N>200 || p<p_down_limit || p>p_up_limit)
		{
			cout<<"Error: illegal inputs: "<<endl;
			PRINTVAR(N);
			PRINTVAR(p);
			break;
		}
		R ans=R(0);
		auto r=solve_root(ans,p,N,R(1),pow(10,9));
		PRINTVAR(ans);
		if (r!=0)
			break;

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
int solve_root(R &ans, R p,int N,R k1,R k2)
{
#if 1
	//PRINT_DEBUG_INFO();
	//PRINTVAR(p);
	R k_mid;
	int is_bigger; // -1:smaller;0=get answer;1=bigger
	if(k1==R(0) && k2==R(0))
	{
		k2=R(1);
		R t=R(0);
		while(t<pow(10,5))
		{
			k2++;
			t=pow(k2,N);
		}
		cout<<"GOT k2="<<k2<<endl;
	}

	k_mid=((k1+k2)/R(2));

	//PRINTVAR_hor(k1);
	//PRINTVAR_hor(k2);
	//PRINTVAR_hor(k_mid);
	//cout<<endl;

	R bound1=pow(k1,N);
	R bound2=pow(k2,N);


	//PRINTVAR(bound1);
	//PRINTVAR(bound2);
	if(bound1>p && bound2>p)
		return 1;
	if(bound1<p && bound2<p)
		return -1;

	R bound_mid=pow(k_mid,N);
	//PRINTVAR(bound_mid);
	if(bound_mid>p)
	{
		//cout<<"go smaller"<<endl;
		return solve_root(ans,p,N,k1,k_mid);
	}
	else if(bound_mid<p)
	{
		//cout<<"go larger"<<endl;
		return solve_root(ans,p,N,k_mid,k2);
	}
	else 
	{
		//cout<<"SOLVED!"<<endl;
		ans=k_mid;
		return 0;
	}

#endif
}

R pow(int k , int n)
{
	return R::pow(R(k),R(n));
}

R pow(R   k , int n)
{
	return R::pow(k,R(n));
}
R pow(int k , R n)
{
	return R::pow(R(k),n);
}
