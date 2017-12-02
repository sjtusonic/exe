#ifndef _DIGRAPH_H_
#define _DIGRAPH_H_
#include "../../include/include.h"
class Digraph {
	public:
		Digraph();
		Digraph(int v);
		Digraph(string fname);

		virtual int V();
		virtual int E();
		//////////////////////////////
		// Table 4.2.2
		//////////////////////////////
		virtual void addEdge(int v,int w);
		virtual vector<int> adj(int v);
		Digraph *reverse();
		string toString();
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
			for(int ii=0;ii<V();ii++)
			{
				outfile<<ii<<";"<<endl;
			}
			for(int v=0;v<V();v++)
			{
				for(auto to:adj(v))
					outfile<<v<<"->"<<to<<";"<<endl;
			}
			outfile<<"}"<<endl;
			//----------------------------------------------------------
		}
		//
	private:
		int mV;
		int mE;
		vector<vector<int>> mAdj;
};

class TestDigraph {
	public:
		TestDigraph()
		{
			Digraph * g=new Digraph ("tinyG.txt");
			DLOG(g->toString());
			auto gr=g->reverse();
			DLOG(gr->toString());
		}
};
#endif
