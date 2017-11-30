/////////////////////////////////
// P342 Table 4.1.5	Paths
/////////////////////////////////
class DepthFirstPaths
{
	private:
		bool* mMarked;
		int* mEdgeTo;
		int mS;
	public:
		DepthFirstPaths() {
			DENTER;
			DRETURN;
		}
		DepthFirstPaths(Graph* G,int s)
		{
			DENTER;
			DLOG(this);//0x7f
			mMarked=new bool[G->V()];
			DLOG(mMarked);//0x55
			mEdgeTo=new int[G->V()];
			mS=s;
			for(int i=0;i<G->V();i++)
				mEdgeTo[i]=-2; // init
			mEdgeTo[s]=-1; // root
			dfs(G,s);
			cout<<"mEdgeTo:";
			for(int i=0;i<G->V();i++)
			{
				cout<<i<<":"<<mEdgeTo[i]<<endl;
			}
			cout<<endl;
			DLOG(mMarked);//0x55
			DRETURN;
		}
	private:
		void dfs(Graph*G,int v)
		{
			DENTER;
			DLOG(v);
			mMarked[v]=1;
			DLOG(this);//0x7f
			DLOG(mMarked);//0x55
			DPRINT("set mMarked["<<v<<"]=1");
			for(int w:G->adj(v))
				if(!mMarked[w]) 
				{
					mEdgeTo[w]=v;
					DPRINT(" EdgeTo["<<w<<"]="<<v);
					dfs(G,w);
				}
			DRETURN;
		}
	public: 
		bool hasPathTo(int v) { 
			DENTER;
			bool r= mMarked[v]; 
			DLOG(this);//0x55
			DLOG(mMarked);//0x7f
			DPRINT("mMarked["<<v<<"]="<<r);
			DRETURN;
			return r;
		}
		vector<int> pathTo(int v)
		{
			DENTER;
			if(!hasPathTo(v)) return {};
			DEBUG_MARK;
			vector<int> path={};
			DEBUG_MARK;
			for(int x=v;x!=mS;x=mEdgeTo[x])
				path.push_back(x);
			DEBUG_MARK;
			path.push_back(mS);
			DEBUG_MARK;
			DLOG(path.size());
			DEBUG_MARK;
			DRETURN;
			return path;

		}
};
class Paths:public DepthFirstPaths
{
	public:
		Paths(Graph*g,int s){ 
			DENTER;
			DLOG(this);//0x55
			//DLOG(mMarked); no this member
			DepthFirstPaths(g,s);
			DRETURN;
		};
};
class TestPath
{
	public:
		TestPath(Graph* G,int s)
		{
			DENTER;
			Paths* search=new Paths(G,s);
			DLOG(search);//0x55
			for(int v=0;v<G->V();v++)
			{
				cout<<"from "<<s<<" to "<<v<<":";
				if(search->hasPathTo(v)) // call a wrong addres, which make the addr of mMarked wrong
					for(int x:search->pathTo(v))
						if(x==s) cout<<x;
						else     cout<<"-"<<x;
				cout<<endl;
			}
			DRETURN;
		}
};
void testPath()
{
	DENTER;
	Graph* g=new Graph("tinyG.txt");
	DLOG(g->toString());
	int SOURCE=1;
	new TestPath(g,SOURCE);
	DRETURN;
}
