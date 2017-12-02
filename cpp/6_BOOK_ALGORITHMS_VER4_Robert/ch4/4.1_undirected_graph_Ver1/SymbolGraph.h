class SymbolGraph
{
	/////////////////////////////////
	// P353 Table 4.1.8	SymbolGraph API
	/////////////////////////////////
	private:
		map<string,int> mSt;
		vector<string> mKeys;
		Graph* mG;
	public:
		SymbolGraph(string filename,string delim)
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
			mG=new Graph(mSt.size());
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
		Graph* G() {
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
class TestSymbolGraph
{
	public:
		TestSymbolGraph(string filename,string delim)
		{
			DENTER;
			SymbolGraph* sg=new SymbolGraph(filename,delim);
			Graph* G=sg->G();
			auto source="shanghai";
			DLOG(source);
			for(auto w:G->adj(sg->index(source)))
				DLOG(sg->name(w));
			source="guangzhou";
			DLOG(source);
			for(auto w:G->adj(sg->index(source)))
			{
				DLOG(sg->name(w));
			}
			DRETURN;
		}

};
void testSymbolGraph ()
{
	DENTER;
	new TestSymbolGraph("routes.txt"," ");
	DRETURN;
}
