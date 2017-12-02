#include "../../include/include.h"
#include "Digraph.h"
class DirectedDFS 
{
	//////////////////////////////
	// Table 4.2.3
	//////////////////////////////
	public:
		DirectedDFS(Digraph*G,int s)
		{
			mMarked.resize(G->V(),0);
			dfs(G,s);
		}

		DirectedDFS(Digraph*G,vector<int> sources)
		{
			mMarked.resize(G->V(),0);
			for(int s:sources )
				if(!mMarked[s]) dfs(G,s);
		}

		bool marked(int v)
		{
			return mMarked[v];
		}
	private:
		void dfs(Digraph*G,int v)
		{
			mMarked[v]=true;
			for(int w:G->adj(v))
				if(!mMarked[w]) 
					dfs(G,w);
		}

	private:
		vector<bool> mMarked;
};
class TestDirectedDFS
{
	public:
		TestDirectedDFS()
		{
			Digraph*G=new Digraph("tinyG.txt");
			DLOG(G->toString());
			G->dumpDOT("TestDirectedDFS.dot");
			vector<int> sources;
			sources.push_back(5);
			//sources.push_back(11);
			DLOG(sources);
			DirectedDFS* reachable=new DirectedDFS(G,sources);
			for(int v=0;v<G->V();v++)
			{
				if(reachable->marked(v))
					cout<<v<<" ";
			}
			cout<<endl;
		}
};
