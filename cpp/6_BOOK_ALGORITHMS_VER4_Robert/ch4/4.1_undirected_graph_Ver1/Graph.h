#ifndef GRAPH_H_
#define GRAPH_H_
#include "GraphBase.h"
#include <set>
typedef vector<int> PATHTYPE;
class Graph:public GraphBase {
	/////////////////////////////////
	// P333 Table 4.1.1	Graph API
	/////////////////////////////////
	public:
		Graph(int ve);
		Graph(string fname);
		int  V();
		int  E();
		void addEdge(int v,int w);
		vector<int> adj(int v);
	private:
		int mV;
		int mE;
		vector<vector<int>> mAdj;
		/////////////////////////////////
		// P342 Table 4.1.5	Paths
		/////////////////////////////////

	public:
		vector<PATHTYPE> paths(int s);// all paths from node s
		bool has_path_to(int from,int through,int to);// path exists from through to
		PATHTYPE get_one_path_to(int from,int through,int to);
		vector<PATHTYPE> get_all_path(int from,int through, int to);// like report_timing
		void report_path(int s,int v);// like report_timing
		/////////////////////////////////
		// P349 Table 4.1.6	CC (connected component)
		/////////////////////////////////
	public:
		void CC(); // pre constr
		int CC_getCount(); // # of CC
		int CC_getId(int v); // id of CC of node v
	private:
		vector<bool> CC_marked;
		vector<int> CC_id;
		int CC_count;
		/////////////////////////////////
		/////////////////////////////////
		/////////////////////////////////

};

#if 1
void testGraph();
#endif


#endif
