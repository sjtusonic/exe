#ifndef GRAPHBASE_H_
#define GRAPHBASE_H_
#include "../../include/include.h"
#define NNODES 100
class GraphBase {
	public:
		GraphBase();
		GraphBase(int v);

		virtual int  V();
		virtual int  E();
		virtual void addEdge(int v,int w);
		virtual vector<int> adj(int v);
		string toString();
		int degree(int v);
		int maxDegree();
		int avgDegree();
		int numberOfSelfLoops();
	private:

};
#endif
