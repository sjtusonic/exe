#include "include.top.h"
#include "gnuplot_i.h"
#include "poj1328.h"

#include <math.h>
#include <iomanip>
#include <map>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)
	#include <conio.h>   //for getch(), needed in wait_for_key()
	#include <windows.h> //for Sleep()
	void sleep(int i) { Sleep(i*1000); }
#endif


#define SLEEP_LGTH 2  // sleep time in seconds

//#include <boost/chrono/chrono_io.hpp>
//#include <boost/chrono/floor.hpp>
//#include <boost/chrono/round.hpp>
//#include <boost/chrono/ceil.hpp>

//using namespace boost;

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
	float D;
	while(getline(infile,line))
	{
		//cout<<"LINE:"<<endl;
		PRINTVAR(line);
		//PRINTVAR(flag_end_of_one_case);
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
				D=b;
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
				float d=cases[cases.size()-1].D;
				p.setD(d);

				cases[cases.size()-1].islands.push_back(p);
			}
			if(flag_end_of_one_case)
			{
				flag_end_of_one_case=false;
			}
		}
		flag_start_of_one_case=flag_end_of_one_case;
	}

	for (auto c:cases)
		c.show();


	for (auto c:cases)
	{
		//if(!c.checkLegality())
		//{
		//	std::cout << "Error: illegal! " << " \n";
		//	return;
		//}
		assert(c.checkLegality());
		c.solve();
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
void Case::show() {
	cout<<"case.show()"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	PRINTVAR(N);
	PRINTVAR(D);
	cout<<"islands:"<<endl;;
	for (auto i:islands)
		i.show();
	cout<<"radars:"<<endl;;
	for (auto i:radars)
	{
		i.show();
	}
	cout<<"-----------------------------------------------"<<endl;
};
void Case::solve() {

	PRINT_DEBUG_INFO();
	cout<<"get covers:"<<endl;
	for(Point i:islands)
	{
		auto c=i.getXCover(D);
		covers.push_back(c);
		i.show();
		cout<<"\tcover: ("<<c.first<<",\t"<<c.second<<")"<<endl;
	}

	//::show(covers);

	vector<Point> islands_left=islands;
	while (islands_left.size()!=0) {
		//----------------------
		// update covers_left
		vector<pair<float,float>> covers_left;
		for(Point i:islands_left)
		{
			auto c=i.getXCover(D);
			covers_left.push_back(c);
		}
		PRINTVAR(covers_left.size());
		//----------------------
		// gen xAxis
		multimap<PointOnXAxis,int> xAxis;
		for(auto c:covers_left)
		{
			PointOnXAxis leftBoard(c.first);

			PointOnXAxis rightBoard(c.second);
			leftBoard.isLeftBoardOfCoverage=true;
			rightBoard.isLeftBoardOfCoverage=false;
			xAxis.insert(pair<PointOnXAxis,int>(leftBoard,0));
			xAxis.insert(pair<PointOnXAxis,int>(rightBoard,0));
		}
		//----------------------
		cout<<"***************************************"<<endl;
		cout<<"SHOW xAxis:"<<endl;
		cout <<"cntr\tisLeftBoardOfCoverage\tPointOnXAxis"<<endl;
		int cntr=0;

		for(auto x:xAxis)
		{
			PointOnXAxis f=x.first;
			if (f.isLeftBoardOfCoverage)
				cntr++;
			else 
				cntr--;
			x.second=cntr;
			cout
				<<x.second <<":\t"
				<<f.isLeftBoardOfCoverage <<":\t"
				<<f<<":\t"
				<<"\n";
		}
		//----------------------
		cout<<"***************************************"<<endl;
		cout<<"find peak point on xAxis(PPOX):"<<endl;
		cntr=0;
		int cntr_max=0;
		PointOnXAxis peak_point;
		for(auto x:xAxis)
		{
			PointOnXAxis f=x.first;
			if (f.isLeftBoardOfCoverage)
				cntr++;
			else 
				cntr--;
			if(cntr>cntr_max)
			{
				cntr_max=cntr;
				peak_point=f;
			}
			x.second=cntr;
		}
		PRINTVAR(cntr_max);
		PRINTVAR(peak_point);
		peak_point.setD(D);
		//----------------------
		cout<<"***************************************"<<endl;
		cout<<"find Points covering PPOX:"<<endl;
		vector<Point> gotCoveringPoints;
		for (auto island:islands_left)
		{
			if(island.coverPointOnXAxis(peak_point))
			{
				PRINTVAR(island);
				gotCoveringPoints.push_back(island);
			}
		}
		//----------------------
		// store covered islands into radar
		for (auto i:gotCoveringPoints)
		{
			peak_point.coverIslands.push_back(i);
		}
		radars.push_back(peak_point);
		//----------------------
		cout<<"***************************************"<<endl;
		cout<<"remove Points covering PPOX:"<<endl;
		cout<<"BEFORE:"<<islands_left.size()<<endl;
		for(auto iter=islands_left.begin();iter!=islands_left.end();)
		{
			bool flag_get=false;
			auto curIsland=*iter;
			for(auto g:gotCoveringPoints)
			{
				if(curIsland.getX()==g.getX() &&curIsland.getY()==g.getY())
					flag_get=true;
			}
			if (flag_get)
				islands_left.erase(iter);
			else
				iter++;
		}
		cout<<"AFTER:"<<islands_left.size()<<endl;
		cout<<"***************************************"<<endl;
		//----------------------
	}
	cout<<"***************************************"<<endl;
	cout<<"got radars"<<endl;
	for (auto r:radars)
	{
		PRINTVAR(r);
		cout<<"\tcovers islands:"<<endl;
		for (auto i:r.coverIslands)
		{
			cout<<"\t";
			PRINTVAR(i);
		}
	}

	try {
		//GUI gui;
		////gui.drawCircle(0,0,1,"lines");
		//
		//for (auto i:islands)
		//{
		//	i.setD(0.1);
		//	gui.drawPoint(i);
		//}
		//for (auto r:radars)
		//{
		//	gui.drawPoint(r);
		//}
		//wait_for_key();

		//Gnuplot g("GUI");
		Gnuplot g("GUI");

		g.reset_all();
		g.reset_plot();
		g.set_grid();


	} 
	catch (GnuplotException ge)
	{  
		cout << ge.what() << endl;
	}


	cout<<"***************************************"<<endl;
}

bool Case::checkLegality() {
	PRINT_DEBUG_INFO();
	//1
	PRINTVAR(N);
	PRINTVAR(islands.size());
	if(N!=islands.size())
	{
		PRINT_DEBUG_INFO();
		return false;
	}

	//2
	float maxY=0;
	for (auto p:islands)
	{
		if(p.getY()<=0)
		{
			PRINT_DEBUG_INFO();
			return false;
		}
		if(p.getY()>maxY)
			maxY=p.getY();

	}
	PRINTVAR(maxY);
	PRINTVAR(D);
	if(maxY>D)
	{
		cout<<"maxY > D, no solution"<<endl;
		PRINT_DEBUG_INFO();
		return false;
	}
	//3
	vector<Point>::iterator ip=islands.begin(),iq=islands.begin();
	for (;ip!=islands.end();ip++)
	{
		Point p=*ip;
		for (iq=ip+1;iq!=islands.end();iq++)
		{
			Point q=*iq;
			if(p.getX()==q.getX() && p.getY()==q.getY())
			{
				PRINT_DEBUG_INFO();
				return false;
			}
		}
	}

	// pass all checks finally
	return true;
}
pair<float,float> Point::getXCover(float D) 
{
	//PRINT_DEBUG_INFO();
	//show();
	float x=getX(),y=getY();
	float l=sqrt(D*D-y*y);
	//PRINTVAR(l);
	pair<float,float> loc={x-l,x+l} ;
	//PRINTVAR(x-l);
	//PRINTVAR(x+l);
	return loc;
}

bool canMerge(pair<float,float> a,pair<float,float> b)
{
	if (a.first>b.second || b.first>a.second )
		return false;
	else
		return true;
}
pair <float,float> merge(pair<float,float> a,pair<float,float> b)
{
	float right=min(a.second,b.second);
	float left=max(a.first,b.first);
	pair <float,float> p={left,right};
	return p;
}
void show(vector<pair<float,float>> v) 
{
	//PRINT_DEBUG_INFO();
	for (auto i:v)
		cout<<"("<<i.first<<",\t"<<i.second<<")"<<endl;
}

void wait_for_key ()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)  // every keypress registered, also arrow keys
	cout << endl << "Press any key to continue..." << endl;

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	_getch();
#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
	cout << endl << "Press ENTER to continue..." << endl;

	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();
#endif
	return;
}

void GUI::drawCircle(double xc,double yc,double r,string style,string info="")
{
	std::vector<double> x, y ;
	//const double PI=3.1415926;
	double theta=0;
	double theta_step=2*PI/GUI_DRAW_NPOINTS;

	for (int i = 0; i < GUI_DRAW_NPOINTS; i++)  // fill double arrays x, y, z
	{
		x.push_back(xc+r*(double)cos(theta));             // x[i] = i
		y.push_back(yc+r*(double)sin(theta)); // y[i] = i^2
		theta+=theta_step;
	}

	//cout << endl << endl << "*** user-defined lists of points (x,y)" << endl;
	//string style="points";
	g.set_style(style);
	g.plot_xy(x,y,info);
}

void GUI::drawPoint(Point p)
{
	drawCircle(p.getX(),p.getY(),0.01,"lines");
	drawCircle(p.getX(),p.getY(),p.getD(),"lines");
}
