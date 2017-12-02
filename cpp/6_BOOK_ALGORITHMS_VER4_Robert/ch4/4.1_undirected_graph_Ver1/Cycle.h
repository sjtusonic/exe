/////////////////////////////////
// P352 	Table 4.1.7	Cycle
/////////////////////////////////
class Cycle
{
	private:
		vector<bool> mMarked;// MEMBER
		bool mHasCycle;// MEMBER
		vector<int> mCycle;
	public:
		Cycle(Graph* G)// METHOD
		{
			mMarked.resize(G->V(),0);
			mCycle={};
			for(int s=0;s<G->V();s++)
				if(!mMarked[s])
					dfs(G,s,s);
		}
		void dfs(Graph* G,int v,int u)// METHOD
		{
			// print some cycles but not all
			// how to print all cycles?
			//DENTER;
			mMarked[v]=1;
			mCycle.push_back(v);
#if 0
			cout<<"mMarked:";
			for(int ii=0;ii<mMarked.size();ii++)
			{
				if(mMarked[ii])
					cout<<ii<<" ";
			}
			cout<<endl;
#endif
			//DLOG(mCycle);
			//DPRINT("set mId["<<v<<"]="<<mCount );
			for(int w:G->adj(v))
			{
				//PRINTVAR_hor(v);
				//DPRINT_hor(" ref:"<<u<<",");
				//DPRINT(w<<" of adj("<<v<<")");
				if(!mMarked[w]) 
				{
					dfs(G,w,v);
				}
				else if(w!=u) 
				{
					auto iter=find(mCycle.begin(),mCycle.end(),w);
					if(iter!=mCycle.end())
					{
						int ind=iter-mCycle.begin();
						mCycle.push_back(w);
						//DPRINT("hasCycle because: "<<w<<"!="<<u);
						DPRINT("hasCycle:");
						for(int ii=ind;ii<mCycle.size();ii++)
						{
							cout<<mCycle[ii]<<" ";
						}
						cout<<endl;
						mHasCycle=true;
						mCycle.pop_back();
					}
				}
			}
			mCycle.pop_back();
			//DRETURN;
		}
		//bool connected(int v,int w) { return mId[v]==mId[w];	}// METHOD
		//int id(int v){return mId[v];}// METHOD
		//int count(){return mCount;}// METHOD
};

class TestCycle// METHOD
{
	public:
		TestCycle(Graph* G)//METHOD
		{
			Cycle* cy=new Cycle(G);
		}
};
void testCycle()//METHOD
{
	Graph* g=new Graph("tinyG.txt");
	DLOG(g->toString());
	new TestCycle(g);
}
