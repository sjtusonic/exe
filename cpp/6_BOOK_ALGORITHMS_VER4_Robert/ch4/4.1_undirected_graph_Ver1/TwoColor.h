/////////////////////////////////
// P352 	Table 4.1.7	TwoColor
/////////////////////////////////
class TwoColor
{
	private:
		vector<bool> mMarked;// MEMBER
		vector<int> mColor;
		bool mIsTwoColorable=true;// MEMBER
	public:
		TwoColor(Graph* G)// METHOD
		{
			mMarked.resize(G->V(),0);
			mColor.resize(G->V(),1);
			for(int s=0;s<G->V();s++)
				if(!mMarked[s])
					dfs(G,s);
			cout<<"-----------------------"<<endl;
			for(int ii=0;ii<mColor.size();ii++)
			{
				cout<<"Color "<<ii<<"\t=\t"<<mColor[ii]<<endl;
			}
			cout<<"-----------------------"<<endl;
		}
		void dfs(Graph* G,int v)// METHOD
		{
			mMarked[v]=1;
			for(int w:G->adj(v))
			{
				//PRINTVAR_hor(v);
				//DPRINT_hor(" ref:"<<u<<",");
				//DPRINT(w<<" of adj("<<v<<")");
				if(!mMarked[w]) 
				{
					mColor[w]=!mColor[v];
					DPRINT("ADD Color "<<w<<": "<<mColor[w]);
					dfs(G,w);
				}
				else if(mColor[w]==mColor[v])
				{
					mIsTwoColorable=0;
					DPRINT("not Colorable because same color:"<<w<<","<<v);
				}
			}
		}
		bool isBipartite() {return mIsTwoColorable;}
		//bool connected(int v,int w) { return mId[v]==mId[w];	}// METHOD
		//int id(int v){return mId[v];}// METHOD
		//int count(){return mCount;}// METHOD
};

class TestTwoColor// METHOD
{
	public:
		TestTwoColor(Graph* G)//METHOD
		{
			TwoColor* cy=new TwoColor(G);
			DLOG(cy->isBipartite());
		}
};
void testTwoColor()//METHOD
{
	Graph* g=new Graph("twoColor.txt");
	DLOG(g->toString());
	new TestTwoColor(g);
}
