#ifndef GRAPH_CLASS_H
#define GRAPH_CLASS_H
#include <map>
#include <deque>
#include <iostream>
#include <vector>
#include "include.top.h"
using namespace std;
#define NIL -999
#define COLOR_WHITE 0
#define COLOR_GREY  1
#define COLOR_BLACK 2

template <typename DATA_TYPE>
class NodeInGraph
{
	public:
		NodeInGraph();
		NodeInGraph(DATA_TYPE v); 
		NodeInGraph(DATA_TYPE v,NodeInGraph* ns,NodeInGraph* fc);
		void setmData(DATA_TYPE v){mData=v;};  
		DATA_TYPE getmData(){return mData;};
		void setmNextSibling(NodeInGraph* v){mNextSibling=v;}; 
		NodeInGraph<DATA_TYPE>* getmNextSibling(){return mNextSibling;};

		NodeInGraph<DATA_TYPE>* getmNextNSibling(int n=1);

		void setmFirstChild(NodeInGraph* v){mFirstChild=v;};   
		NodeInGraph* getmFirstChild(){return mFirstChild;};
		void show();

		int mD;
	private:
		DATA_TYPE mData;
		NodeInGraph* mNextSibling;
		NodeInGraph* mFirstChild;
};

template <typename TYPE_WEIGHT_Edge>
class Edge
{
	public:
		Edge() { setWeight(1); directed=false; };
		Edge(TYPE_WEIGHT_Edge w) { setWeight(w);directed=false;};
		Edge(TYPE_WEIGHT_Edge w,bool d) { setWeight(w);directed=d;};
		Edge(TYPE_WEIGHT_Edge w,bool d,double rv,double cv):weight(w),directed(d),r(rv),c(cv) {};
		void setWeight(TYPE_WEIGHT_Edge w){weight=w;};
		TYPE_WEIGHT_Edge getWeight(){ return weight; };
		void setR(double rv){r=rv;};
		void setC(double cv){c=cv;};
		double getR(){return r;};
		double getC(){return c;};
		bool isDirected(){return directed;};
		void show() { std::cout<<weight<<","<<directed<<","<<r<<","<<c<<std::endl; };
	private:
		TYPE_WEIGHT_Edge weight;
		double r,c;
		bool directed;
};

template <typename TYPE_OF_NODE,typename TYPE_OF_WEIGHT>
class GRAPH
{
	public:
		GRAPH(unsigned nodeCnt,Edge<TYPE_OF_WEIGHT> defaultEdge);
		void addEdge(TYPE_OF_NODE* from,TYPE_OF_NODE* to,Edge<TYPE_OF_WEIGHT> edge);
		Edge<TYPE_OF_WEIGHT> getEdge(TYPE_OF_NODE* from,TYPE_OF_NODE* to);
	private:
		unsigned getNewId();
	public:
		bool isExistNode(TYPE_OF_NODE* node){ 
			//return !(MAP_name2id.find(node)==MAP_name2id.end()); 
			for(auto p:MAP_name2id)
			{
				PRINTVAR(p.first);
				PRINTVAR(p.second);
				PRINTVAR(*p.first);
				if(*p.first==*node)
					return true;
			}
			return false;
		};
		bool isExistId(unsigned id){ return !(MAP_id2name.find(id)==MAP_id2name.end()); };
		TYPE_OF_NODE*  getNodeById(unsigned id) {return MAP_id2name[id];};
		TYPE_OF_NODE*  getNodeByName(TYPE_OF_NODE name) { 
			// name is the value stored in TYPE_OF_NODE*
			for(auto p:MAP_name2id)
			{
				if(*p.first==name)
					return p.first;
			}
			assert(0);
			//return 0;
			//return MAP_id2name[id];
		};
		unsigned 		getIdByNode(TYPE_OF_NODE* node) {return MAP_name2id[node];};
		void show();
		void showWeight();
		void showR();
		void showC();
		void showMAP_id2BFSdepth(){
			for(auto i:MAP_id2BFSdepth)
			{
				std::cout<<i.first<<"\t->\t"<<i.second<<std::endl;
			}
		};
		void showMAP_id2BFSparent(){
			for(auto i:MAP_id2BFSparent)
			{
				std::cout<<i.first<<"\t->\t"<<i.second<<std::endl;
			}
		};

		vector<vector <Edge<TYPE_OF_WEIGHT>>> getMat(){ return mat; };
		map<unsigned,int> getMAP_id2BFSdepth (){ return MAP_id2BFSdepth;};

	public:
		vector<unsigned> getChildIdList(unsigned nodeId);
		vector<unsigned> getParentIdList(unsigned nodeId);
		//void traverseDFS(void (*func)(TYPE_OF_NODE*)=0){traverseDFS(Root,"0",func);};
		//void traverseBFS(void (*func)(TYPE_OF_NODE*)=0){traverseBFS(Root,"0",func);};
		void traverseDFS(TYPE_OF_NODE* fromNode,void (*func)(TYPE_OF_NODE*)=0);
		void traverseBFS(TYPE_OF_NODE* fromNode,void (*func)(TYPE_OF_NODE*)=0);
		void printBFSTree() {
			bool flag_print=true;
			for(int depth=0;flag_print;depth++)
			{
				flag_print=false;
				for(auto i:MAP_id2BFSdepth)
				{
					if(i.second==depth)
					{
						int tmpd=depth;
						while(tmpd--)
							cout<<"-->";
						cout<<i.first<<"("<<*MAP_id2name[i.first]<<")"<<endl;
						flag_print=true;
					}
				}
			}
		};
		void printShortestPath(unsigned fromId,unsigned toId,std::string prefix="PSP:\t"){
			std::cout<<"calling printShortestPath(), from "<<fromId<<" to "<<toId<<std::endl;
			// this method must be used after run traverseBFS()
			if(fromId==toId)
				std::cout<<prefix<<fromId<<std::endl;
			else if (MAP_id2BFSparent[toId]==NIL)
			{
				std::cout<<"in printShortestPath(), no path from "<<fromId<<" to "<<toId<<std::endl;
			}
			else
			{
				printShortestPath(fromId,MAP_id2BFSparent[toId],prefix);
				std::cout<<prefix<<toId<<std::endl;
			}
		};
		map<unsigned,int> MAP_id2DFSdepth_grey;
		map<unsigned,int> MAP_id2DFSdepth_black;
	private:
		map<unsigned,unsigned> MAP_nodeId2color_DFS;	// map id2color 0:white,1:grey,2:black;
		vector<unsigned> visitStack_DFS;
		int DFSvisitTime;
		map<unsigned,int> MAP_id2DFSparent;
		void traverseDFS_recur(TYPE_OF_NODE* fromNode,
				vector<unsigned>* ptr_visitedList,
				void (*func)(TYPE_OF_NODE*)=0
				);

	private:
		map<TYPE_OF_NODE*,unsigned> MAP_name2id;
		map<unsigned,TYPE_OF_NODE*> MAP_id2name;
		map<unsigned,int> MAP_id2BFSdepth;
		map<unsigned,int> MAP_id2BFSparent;
		//std::vector<unsigned> nodeIdList;
		vector<vector <Edge<TYPE_OF_WEIGHT>>> mat;
		unsigned mNodeCnt;
};

#endif
