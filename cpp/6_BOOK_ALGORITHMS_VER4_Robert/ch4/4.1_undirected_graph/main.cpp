#include "../../include/include.h"
#include "GraphAdjList.h"
int main() 
{
	//GraphAdjList* g=new GraphAdjList (10);
	GraphAdjList* g=new GraphAdjList ("tinyG.txt");
	//g->addEdge(1,2);
	DLOG(g->toString());
	return 0;

}

void testGraph()
{
	GraphAdjList* g=new GraphAdjList ("tinyG.txt");
	//g->addEdge(1,2);
	DLOG(g->toString());
}
void testSearch(GraphAdjList* g)
{
	int source=1;
	for(int v=0;v<g->V();v++)
	{
		if(g->marked(source,v))
			DLOG(v);
	}
	if(g->count(source )!=g->V())
		DPRINT("NOT");
	DPRINT("CONNECTED");

}
