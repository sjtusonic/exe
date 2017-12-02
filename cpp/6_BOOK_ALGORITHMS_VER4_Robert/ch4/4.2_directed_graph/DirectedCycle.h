/////////////////////////////////
// P372 	Table 4.2.5	DirectedCycle
/////////////////////////////////
class DirectedCycle
{
	private:
		vector<bool> mMarked;// MEMBER
		vector<int> mEdgeTo;// MEMBER
		vector<int> mDirectedCycle;
		vector<bool> mOnStack;
		bool mHasDirectedCycle;// MEMBER
	public:
		DirectedCycle(Digraph * G)// METHOD
		{
			auto v=G->V();
			mOnStack.resize(v,0);
			mEdgeTo.resize(v,-1);
			mMarked.resize(v,0);
			for(int s=0;s<v;s++)
				if(!mMarked[s])
					dfs(G,s);
			reverse(mDirectedCycle.begin(),mDirectedCycle.end());
		}
	private:
		void dfs(Digraph* G,int v)// METHOD
		{
			//DENTER;
			mOnStack[v]=1;
			mMarked[v]=1;
			for(int w:G->adj(v))
				if(hasCycle()) 
					return;
				else if(!mMarked[w])
				{
					mEdgeTo[w]=v;
					dfs(G,w);
				}
				else if(mOnStack[w])
				{
					mDirectedCycle={};
					for(int x=v;x!=w;x=mEdgeTo[x])
						mDirectedCycle.push_back(x);
					mDirectedCycle.push_back(w);
					mDirectedCycle.push_back(v);
				}
			mOnStack[v]=0;
			//DRETURN;
		}
	public:
		bool hasCycle() {return mDirectedCycle.size()!=0;}
		vector<int> cycle() {return mDirectedCycle;}
};

class TestDirectedCycle// METHOD
{
	public:
		TestDirectedCycle()//METHOD
		{
			Digraph* g=new Digraph("tinyG.hasDirectedCycle.txt");
			DLOG(g->toString());
			g->dumpDOT("TestDirectedCycle.dot");
			auto dc=new DirectedCycle(g);
			DLOG(dc->hasCycle());
			if(dc->hasCycle())
				DLOG(dc->cycle());
		}
};
