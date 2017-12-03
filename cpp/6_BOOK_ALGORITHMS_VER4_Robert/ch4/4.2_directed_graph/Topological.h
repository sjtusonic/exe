class Topological
{
	private:
		vector<int> mOrder;
	public:
		Topological(Digraph*G)
		{
			DENTER;
			DirectedCycle*cyclefinder=new DirectedCycle(G);
			DLOG(cyclefinder->hasCycle());
			if(!cyclefinder->hasCycle())
			{
				DepthFirstOrder* dfs=new DepthFirstOrder(G);
				mOrder=dfs->reversePost();
				reverse(mOrder.begin(),mOrder.end());
				DLOG(mOrder);
				DLOG(dfs->pre());
				DLOG(dfs->post());
			}
			DRETURN;
		}
		bool isDAG() { return mOrder.size()!=0; }
		vector<int> order() { return mOrder; }
};
class TestTopological
{
	public:
		TestTopological()
		{
			string fname="tinyG.nocycle.txt";
			SymbolDigraph* sg=new SymbolDigraph(fname," ");
			auto G=sg->G();
			//DLOG(G->toString());
			DLOG(sg->toString());
			//G->dumpDOT("TestTopological.dot");
			sg->dumpDOT("TestTopological.dot");

			Topological* topo=new Topological(G);
			DLOG(topo->isDAG());
			for(int v:topo->order())
			{
				cout<<sg->name(v)<<"("<<v<<") ";
			}
			cout<<endl;
		}
};
