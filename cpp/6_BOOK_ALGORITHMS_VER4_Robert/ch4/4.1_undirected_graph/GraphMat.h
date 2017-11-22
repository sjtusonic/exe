#include "GraphBase.h"
class GraphMat:public GraphBase {
	int  V();
	int  E();
	void addEdge(int v,int w);
	vector<int> adj(int v);
}
