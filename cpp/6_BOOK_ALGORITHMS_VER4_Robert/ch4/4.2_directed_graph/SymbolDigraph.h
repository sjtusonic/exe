class SymbolDigraph
{
	/////////////////////////////////
	// P353 Table 4.1.8	SymbolDigraph API
	/////////////////////////////////
	private:
		map<string,int> mSt;
		vector<string> mKeys;
		Digraph* mG;
	public:
		SymbolDigraph(string filename,string delim)
		{
			DENTER;
			std::ifstream infile(filename);
			if (!infile)
				std::cerr << "Couldn't open " << filename << " for reading\n";
			string a, b;
			int cntLine=0;
			while (infile >> a >> b)
			{
				cntLine++;
				if(mSt.find(a)==mSt.end())
					mSt[a]=mSt.size()-1;
				if(mSt.find(b)==mSt.end())
					mSt[b]=mSt.size()-1;
			}

			mKeys.resize(mSt.size());
			//for(string name:mSt.keys())
			//mKeys[st.get(name)]=name;
			for(auto pair:mSt)
			{
				mKeys[pair.second]=pair.first;
			}
			mG=new Digraph(mSt.size());
			std::ifstream infile1(filename);
			if (!infile1)
				std::cerr << "Couldn't open " << filename << " for reading\n";
			cntLine=0;
			while (infile1 >> a >> b)
			{
				if(cntLine>mSt.size())
					break;
				cntLine++;
				int u=mSt[a];
				int v=mSt[b];
				mG->addEdge(u,v);
				//DPRINT("addEdge");
			}
			DLOG(mG->toString());
			DRETURN;
		}
		Digraph* G() {
			return mG;}
		bool contains(string key) { return mSt.find(key)!=mSt.end(); }
		int index(string key)
		{
			DENTER;
			auto r= mSt[key];
			DRETURN;
			return r;
		}
		string name(int v)
		{
			return mKeys[v];
		}
};
class TestSymbolDigraph
{
	public:
		TestSymbolDigraph(string filename,string delim)
		{
			DENTER;
			SymbolDigraph* sdg=new SymbolDigraph(filename,delim);
			Digraph* G=sdg->G();
			auto source="shanghai";
			DLOG(source);
			for(auto w:G->adj(sdg->index(source)))
				DLOG(sdg->name(w));
			source="guangzhou";
			DLOG(source);
			for(auto w:G->adj(sdg->index(source)))
			{
				DLOG(sdg->name(w));
			}
			DRETURN;
		}

};
void testSymbolDigraph ()
{
	DENTER;
	new TestSymbolDigraph("routes.txt"," ");
	DRETURN;
}
