#include "GraphBase.h"
#include <set>
class GraphAdjList:public GraphBase {
	public:
		GraphAdjList(int ve);
		GraphAdjList(string fname);
		int  V();
		int  E();
		void addEdge(int v,int w);
		vector<int> adj(int v);
	private:
		int mV;
		int mE;
		vector<vector<int>> mAdj;
		// P337 Table4.1.4
	public:
		vector <int> search(int s); // find all nodes connected s
		bool marked(int s,int v); // does v connected to s
		int count(int s); // # of nodes connected s
};
