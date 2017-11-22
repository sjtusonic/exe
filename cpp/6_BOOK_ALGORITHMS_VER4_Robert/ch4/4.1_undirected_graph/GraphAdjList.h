#include "GraphBase.h"
#include <set>
class GraphAdjList:public GraphBase {
	public:
		GraphAdjList(int ve);
		int  V();
		int  E();
		void addEdge(int v,int w);
		vector<int> adj(int v);
	private:
		int mV;
		int mE;
		set<int>mAdj;

};
