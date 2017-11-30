#include "Graph.h"
class DepthFirstSearch {
	/////////////////////////////////
	// P337 Table 4.1.4	Search
	/////////////////////////////////
	private:
		bool* mMarked;
		int mCount;
	public:
		DepthFirstSearch() {}
		DepthFirstSearch(Graph* G,int s)
		{
			mMarked=new bool[G->V()];
			dfs(G,s);
		}
		void dfs(Graph* G,int v)
		{
			mMarked[v]=true;
			mCount++;
			for(int w:G->adj(v))
				if(!mMarked[w]) dfs(G,w);
		}
		bool marked(int w) { return mMarked[w]; }
		int count() { return mCount; }
};
class Search:public DepthFirstSearch
{
	public:
		Search(Graph* G,int s) { }
};
class TestSearch {
	public:
		TestSearch(Graph* G,int s)
		{
			DENTER;
			Search* search=new Search(G,s);
			for(int v=0;v<G->V();v++)
				if(search->marked(v))
					cout<<v<<" ";
			cout<<""<<endl;

			if(search->count()!=G->V())
				cout<<"NOT ";
			cout<<"connected."<<endl;
			DRETURN;
		}
		TestSearch(string fnameGraph,int s)
		{
			Graph* G=new Graph(fnameGraph);
			TestSearch(G,s);
		}
	private:
		;
};
void testSearch()
{
	DENTER;
	Graph* g=new Graph ("tinyG.txt");
	DLOG(g->toString());
	int SOURCE=1;
	new TestSearch(g,SOURCE);
	DRETURN;
}
