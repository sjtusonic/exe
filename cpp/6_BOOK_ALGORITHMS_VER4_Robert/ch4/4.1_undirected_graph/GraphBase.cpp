#include "../../include/include.h"
#include "GraphBase.h"
GraphBase::GraphBase(int v){
}

int  GraphBase::V(){
}
int  GraphBase::E(){
}
void GraphBase::addEdge(int v,int w){
}
vector<int> GraphBase::adj(int v){
}
string GraphBase::toString(){
	string s= ""+ 
	to_string(V())+" vertices, "+
	to_string(E())+"edges\n";
	for(int v=0;v<V();v++)
	{
		s+=v+":";
		for(int w:adj(v)) 
			s+=w+" ";
		s+="\n";
	}
	return s;
}
// freq used methods:
int GraphBase::degree(int v){
	int r=0;
	for(int w:adj(v)) r++;
}
int GraphBase::maxDegree(){
	int max=0;
	for(int v=0;v<V();v++)
		if(degree(v)>max)
			max=degree(v);
	return max;
}
int GraphBase::avgDegree(){
	return 2*E() /V();
}

int GraphBase::numberOfSelfLoops(){
	int count=0;
	for(int v=0;v<V();v++)
		for(int w:adj(v))
			if(v==w) count++;
	return count /2;
}
