#include "../../include/include.h"
#include "GraphAdjList.h"

GraphAdjList::GraphAdjList(int ve){
	DENTER;
	//DLOG(ve);
	mV=ve;
	mE=0;
	mAdj={};
	for(int i=0;i<ve;i++)
		mAdj.push_back({});
	DRETURN;
}
GraphAdjList::GraphAdjList(string fname){
	string filename=fname;
	std::ifstream infile(filename);
	if (!infile)
		std::cerr << "Couldn't open " << filename << " for reading\n";
	int a, b;
	int sum;
	int cntLine=0;
	while (infile >> a >> b)
	{
		cntLine++;
		DLOG(cntLine);
		DLOG(a);
		DLOG(b);
		if(cntLine==1)
		{
			mV=a;
			mE=0;
			mAdj={};
			for(int i=0;i<a;i++)
				mAdj.push_back({});
		}
		else
		{
			addEdge(a,b);
		}
	}
}
int  GraphAdjList::V(){
	return mV;
}
int  GraphAdjList::E(){
	DENTER;
	DRETURN;
	return mE;
}
void GraphAdjList::addEdge(int v,int w){
	DENTER;
	//DLOG(v);
	//DLOG(w);
	mAdj[v].push_back(w);
	mAdj[w].push_back(v);
	//DLOG(mAdj.size());
	//DLOG(mAdj[v].size());
	mE++;
	DRETURN;
}
vector<int> GraphAdjList::adj(int v){
	DENTER;
	//DLOG(v);
	//DLOG(mAdj.size());
	//DLOG(mAdj[v].size());
	DRETURN;
	return mAdj[v];
}
//////////////////////////
// P337 Table4.1.4
//////////////////////////
vector<int> GraphAdjList::search(int s) // find all nodes connected s
{
	return {};
}
bool  GraphAdjList::marked(int s,int v) // does v connected to s
{
	return 0;
}
int  GraphAdjList::count(int s) // # of nodes connected s
{
	return 0;
}
