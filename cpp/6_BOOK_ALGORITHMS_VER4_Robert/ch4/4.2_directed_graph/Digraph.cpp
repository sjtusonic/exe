#include "Digraph.h"
Digraph::Digraph()
{
}

Digraph::Digraph(int v)
{
	mV=v;
	mE=0;
	mAdj={};
}
Digraph::Digraph(string fname){
	string filename=fname;
	std::ifstream infile(filename);
	if (!infile)
		std::cerr << "Couldn't open " << filename << " for reading\n";
	int a, b;
	int sum;
	int cntLine=0;
	while (infile >> a >> b)
	{
		cntLine++;
		DLOG(cntLine);
		DLOG(a);
		DLOG(b);
		if(cntLine==1)
		{
			mV=a;
			mE=0;
			mAdj={};
			for(int i=0;i<a;i++)
				mAdj.push_back({});
		}
		else
		{
			addEdge(a,b);
		}
	}
}

int  Digraph::V() { return mV;}
int  Digraph::E() { return mE;}

void Digraph::addEdge(int v,int w)
{
	DENTER;
	DLOG(mAdj.size());
	while(mAdj.size()<v+1)
	{
		mAdj.push_back({});
	}
	DLOG(mAdj.size());
	mAdj[v].push_back(w);
	mE++;
	DRETURN;
}

vector<int> Digraph::adj(int v) { 
	//DENTER;
	//DLOG(v);
	//DLOG(mAdj.size());
	if(mAdj.size()<v+1)
	{
		//DRETURN;
		return {};
	}
	//DRETURN;
	return mAdj[v]; 
}

string Digraph::toString()
{
	DENTER;
	string s= ""; 
	s+="\n-----------------------------\n";
	s+=to_string(V())+" vertices, "+
		to_string(E())+"edges\n";
	for(int v=0;v<V();v++)
	{
		s+=to_string(v)+"\t->\t";
		auto vv=adj(v);
		auto sz= vv.size();
		if(sz!=0)
		{
			for(int w:adj(v)) 
			{
				s+=to_string(w)+" ";
			}
		}
		s+="\n";
	}
	s+="-----------------------------\n";
	DRETURN;
	return s;
}

Digraph* Digraph::reverse()
{
	DENTER;
	auto R=new Digraph(V());
	DLOG(R->toString());
	//DEBUG_MARK;
	for(int v=0;v<mV;v++)
	{
		//DEBUG_MARK;
		for(int w:adj(v))
		{
			//DEBUG_MARK;
			DLOG(R);
			//DEBUG_MARK;
			R->addEdge(w,v);
		}
	}
	DRETURN;
	return R;
}
