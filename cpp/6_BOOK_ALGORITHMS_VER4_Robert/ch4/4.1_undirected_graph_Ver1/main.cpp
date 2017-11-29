#include "../../include/include.h"
#include "Graph.h"
#include "DepthFirstSearch.h"
void testSearch(Graph* g); // test table 4.1.4
void testPath(Graph* g); // test table 4.1.5
void testCC(Graph* g); // test table 4.1.6
//////////////////////////////
// MAIN
//////////////////////////////
int main() 
{
	//Graph* g=new Graph (10);
	Graph* g=new Graph ("tinyG.txt");
	//Graph* g=new Graph ("tinyG.connected.txt");
	//g->addEdge(1,2);
	DLOG(g->toString());
	testSearch(g);
	//testPath(g);
	//testCC(g);
	return 0;

}

//////////////////////////////
//////////////////////////////
//////////////////////////////
void testGraph()
{
	Graph* g=new Graph ("tinyG.txt");
	//g->addEdge(1,2);
	DLOG(g->toString());
}
void testSearch(Graph* g)
{
	DENTER;
	int SOURCE=1;
	TestSearch* ts=new TestSearch(g,SOURCE);
	DRETURN;
}
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
