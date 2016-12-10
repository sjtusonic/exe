#include "include.top.h"
#include <math.h>
#include <iomanip>
#include <map>
#include "poj1753.h"
#include "poj2965.h"

using namespace std;

#include <fstream>

void poj2965 () 
{
	cout<<"-----------------------------------------------"<<endl;
	cout<<"poj2965"<<endl;
	//----------------------------------------------------------
	string filename="input/poj2965.in";
	std::ifstream infile(filename);
	if (!infile)
		std::cerr << "Couldn't open " << filename << " for reading\n";

	//----------------------------------------------------------
	string filename_out="output/poj2965.out";

// clean the file "output/poj2965.out"
	std::ofstream outfile_init(filename_out);
	outfile_init.close();

	std::ofstream outfile(filename_out,ios::app);
	if (!outfile)
		std::cerr << "Couldn't open " << filename_out << " for writing\n";


	//----------------------------------------------------------
	std::cout << "parsing " << filename << " ...\n";

	//----------------------------------------------------------
	// dump output file

	outfile<<"====================="<<endl;
	GateOfRefrigerator gate_read_file("input/poj2965.in");
	cout<<"gate_read_file.show()"<<endl;
	gate_read_file.show();

	//gate_read_file.flip(1,2);
	//gate_read_file.show();

	GateOfRefrigerator gate_read_file_bk=gate_read_file;
	vector<Board> solution_tranformations;
	for(int seed0=0;seed0<pow(2,16);seed0++)
	{
		gate_read_file=gate_read_file_bk;
		Board t;
		t.deserialize(seed0);
		//PRINTVAR(seed0);
		//cout<<"before:"<<endl;
		//gate_read_file.show();
		gate_read_file.transformed_by(t);
		//cout<<"after:"<<endl;
		//gate_read_file.show();
		if (gate_read_file.isAllBlack())
		{
			solution_tranformations.push_back(t);
			std::cout << "GOT\n";
			t.show();
		}
	}
	cout<<"GOT "<<solution_tranformations.size()<<" solutions:"<<endl;
	sort(solution_tranformations.begin(),solution_tranformations.end());
	std::cout << "----------------------------------------\n";
	cout<<"solution_tranformations"<<endl;
	for (auto t:solution_tranformations)
	{
		t.show();
		cout<<"**"<<endl;
		cout<<t.sumOfTrue()<<endl;
		outfile<<t.sumOfTrue()<<endl;
		//outfile.close();
		t.showTransformationSteps(true);
		t.showTransformationSteps(true,"output/poj2965.out");

		cout<<"**"<<endl;
	}
	std::cout << "----------------------------------------\n";
	//----------------------------------------------------------
	// dump output file
	outfile<<"====================="<<endl;
	//----------------------------------------------------------


	std::cout << "FINISH " << " \n";
	cout<<"-----------------------------------------------"<<endl;
	outfile.close();
}

void GateOfRefrigerator::flip(int row,int col)
{
	//cout<<"calling GateOfRefrigerator::flip()"<<endl;
	int r,c;
	r=row;
	c=col;
	for(int r=0;r<=3;r++)
	{
		board[r][c]=!board[r][c];
	}

	r=row;
	c=col;
	for(int c=0;c<=3;c++)
	{
		board[r][c]=!board[r][c];
	}

	r=row;
	c=col;
	board[r][c]=!board[r][c];
}

