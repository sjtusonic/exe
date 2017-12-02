/////////////////////////////////
// P358 Table DegreeOfSeparation
/////////////////////////////////
class DegreeOfSeparation
{
	public:
		DegreeOfSeparation(string fname,string delim=" ")// METHOD
		{
			SymbolGraph* sg=new SymbolGraph(fname,delim);
			Graph* G=sg->G();
			string source="beijing";

			if(!sg->contains(source))
			{ cout<<source<<" is not in database!"; return; }

			int s=sg->index(source);
			BreadthFirstPaths* bfs=new BreadthFirstPaths(G,s);

			string sink="taiwan";
			if(!sg->contains(sink))
			{ cout<<sink<<" is not in database!"; return; }

			DPRINT("CHECKING from "<<source<<" to "<<sink<<" ...");
			int t=sg->index(sink);

			if(bfs->hasPathTo(t))
				for(int v:bfs->pathTo(t))
					cout<<" "<<sg->name(v)<<endl;
			int degrees=bfs->pathTo(t).size()-1;
			DLOG(degrees);
		}
};

class TestDegreeOfSeparation// METHOD
{
	public:
		TestDegreeOfSeparation(string fname)//METHOD
		{
			new DegreeOfSeparation(fname);
		}
};
void testDegreeOfSeparation()//METHOD
{
	new TestDegreeOfSeparation("routes.txt");
}
