#include "../../include/include.h"
#include "DepthFirstSearch.h"
#include "DepthFirstPaths.h"
#include "CC.h"
#include "Cycle.h"
#include "TwoColor.h"
#include "SymbolGraph.h"
#include "DegreeOfSeparation.h"
#include "GraphProperties.h"
//void testSearch(Graph* g); // test table 4.1.4
//void testPath(Graph* g); // test table 4.1.5
//void testCC(Graph* g); // test table 4.1.6
//////////////////////////////
// MAIN
//////////////////////////////
int main() 
{
	//assert(0);
	//testGraph(); //table
	//testSearch();
	//testPath();
	//testCC();
	//testCycle();
	//testTwoColor();
	//testSymbolGraph();
	//testDegreeOfSeparation();
	testGraphProperties();
	DPRINT("-------------------------");
	return 0;
}

//////////////////////////////
//////////////////////////////
//////////////////////////////
#if 0
void testPath(Graph* g)
{
	DENTER;
	int SOURCE=1;
	bool USE_DFS=1;
	//g->search(SOURCE,USE_DFS);
	//g->search(SOURCE,!USE_DFS);

	DLOG(g->has_path_to(1,-1,9));
	//DLOG(g->get_one_path_to(1,-1,6));
	//DLOG(g->get_one_path_to(1,-1,2));
	//DLOG(g->get_one_path_to(1,-1,3));
	//DLOG(g->get_one_path_to(1,-1,8));

	auto paths=g->paths(SOURCE);
	for(auto one_path:paths)
	{
		DLOG(one_path );
	}
	DRETURN;
}
void testCC(Graph* g)
{
	DENTER;
	int M=g->countCC();
	DLOG(M);
	vector<vector<int>> components;
	for(int v=0;v<g->V();v++)
		components[g->id(v)].push_back(v);
	for(int i=0;i<M;i++)
	{
		for(int v:components[i])
			cout<<v<<" "<<endl;
		cout<<endl;
	}
	DRETURN;
}
#endif
