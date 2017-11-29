#include "../../include/include.h"
#include "Graph.h"
#include <queue>
#include <utility>



//struct CmpByKeyLength { bool operator()(const int& k1, const int& k2) { return k1.length() < k2.length(); } }; 


typedef std::pair<int,int> PAIR; 
class combyValue
{
	public:
		bool operator()(pair<int,int> &lhs,pair<int,int> &rhs)
		{return lhs.second<rhs.second;}
};

void print_sorted_hash_by_value(map<int,int> & mm ) { 
	//DENTER;
	vector<pair<int,int>> vv(mm.begin(),mm.end());
	//DLOG(vv.size());
	//sort(vv.begin(), vv.end(), CmpByValue());
	//sort(mm.begin(),mm.end(),combyValue());
	sort(vv.begin(), vv.end(), combyValue());
#if 1
	cout<<"-----------------------------"<<endl;
	cout<<"node, parent"<<endl;
	for (int i = 0; i != vv.size(); ++i) { 
		cout << vv[i].first<<"\t,\t"<<vv[i].second << endl;
	} 
	cout<<"-----------------------------"<<endl;
#endif
	//DRETURN;
	return ;
} 

Graph::Graph(int ve){
	DENTER;
	//DLOG(ve);
	mV=ve;
	mE=0;
	mAdj={};
	for(int i=0;i<ve;i++)
		mAdj.push_back({});
	DRETURN;
}
Graph::Graph(string fname){
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
int  Graph::V(){
	return mV;
}
int  Graph::E(){
	DENTER;
	DRETURN;
	return mE;
}
void Graph::addEdge(int v,int w){
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
vector<int> Graph::adj(int v){
	//DENTER;
	//DLOG(v);
	//DLOG(mAdj.size());
	//DLOG(mAdj[v].size());
	//DRETURN;
	return mAdj[v];
}

#if 0
/////////////////////////////////
// P342 Table 4.1.5	Paths
/////////////////////////////////
vector<PATHTYPE> Graph::paths(int s)// all paths from node s
{
}
bool Graph::has_path_to(int from,int through,int to)// path exists from through to
{
	assert(through==-1);
	return connected(from,to);
}
PATHTYPE Graph::get_one_path_to(int from,int through,int to)
{
	if(!has_path_to(from,through,to))
	{
		DPRINT("no path");
		return {};
	}
	PATHTYPE p;
	for(int x=to;x!=from;x=edge_dfs_to[x])
		p.push_back(x);
	p.push_back(from);
	reverse(p.begin(),p.end());
	return p;
}
vector<PATHTYPE> Graph::get_all_path(int from,int through, int to)// like report_timing
{
	assert(through==-1);
	vector<PATHTYPE> r;
	return r;
}
void Graph::report_path(int s,int v)// like report_timing
{
}
/////////////////////////////////
// P349 Table 4.1.6	CC (connected component)
/////////////////////////////////
void Graph::CC() // pre constr
{
	CC_marked={};
	CC_id={};
	for(int s=0;s<V();s++)
		if(!CC_marked[s]) // s is not connected yet
		{
			dfs_rec(s,CC_marked);
			CC_count++;
		}
}
int Graph::CC_getCount() // # of CC
{ return CC_count; }
int Graph::CC_getId(int v) // id of CC of node v
{
	return CC_id[v];
}
#endif
