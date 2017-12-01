/////////////////////////////////
// P342 Table 4.1.5	Paths
/////////////////////////////////
#define USE_DFS_SEARCH 1

#include "BreadthFirstPaths.h"
class DepthFirstPaths
{
	protected:
		vector<bool> mMarked;// MEMBER
		vector<int> mEdgeTo;// MEMBER
		int mS;
	public:
		DepthFirstPaths() {}//METHOD
		DepthFirstPaths(Graph* G,int s)//METHOD
		{
			mMarked.resize(G->V(),0);
			mEdgeTo.resize(G->V(),-2); // -2 is init value
			mEdgeTo[s]=-1; // -1 is root value
			mS=s;
			dfs(G,s);
			cout<<"mEdgeTo:";
			for(int i=0;i<G->V();i++)
			{
				cout<<i<<":"<<mEdgeTo[i]<<endl;
			}
			cout<<endl;
		}
	private:
		void dfs(Graph*G,int v)//METHOD
		{
			//DENTER;
			//DLOG(v);
			mMarked[v]=1;
			//DPRINT("set mMarked["<<v<<"]=1");
			//DLOG(mMarked[v]);
			for(int w:G->adj(v))
				if(!mMarked[w]) 
				{
					mEdgeTo[w]=v;
					DPRINT(" EdgeTo["<<w<<"]="<<v);
					dfs(G,w);
				}
			//DRETURN;
		}
	public: 
		bool hasPathTo(int v) { return mMarked[v]; }//METHOD
		vector<int> pathTo(int v)//METHOD
		{
			if(!hasPathTo(v)) return {};
			vector<int> path={};
			for(int x=v;x!=mS;x=mEdgeTo[x])
				path.push_back(x);
			path.push_back(mS);
			return path;
		}
};
#if USE_DFS_SEARCH
class Paths:public DepthFirstPaths
{
	public:
		using DepthFirstPaths::DepthFirstPaths;//METHOD
};
#else
class Paths:public BreadthFirstPaths
{
	public:
		using BreadthFirstPaths::BreadthFirstPaths;//METHOD
};
#endif
class TestPath
{
	public:
		TestPath(Graph* G,int s)//METHOD
		{
			DENTER;
			Paths* search=new Paths(G,s);
			DLOG(search);//0x55
			for(int v=0;v<G->V();v++)
			{
				cout<<"from "<<s<<" to "<<v<<":\t";
				if(search->hasPathTo(v))
					for(int x:search->pathTo(v))
						if(x==s) cout<<x;
						else     cout<<x<<"-";
				else
					cout<<"NA";
				cout<<endl;
			}
			DRETURN;
		}
};
void testPath()//METHOD
{
	DENTER;
	Graph* g=new Graph("tinyG.txt");
	DLOG(g->toString());
	int SOURCE=1;
	new TestPath(g,SOURCE);
	DRETURN;
}
