/////////////////////////////////
// P349 Table 4.1.6	CC
/////////////////////////////////
class CC
{
	private:

		vector<bool> mMarked;// MEMBER
		vector<int> mId;// MEMBER
		int mCount;// MEMBER 
	public:
		CC(Graph* G)// METHOD
		{
			mMarked.resize(G->V(),0);
			mId.resize(G->V(),-1);
			mCount=0;
			for(int s=0;s<G->V();s++)
				if(!mMarked[s])
				{
					dfs(G,s)	;
					mCount++;
				}
		}
		void dfs(Graph* G,int v)// METHOD
		{
			//DLOG(v);
			mMarked[v]=1;
			mId[v]=mCount;
			//DPRINT("set mId["<<v<<"]="<<mCount );
			for(int w:G->adj(v))
				if(!mMarked[w]) 
					dfs(G,w);
		}
		bool connected(int v,int w) { return mId[v]==mId[w];	}// METHOD
		int id(int v){return mId[v];}// METHOD
		int count(){return mCount;}// METHOD
};

class TestCC// METHOD
{
	public:
		TestCC(Graph* G)//METHOD
		{
			CC* cc=new CC(G);
			int M=cc->count();
			cout<<M<<" components:"<<endl;
			vector<vector<int>> components;
			components.resize(M,{});
			for(int i=0;i<M;i++)
				components[i]={};
			for(int v=0;v<G->V();v++)
				components[cc->id(v)].push_back(v);
			for(int i=0;i<M;i++)
			{
				for(int v:components[i])
					cout<<v<<" ";
				cout<<endl;
			}
		}
};
void testCC()//METHOD
{
	Graph* g=new Graph("tinyG.txt");
	DLOG(g->toString());
	new TestCC(g);
}
