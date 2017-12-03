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
		SymbolDigraph(string filename,string delim)//METHOD
		{
			DENTER;
			std::ifstream infile(filename);
			if (!infile)
				std::cerr << "Couldn't open " << filename << " for reading\n";
			cout<<"READING file: "<<filename<<" ..."<<endl;
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
			cout<<"READING file: "<<filename<<" ..."<<endl;
			cntLine=0;
			while (infile1 >> a >> b)
			{
				cntLine++;
				int u=mSt[a];
				int v=mSt[b];
				DPRINT("addEdge:"<<a<<"("<<u<<"),"<<b<<"("<<v<<")");
				mG->addEdge(u,v);
				//DPRINT("addEdge");
			}
			DLOG(mG->toString());
			DRETURN;
		}
		Digraph* G() {//METHOD
			return mG;}
		bool contains(string key) { return mSt.find(key)!=mSt.end(); }//METHOD
		int index(string key)//METHOD
		{
			DENTER;
			auto r= mSt[key];
			DRETURN;
			return r;
		}
		string name(int v)//METHOD
		{ return mKeys[v]; }
		string toString()
		{
			DENTER;
			string s= ""; 
			s+="\n-----------------------------\n";
			s+=to_string(mG->V())+" vertices, "+
				to_string(mG->E())+"edges\n";
			for(int v=0;v<mG->V();v++)
			{
				s+=name(v)+"("+to_string(v)+")\t->\t";
				auto vv=mG->adj(v);
				auto sz= vv.size();
				if(sz!=0)
				{
					for(int w:mG->adj(v))
					{
						s+=name(w)+"("+to_string(w)+") ";
					}
				}
				s+="\n";
			}
			s+="-----------------------------\n";
			DRETURN;
			return s;
		}
		void dumpDOT(string fname)
		{
			//----------------------------------------------------------
			string filename_out=fname;
			std::ofstream outfile(filename_out);
			if (!outfile)
			{
				std::cerr << "Couldn't open " << filename_out << " for writing\n";
				return;
			}
			cout<<"DUMPING FILE: "<<fname<<" ..."<<endl;
			outfile<<"digraph \""<<this<<"\" {"<<endl;
			for(int ii=0;ii<mG->V();ii++)
			{
				outfile<<ii<<"[label =\""<<ii<<","<<name(ii)<<"\"];"<<endl;
			}
			for(int v=0;v<mG->V();v++)
			{
				for(auto to:mG->adj(v))
					outfile<<v<<"->"<<to<<";"<<endl;
			}
			outfile<<"}"<<endl;
			//----------------------------------------------------------
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
