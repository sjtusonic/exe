#include <map>
#include <iostream>
#include <vector>
#include "include.top.h"
#include "GRAPH.class.h"
using namespace std;


//	FUNC
template <typename TYPE_OF_NODE,typename TYPE_OF_WEIGHT>
GRAPH<TYPE_OF_NODE,TYPE_OF_WEIGHT>::GRAPH(unsigned nodeCnt,Edge<TYPE_OF_WEIGHT> defaultEdge){
	//vector<vector <Edge<TYPE_OF_WEIGHT>>> mat;
	mNodeCnt=nodeCnt;

	for(int i=0;i<nodeCnt;i++)
	{
		vector <Edge<TYPE_OF_WEIGHT>> tmp;
		for(int j=0;j<nodeCnt;j++)
		{
			//mat[i][j]=defaultEdge;
			tmp.push_back(defaultEdge);

			//PRINTVAR(i);
			//PRINTVAR(j);
			//defaultEdge.show();
		}
		mat.push_back(tmp);
	}
	PRINTVAR(mat.size());
};

//	FUNC
template <typename TYPE_OF_NODE,typename TYPE_OF_WEIGHT>
void GRAPH<TYPE_OF_NODE,TYPE_OF_WEIGHT>::addEdge(TYPE_OF_NODE* from,TYPE_OF_NODE* to,Edge<TYPE_OF_WEIGHT> edge){
	PRINT_DEBUG_INFO();
	if(!isExistNode(from))
	{
		PRINT_DEBUG_INFO();
		PRINTVAR(*from);
		PRINTVAR(from);
		auto newId=getNewId();
		MAP_name2id[from]=newId;
		MAP_id2name[newId]=from;
		PRINTVAR(from);
		PRINTVAR(newId);
	} 
	else 
	{
		from=getNodeByName(*from);
	}
	if(!isExistNode(to))
	{
		PRINT_DEBUG_INFO();
		PRINTVAR(*to);
		PRINTVAR(to);
		auto newId=getNewId();
		MAP_name2id[to]=newId;
		MAP_id2name[newId]=to;
		PRINTVAR(to);
		PRINTVAR(newId);
	}
	else 
	{
		to=getNodeByName(*to);
	}

	PRINT_DEBUG_INFO();
	std::cout<<"-------------------------------"<<std::endl;
	std::cout<<"addEdge:"<<from
		<<"("<<MAP_name2id[from]<<"),"
		<<to
		<<"("<<MAP_name2id[to]<<")"
		<<std::endl;
	edge.show();
	std::cout<<"-------------------------------"<<std::endl;
	PRINT_DEBUG_INFO();
	assert(from);
	assert(to);
	PRINT_DEBUG_INFO();
	if(MAP_name2id[from])
		PRINTVAR(MAP_name2id[from]);
	PRINT_DEBUG_INFO();
	if(MAP_name2id[to])
		PRINTVAR(MAP_name2id[to]);
	PRINT_DEBUG_INFO();
	mat[MAP_name2id[from]][MAP_name2id[to]]=edge;
	PRINT_DEBUG_INFO();
};

//	FUNC
template <typename TYPE_OF_NODE,typename TYPE_OF_WEIGHT>
Edge<TYPE_OF_WEIGHT> GRAPH<TYPE_OF_NODE,TYPE_OF_WEIGHT>::getEdge(TYPE_OF_NODE* from,TYPE_OF_NODE* to){
	if(!isExistNode(from))
		return 0;
	if(!isExistNode(to))
		return 0;
	return mat[MAP_name2id[from]][MAP_name2id[to]];
};


//	FUNC
template <typename TYPE_OF_NODE,typename TYPE_OF_WEIGHT>
unsigned GRAPH<TYPE_OF_NODE,TYPE_OF_WEIGHT>::getNewId(){
	unsigned id=0;
	while(isExistId(id))
	{
		id++;
	}
	return id;
};

//	FUNC
template <typename TYPE_OF_NODE,typename TYPE_OF_WEIGHT>
void GRAPH<TYPE_OF_NODE,TYPE_OF_WEIGHT>::show(){
	std::cout<<"-------------------------------"<<std::endl;
	std::cout<<"MAP_id2name"<<std::endl;
	for(auto id2name:MAP_id2name)
	{
		//PRINTVAR(id2name.first);
		//PRINTVAR(id2name.second);
		std::cout<<id2name.first<<"->"<<id2name.second<<std::endl;
	}
	std::cout<<"-------------------------------"<<std::endl;
	std::cout<<"MAP_name2id"<<std::endl;
	for(auto name2id:MAP_name2id)
	{
		//PRINTVAR(name2id.first);
		//PRINTVAR(name2id.second);
		std::cout<<name2id.first<<"->"<<name2id.second<<std::endl;
	}
	std::cout<<"-------------------------------"<<std::endl;
	showWeight();
	showR();
	showC();
};

//	FUNC
	template <typename TYPE_OF_NODE,typename TYPE_OF_WEIGHT>
void GRAPH<TYPE_OF_NODE,TYPE_OF_WEIGHT>::showWeight()
{
	std::cout<<"-------------------------------"<<std::endl;
	std::cout<<"showWeight()"<<std::endl;
	//
	cout<<"\t";
	for(int j=0;j<mNodeCnt;j++)
	{
		cout<<MAP_id2name[j]<<"\t";
	}
	cout<<endl;
	//
	for(int i=0;i<mNodeCnt;i++)
	{
		cout<<MAP_id2name[i]<<"\t";
		for(int j=0;j<mNodeCnt;j++)
		{
			auto cell=mat[i][j];
			cout<<cell.getWeight()<<"\t";
		}
		cout<<endl;
	}
	std::cout<<"-------------------------------"<<std::endl;
};

//	FUNC
	template <typename TYPE_OF_NODE,typename TYPE_OF_WEIGHT>
void GRAPH<TYPE_OF_NODE,TYPE_OF_WEIGHT>::showR()
{
	std::cout<<"-------------------------------"<<std::endl;
	std::cout<<"showRate()"<<std::endl;
	//
	cout<<"\t";
	for(int j=0;j<mNodeCnt;j++)
	{
		cout<<MAP_id2name[j]<<"\t";
	}
	cout<<endl;
	//
	for(int i=0;i<mNodeCnt;i++)
	{
		cout<<MAP_id2name[i]<<"\t";
		for(int j=0;j<mNodeCnt;j++)
		{
			auto cell=mat[i][j];
			cout<<cell.getR()<<"\t";
		}
		cout<<endl;
	}
	std::cout<<"-------------------------------"<<std::endl;
};

//	FUNC
	template <typename TYPE_OF_NODE,typename TYPE_OF_WEIGHT>
void GRAPH<TYPE_OF_NODE,TYPE_OF_WEIGHT>::showC()
{
	std::cout<<"-------------------------------"<<std::endl;
	std::cout<<"showCommission()"<<std::endl;
	//
	cout<<"\t";
	for(int j=0;j<mNodeCnt;j++)
	{
		cout<<MAP_id2name[j]<<"\t";
	}
	cout<<endl;
	//
	for(int i=0;i<mNodeCnt;i++)
	{
		cout<<MAP_id2name[i]<<"\t";
		for(int j=0;j<mNodeCnt;j++)
		{
			auto cell=mat[i][j];
			cout<<cell.getC()<<"\t";
		}
		cout<<endl;
	}
	std::cout<<"-------------------------------"<<std::endl;
};

//	FUNC
	template <typename TYPE_OF_NODE,typename TYPE_OF_WEIGHT>
vector<unsigned> GRAPH<TYPE_OF_NODE,TYPE_OF_WEIGHT>::getChildIdList(unsigned nodeId) 
{
	vector<unsigned> r;
	unsigned toId=0;
	for(auto edge:mat[nodeId])
	{
		if(edge.getWeight()>0)
			r.push_back(toId);
		toId++;
	}
	cout<<"getChildIdList("<<nodeId<<")=\t";
	PRINT_VECTOR_hor(r);
	return r;
};

//	FUNC
	template <typename TYPE_OF_NODE,typename TYPE_OF_WEIGHT>
vector<unsigned> GRAPH<TYPE_OF_NODE,TYPE_OF_WEIGHT>::getParentIdList(unsigned nodeId) 
{
	vector<unsigned> r;
	unsigned j=0;
	for(int fromId=0;fromId<mNodeCnt;fromId++)
	{
		for(int toId=0;toId<mNodeCnt;toId++)
		{
			TYPE_OF_WEIGHT weight=mat[fromId][toId].getWeight();
			if(toId==nodeId && weight>0)
				r.push_back(fromId);
		}
	}
	PRINT_VECTOR_hor(r);
	return r;
};

//	FUNC
	template <typename TYPE_OF_NODE,typename TYPE_OF_WEIGHT>
void GRAPH<TYPE_OF_NODE,TYPE_OF_WEIGHT>::traverseDFS(TYPE_OF_NODE* fromNode,void (*func)(TYPE_OF_NODE*))
{
	vector<unsigned> visitedList; 		// store as id
	//map<unsigned,unsigned> MAP_nodeId2color_DFS;	// map id2color 0:white,1:grey,2:black;
	// init
	for(int u=0;u<mNodeCnt;u++)
	{
		MAP_nodeId2color_DFS[u]=COLOR_WHITE; // mark all white
		MAP_id2DFSparent[u]=NIL;
		MAP_id2DFSdepth_grey[u]=NIL;
		MAP_id2DFSdepth_black[u]=NIL;
	}
	DFSvisitTime=0;
	// 
	traverseDFS_recur(fromNode,&visitedList,func);
};

//	FUNC
	template <typename TYPE_OF_NODE,typename TYPE_OF_WEIGHT>
void GRAPH<TYPE_OF_NODE,TYPE_OF_WEIGHT>::traverseDFS_recur(TYPE_OF_NODE* curNode,
		vector<unsigned>* ptr_visitedList,
		void (*func)(TYPE_OF_NODE*)
		)
{
	PRINT_MAP(MAP_nodeId2color_DFS);
	unsigned curId=MAP_name2id[curNode];
	cout<<"calling traverseDFS_recur("<<curId<<")"<<endl;
	vector<unsigned>       visitedList     =*ptr_visitedList;

	visitStack_DFS.push_back(curId);
	MAP_nodeId2color_DFS[curId]=COLOR_GREY;
	MAP_id2DFSdepth_grey[curId]=DFSvisitTime;

	vector<unsigned> childList=getChildIdList(curId);
	for(auto id:childList)
	{
		if(MAP_nodeId2color_DFS[id]!=COLOR_GREY)
		{
			MAP_id2DFSparent[id]=curId;
			DFSvisitTime++;
			traverseDFS_recur(getNodeById(id),ptr_visitedList,func);
		}
	}
	MAP_nodeId2color_DFS[curId]=COLOR_BLACK;
	DFSvisitTime++;
	MAP_id2DFSdepth_black[curId]=DFSvisitTime;
	PRINT_MAP(MAP_nodeId2color_DFS);
	PRINT_MAP(MAP_id2DFSparent);
	PRINT_MAP(MAP_id2DFSdepth_grey);
	PRINT_MAP(MAP_id2DFSdepth_black);
	PRINT_VECTOR_hor(visitStack_DFS);
	assert(visitStack_DFS.back()==curId);
	visitStack_DFS.pop_back();
};

//	FUNC
	template <typename TYPE_OF_NODE,typename TYPE_OF_WEIGHT>
void GRAPH<TYPE_OF_NODE,TYPE_OF_WEIGHT>::traverseBFS(TYPE_OF_NODE* fromNode,void (*func)(TYPE_OF_NODE*))
{
	//vector<unsigned> visitedList; 		// store as id
	map<unsigned,unsigned> MAP_nodeId2color;	// map id2color 0:white,1:grey,2:black;
	std::deque<unsigned> queue;

	//---------------------
	// init color/depth/parent
	for(auto pair:MAP_id2name)
	{
		MAP_nodeId2color[pair.first]=COLOR_WHITE;
		MAP_id2BFSdepth [pair.first]=NIL;
		MAP_id2BFSparent[pair.first]=NIL;
	}
	//---------------------
	//---------------------
	// root node
	TYPE_OF_NODE* curNode=fromNode;
	unsigned curId=MAP_name2id[curNode];
	PRINTVAR(curId);
	MAP_id2BFSdepth[curId]=0;
	MAP_id2BFSparent[curId]=NIL;
	queue.clear();
	cout<<"qpush "<<curId<<endl;
	queue.push_back(curId);
	//---------------------

	while(queue.size()!=0)
	{
		//---------------------
		// show queue
		PRINTVAR(queue.size());
		for (std::deque<unsigned>::iterator it = queue.begin(); it!=queue.end(); ++it)
			std::cout << " q" << *it;
		cout<<endl;
		//---------------------
		curId=queue.front();
		queue.pop_front();
		PRINTVAR(curId);
		curNode=MAP_id2name[curId];
		cout<<"qpop "<<curId<<endl;
		// visit
		//PRINT_DEBUG_INFO();
		//PRINTVAR_hor(curId);
		//PRINTVAR(MAP_nodeId2color[curId]);

		//if(MAP_nodeId2color[curId]!=COLOR_WHITE)
		//{
		//	continue;
		//}
		//MAP_nodeId2color[curId]=COLOR_GREY;
		//visitedList.push_back(curId);

		//---------------------
		// do some thing
		if(func)
			func(curNode);
		//---------------------

		//---------------------
		// store child
		//
		vector<unsigned> childList=getChildIdList(curId);
		//
		for(unsigned c:childList)
		{
			if(MAP_nodeId2color[c]==COLOR_WHITE)
			{
				MAP_nodeId2color[c]=COLOR_GREY;
				MAP_id2BFSdepth[c] =MAP_id2BFSdepth[curId]+1;
				MAP_id2BFSparent[c]=curId;
				queue.push_back(c);
				cout<<"qpush "<<c<<endl;
			}
		}
		MAP_nodeId2color[curId]=COLOR_BLACK;
	}
};

