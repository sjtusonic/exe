#include <vector>
#include <iostream>
#include <string>
#include <deque>
#include <type_traits> // for is_same
#include <typeinfo>
#include <assert.h>
#include "../POJ/include/lib.h"
using namespace std;



#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define PRINT_ARRAY(a,len)  for(int u=0;u<len;u++) {std::cout<<u<<":\t"<<*a+u<<std::endl;}
#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<std::endl;}
#define PRINT_VECTOR_hor(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;

#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)
#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )



template <typename DATA_TYPE>
class Node
{
	public:
		Node();
		Node(DATA_TYPE v);
		Node(DATA_TYPE v,Node* ns,Node* fc);
		void setmData(DATA_TYPE v){mData=v;};	
		DATA_TYPE getmData(){return mData;};
		void setmNextSibling(Node* v){mNextSibling=v;};	
		Node<DATA_TYPE>* getmNextSibling(){return mNextSibling;};

		Node<DATA_TYPE>* getmNextNSibling(int n=1);

		void setmFirstChild(Node* v){mFirstChild=v;};	
		Node* getmFirstChild(){return mFirstChild;};
		void setmIdInATree(string v){mIdInATree=v;};
		string getmIdInATree(){ return mIdInATree; };
		void show();
	private:
		DATA_TYPE mData;
		Node* mNextSibling;
		Node* mFirstChild;
		string mIdInATree;
};


#define NODE_T Node<NODE_DATA_TYPE>
template <typename NODE_DATA_TYPE>
class Tree 
{
	public:
		Tree();
		~Tree();
		void insertNode(NODE_T* brother,	NODE_T* newNode) ;
		void insertNode(NODE_T* parent,			unsigned nth,	NODE_DATA_TYPE newNodeData);
		void insertNode(NODE_T* parent,			unsigned nth,	NODE_T* newNode);
		//void insertNode(NODE_T* parent,NODE_T* newNode);
		void deleteNode(string id);
		void deleteNode(NODE_T* targetNode);
		NODE_T* getRoot();
		NODE_T* getNodeById(string id);
	public:
		void show();
		void traverseDFS(void (*func)(NODE_T*)=0){traverseDFS(Root,"0",func);};
		void traverseBFS(void (*func)(NODE_T*)=0){traverseBFS(Root,"0",func);};
		void traverseDFS(NODE_T* fromNode,string fromNodeId="",void (*func)(NODE_T*)=0);
		void traverseBFS(NODE_T* fromNode,string fromNodeId="",void (*func)(NODE_T*)=0);
	private:
		std::vector<NODE_T*> list;
		NODE_T* Root;
	private:
		static void _print_used_in_show(Node<int>* node);
};
