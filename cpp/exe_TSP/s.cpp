#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define DLOG(a) PRINTVAR(a);
#define DENTER std::cout<<" -->"<<__PRETTY_FUNCTION__<<std::endl;
#define DRETURN std::cout<<"<-- "<<__PRETTY_FUNCTION__<<std::endl;

#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<"VEC:\t"<<#a<<"="<<*u<<std::endl;}

#define PRINT_VECTOR_hor(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;
//#define PRINT_VECTOR_hor(a) 
#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)
#define DEBUG_MARK PRINT_DEBUG_INFO()

#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )

#include <vector>
#include <math.h>
#include <string>
#include <iostream>
#include <deque>
#include <assert.h>
#include <limits>
#include <cstdint>
#include <algorithm>
#include <fstream>

#ifndef INT_MAX
#define INT_MAX 999999
#endif

using namespace std;
typedef pair<int,int> POINT;

ostream & operator<<(ostream &os, POINT p)
{
	os<<"("<<p.first<<","<<p.second<<")";
}
class Solver
{
	private:
		vector<pair<int,int>> mData;
		vector<int> mAnsInd;
		vector<int> mVisitedInd;
		//int startInd;
	public:
		// FOR Points:
		double sqr(double x) {return x*x;};
		double getDistance(POINT p1,POINT p2);
		double getDistanceSum(vector<POINT> v);
		double getDistanceSum(vector<int> v);
		//Solver(string fname);
		Solver();
		friend std::ostream& operator<< (std::ostream& o_os,Solver sol)
		{
			//cout<<"-----------------------------------"<<endl;
			//for(auto p:sol.getData())
			//{
			//	o_os<<p.first<<","<< p.second<<endl;
			//}
			//cout<<"-----------------------------------"<<endl;
			sol.show(sol.getData(),o_os);
			return o_os;
		};
		void dump(string fname);
		void read(string fname);

		vector<pair<int,int>> getData() {return mData;};
		void genRandomData(int cntNodes);
		void solveNearest() ;
		int getNearestPointInd(POINT p0) ;
		void show(vector<pair<int,int>> v,std::ostream& o_os=std::cout)
		{
			cout<<"-----------------------------------"<<endl;
			for(auto p:v)
			{
				o_os<<p.first<<","<< p.second<<endl;
			}
			cout<<"-----------------------------------"<<endl;
		}
		void show(vector<int> vInd,std::ostream& o_os=std::cout) // show by Index
		{
			cout<<"-----------------------------------"<<endl;
			for(auto i:vInd)
			{
				auto p=mData[i];
				o_os<<p.first<<","<< p.second<<endl;
			}
			cout<<"-----------------------------------"<<endl;
		}
};
void Solver::read(string fname)
{
	string filename=fname;
	std::ifstream infile(filename);
	if (!infile)
		std::cerr << "Couldn't open " << filename << " for reading\n";
	std::cout << "parsing " << filename << " ...\n";

	mData={};
	int a, b;
	int sum;
	while (infile >> a >> b)
	{   
		mData.push_back(make_pair(a,b));
	}
}
void Solver::dump(string fname)
{
	string filename_out=fname;
	std::ofstream outfile(filename_out);
	if (!outfile)
		std::cerr << "Couldn't open " << filename_out << " for writing\n";
	std::cout << "dumping " << filename_out << " ...\n";
	for(auto i:mAnsInd)
	{
		auto p=mData[i];
		outfile<<p.first<<" "<< p.second<<endl;
	}
}
void Solver::genRandomData(int cntNodes)
{
	int i=cntNodes;
	while(i>0)
	{
		srand(time(NULL)+i);
		int x=rand()%100;
		int y=rand()%100;
		auto p=make_pair(x,y);
		mData.push_back(p);
		//DLOG(x);
		//DLOG(y);
		i--;
	}
}
double Solver::getDistance(POINT p1,POINT p2)
{
	//DENTER;
	//DLOG(p1);
	//DLOG(p2);
	double r;
	double x1=p1.first;
	double x2=p2.first;
	double y1=p1.second;
	double y2=p2.second;
	r=pow((sqr(x1-x2)+sqr(y1-y2)),0.5);
	//DLOG(r);
	//DRETURN;
	return r;
}
double Solver::getDistanceSum(vector<POINT> v)
{
	double totalDist=0;
	for(int ind=0;ind<v.size();ind++)
	{
		if(ind==0)
			continue;
		totalDist+=getDistance(v[ind-1],v[ind]);
	}
	return totalDist;
}
double Solver::getDistanceSum(vector<int> v)
{
	//DENTER;
	double totalDist=0;
	for(int ind=0;ind<v.size();ind++)
	{
		if(ind==0)
			continue;
		//DEBUG_MARK;
		totalDist+=getDistance(mData[v[ind-1]],mData[v[ind]]);
	}
	//DLOG(totalDist);
	//DRETURN;
	return totalDist;
}
Solver::Solver()
{
	int CNT_NODES=10;
	genRandomData(CNT_NODES);
	//startInd=0;
	//for(auto p:mData)
	//{
	//	auto orig=make_pair(0,0);
	//	DLOG(getDistance(orig,p));
	//}
	DLOG(getDistanceSum(mData));
}
void Solver::solveNearest() 
{
	mAnsInd={};
	show(mAnsInd);
	mAnsInd.push_back(0);
	mVisitedInd.push_back(0);
	while(mVisitedInd.size()<mData.size())
	{
		int currInd=mAnsInd.back();
		auto nearestInd=getNearestPointInd(mData[currInd]);
		mAnsInd.push_back(nearestInd);
		mVisitedInd.push_back(nearestInd);
	}
	show(mAnsInd);
	DLOG(getDistanceSum(mAnsInd));
}
int Solver::getNearestPointInd(POINT p0) 
{
	DENTER;
	DLOG(p0);
	double minDist=INT_MAX;
	int minInd=-1;
	int ind=-1;
	DLOG(mData.size());
	for(auto p:mData)
	{
		ind++;
		auto it=std::find(mVisitedInd.begin(),mVisitedInd.end(),ind);
		if(it!=mVisitedInd.end())
			continue;
		double newDist=getDistance(p0,mData[ind]);
		//DLOG(newDist);
		if(newDist<minDist)
		{
			minDist=newDist;
			minInd=ind;
		}
	}
	DLOG(minDist);
	DLOG(minInd);
	return minInd;
}

int main ()
{
	Solver sol;
	cout<<sol<<endl;
	sol.solveNearest();
	sol.dump("out.nearest.dat");
	return 0;
}
