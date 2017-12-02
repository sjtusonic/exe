/////////////////////////////////
// P361 Table 4.1.10	GraphProperties
/////////////////////////////////
class GraphProperties
{
	private:
		vector<bool> mMarked;// MEMBER
		vector<int> mEccentricity;
		vector<int> mId;// MEMBER
		Graph* mG;
		bool mSingleCC;
		BreadthFirstPaths* mBfs;
	public:
		GraphProperties(Graph* G)// METHOD
		{
			mG=G;
			mMarked.resize(G->V(),0);
			mEccentricity.resize(G->V(),0);
			mSingleCC=1;
			CC* cc=new CC(G);

			if(cc->count()>1)
			{
				DPRINT("Graph has more than 1 CC, return");
				mSingleCC=0;
				return;
			}
			for(int ii=0;ii<mG->V();ii++)
			{
				mEccentricity[ii]=eccentricity(ii);
			}
		}
		int eccentricity(int v) // the min distance the farest node of node v
		{
			if(!mSingleCC) return -1;
			mBfs=new BreadthFirstPaths(mG,v);
			mBfs->getEccentricity();
		}
		int diameter() // the max value of eccentricity of all nodes
		{
			if(!mSingleCC) return -1;
			int max=-1;
			for(int ii=0;ii<mG->V();ii++)
			{
				if(mEccentricity[ii]>max)
				{
					max=mEccentricity[ii];
				}
			}
			return max;
		}
		int radius() // the min value of eccentricity of all nodes
		{
			if(!mSingleCC) return -1;
			int min=9999;
			for(int ii=0;ii<mG->V();ii++)
			{
				if(mEccentricity[ii]<min)
				{
					min=mEccentricity[ii];
				}
			}
			return min;
		}
		int center() // nodes whose diameter==radius
		{
			if(!mSingleCC) return -1;
			for(int ii=0;ii<mG->V();ii++)
			{
				auto d=diameter();
				auto r=radius();
				DLOG(ii);
				DLOG(d);
				DLOG(r);
				if(d==r)
					return ii;
			}
			return -1;
		}
		//void dfs(Graph* G,int v)// METHOD
		//{
		//	//DLOG(v);
		//	mEccentricity[v]=eccentricity(v);
		//	mMarked[v]=1;
		//	for(int w:G->adj(v))
		//		if(!mMarked[w]) 
		//		{
		//			dfs(G,w);
		//		}
		//}
};

class TestGraphProperties// METHOD
{
	public:
		TestGraphProperties(Graph* G)//METHOD
		{
			GraphProperties* gp=new GraphProperties(G);
			DLOG(gp->eccentricity(1));
			DLOG(gp->diameter());
			DLOG(gp->radius());
			DLOG(gp->center());
		}
};
void testGraphProperties()//METHOD
{
	Graph* g=new Graph("tinyG.connected.txt");
	DLOG(g->toString());
	new TestGraphProperties(g);
}
