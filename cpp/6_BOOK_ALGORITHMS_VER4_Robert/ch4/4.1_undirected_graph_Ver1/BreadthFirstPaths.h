/////////////////////////////////
// P342 Table 4.1.5	Paths
/////////////////////////////////
class BreadthFirstPaths
{
	protected:
		vector<bool> mMarked;// MEMBER
		vector<int> mEdgeTo;// MEMBER
		int mS;
	public:
		BreadthFirstPaths() {}//METHOD
		BreadthFirstPaths(Graph* G,int s)//METHOD
		{
			mMarked.resize(G->V(),0);
			mEdgeTo.resize(G->V(),-2); // -2 is init value
			mEdgeTo[s]=-1; // -1 is root value
			mS=s;
			bfs(G,s);
			cout<<"mEdgeTo:";
			for(int i=0;i<G->V();i++)
			{
				cout<<i<<":"<<mEdgeTo[i]<<endl;
			}
			cout<<endl;
		}
	private:
		void bfs(Graph*G,int s)//METHOD
		{
			deque<int> queue={};
			mMarked[s]=1;
			queue.push_back(s);
			while(!queue.empty())
			{
				int v=queue.front();
				queue.pop_front();
				for(int w:G->adj(v))
					if(!mMarked[w]) 
					{
						mEdgeTo[w]=v;
						mMarked[w]=1;
						DPRINT(" EdgeTo["<<w<<"]="<<s);
						queue.push_back(w);
					}
			}
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
