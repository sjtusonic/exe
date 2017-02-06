#include "include.top.h"
#include "gnuplot_i.h"
#include "poj2632.h"
#include "MATRIX.class.h"
#include "ROBOT.class.h"
#include <math.h>
#include <iomanip>
#include <map>

#include <fstream>
using namespace std;

void poj2632 () 
{
#if 1
	cout<<"-----------------------------------------------"<<endl;
	cout<<"poj2632"<<endl;
	//----------------------------------------------------------
	string filename="input/poj2632.in";
	std::ifstream infile(filename);
	if (!infile)
		std::cerr << "Couldn't open " << filename << " for reading\n";
	//----------------------------------------------------------
	string filename_out="output/poj2632.out";
	// clean the file "output/poj2632.out"
	std::ofstream outfile_init(filename_out);
	outfile_init.close();
	std::ofstream outfile(filename_out,ios::app);
	if (!outfile)
		std::cerr << "Couldn't open " << filename_out << " for writing\n";
	//----------------------------------------------------------
	//
	std::cout << "parsing " << filename << " ...\n";

	string line;

	int cnt_line=0;
	int NUM_OF_CASES;
	int num_of_robots=0,num_of_inst;
	int cnt_robert=0;
	int cnt_do=-1;
	bool flag_robert=0,flag_do=0;
	vector<ROBOT*> list_robot;
	MATRIX<int> m(1,1);
	MATRIX<int> * board_ptr=&m;
	while(getline(infile,line))
	{
		cnt_line++;
		cout<<"-------------------------------------"<<endl;
		cout<<"LINE="<<line<<endl;
		if(cnt_line==1)
		{
			NUM_OF_CASES=stoi(line);
			PRINTVAR(NUM_OF_CASES);
		}
		if(cnt_line==2)
		{
			stringstream ssin(line);
			int width,height;
			ssin>>width>>height;
			PRINTVAR(width);
			PRINTVAR(height);
			//MATRIX<int> m(height,width,1);
			m.setWidth(width);
			m.setHeight(height);
			m.fill(1);
		}
		if(cnt_line==3)
		{
			stringstream ssin(line);
			ssin>>num_of_robots>>num_of_inst;
			PRINTVAR(num_of_robots);
			PRINTVAR(num_of_inst);
			cnt_robert=0;
		}

		if(cnt_robert!=num_of_robots && cnt_line>3)
		{
			cnt_robert++;
			cout<<"got robert "<<cnt_robert<<": "<<line<<endl;
			int t1=stoi(split(line," ")[0])-1;
			int t2=stoi(split(line," ")[1])-1;
			Point<int> p(t1,t2);
			string h=split(line," ")[2];

			ROBOT* r=new ROBOT(p,h);
			PRINT_DEBUG_INFO();
			board_ptr->show();
			PRINT_DEBUG_INFO();
			r->setBoard(board_ptr);
			list_robot.push_back(r);
			r->show();
		}
		if(cnt_robert==num_of_robots && cnt_do<0)
		{
			cnt_do=0;
		}
		if(cnt_do!=num_of_inst && cnt_line>3+num_of_robots)
		{
			cnt_do++;
			cout<<"got move "<<cnt_do<<": "<<line<<endl;
			auto iv=split(line," ");
			int robot_id=stoi(iv[0]);

			vector<string>iv2(iv.begin()+1,iv.end());
			string cmd=join(iv2);
			PRINTVAR(robot_id);
			PRINTVAR(cmd);
			list_robot[robot_id-1]->exe(cmd);
		}
		if(cnt_line>=3+num_of_robots+num_of_inst)
		{
			cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
			for(auto r:list_robot)
				r->show();
			cout<<"end of case <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
			cnt_line=1;
			cnt_do=-1;
		}
		//cout<<"LINE:"<<endl;
		//PRINTVAR(flag_end_of_one_case);
	}

// MATRIX<int> m(4,5,1);
// m.show();
// PRINTVAR(m.isOnEdge(1,2));
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
	string sss=string("  ")+">>>\t";
	int u=3;
	PRINT_DEBUG_INFO_PREFIX(u);

	//for(int cnt=0;cnt<=100;cnt++)
	//{
	//float rx=((float)(random()%100))/100;
	//float ry=((float)(random()%100))/100;
	//cout<<rx<<" "<<ry<<endl;
	//}
#endif
}
