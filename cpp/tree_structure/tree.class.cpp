// NODE CLASS
	template <typename DATA_TYPE>
Node<DATA_TYPE>::Node()
{
	mData=0;
	mNextSibling=0;
	mFirstChild=0;
	mIdInATree="";
}
template <typename DATA_TYPE>
Node<DATA_TYPE>::Node(DATA_TYPE v){
	mData=v;
	mNextSibling=0;
	mFirstChild=0;
	mIdInATree="";
};
template <typename DATA_TYPE>
Node<DATA_TYPE>::Node(DATA_TYPE v,Node* ns,Node* fc){
	mData=v;
	mNextSibling=ns;
	mFirstChild=fc;
	mIdInATree="";
};
template <typename DATA_TYPE>
Node<DATA_TYPE>* Node<DATA_TYPE>::getmNextNSibling(int n){
	assert(n>=0);
	if(n==0)
		return this;
	if(n==1)
		return mNextSibling;
	else
		return mNextSibling->getmNextNSibling(n-1);
};
template <typename DATA_TYPE>
void Node<DATA_TYPE>::show(){
	std::cout<<"----------------------------------------------------------------------------------------------------"<<std::endl;
	std::cout<<"Node obj at      =\t"<<this<<std::endl;
	std::cout<<"Node mData       =\t"<<mData<<std::endl;
	std::cout<<"Node mNextSibling=\t"<<mNextSibling<<std::endl;
	std::cout<<"Node mFirstChild =\t"<<mFirstChild<<std::endl;
	std::cout<<"Node mIdInATree  =\t"<<mIdInATree<<std::endl;
	std::cout<<"----------------------------------------------------------------------------------------------------"<<std::endl;
};
// TREE CLASS
template <typename NODE_DATA_TYPE>
Tree<NODE_DATA_TYPE>::Tree(){
	Root=new NODE_T();
	list.push_back(Root);
};
template <typename NODE_DATA_TYPE>
Tree<NODE_DATA_TYPE>::~Tree(){
	for(auto n:list)
	{
		delete n;
	}
	//delete Root;
}
	template <typename NODE_DATA_TYPE>
void Tree<NODE_DATA_TYPE>::insertNode(NODE_T* brother,NODE_T* newNode) 
{
	assert(brother);
	newNode->setmNextSibling(brother->getmNextSibling());
	brother->setmNextSibling(newNode);
	return;
};
	template <typename NODE_DATA_TYPE>
void Tree<NODE_DATA_TYPE>::insertNode(NODE_T* parent,unsigned nth,NODE_DATA_TYPE newNodeData)
{
	PRINT_DEBUG_INFO();
	Node<NODE_DATA_TYPE>* newNode=new NODE_T(newNodeData);
	insertNode(parent,nth, newNode);
};
	template <typename NODE_DATA_TYPE>
void Tree<NODE_DATA_TYPE>::insertNode(NODE_T* parent,unsigned nth,NODE_T* newNode)
{
	PRINT_DEBUG_INFO();
	list.push_back(newNode);
	bool flag_got_parent_node=false;
	for(auto p:list)
	{
		if(p==parent)
		{
			flag_got_parent_node=true;
			break;
		}
	}
	if(!flag_got_parent_node)
	{
		std::cout<<"in insertNode(), cannot get parent node: "<<parent<<std::endl;
		return;
	}
	NODE_T* target;
	PRINT_DEBUG_INFO();
	if(nth==0)
	{
		PRINT_DEBUG_INFO();
		target=parent;
		assert(target);
		newNode->setmNextSibling(target->getmFirstChild());
		target->setmFirstChild(newNode);
		return;
	}
	else if(nth==1)
	{
		PRINT_DEBUG_INFO();
		target=parent->getmFirstChild();
		assert(target);
		newNode->setmNextSibling(target->getmNextSibling());
		target->setmNextSibling(newNode);
		return;
	}
	else
	{
		PRINT_DEBUG_INFO();
		target=parent->getmFirstChild();
		assert(target);
		int cntr=nth;
		while(cntr!=0)
		{
			target=target->getmNextSibling();
			cntr--;
		}
		assert(target);
		newNode->setmNextSibling(target->getmNextSibling());
		target->setmNextSibling(newNode);
		return;
	}
};
//template <typename NODE_DATA_TYPE>
//void Tree<NODE_DATA_TYPE>::insertNode(NODE_T* parent,NODE_T* newNode)
//{
//	unsigned i=0;
//	insertNode(parent,i,newNode);
//};
	template <typename NODE_DATA_TYPE>
void Tree<NODE_DATA_TYPE>::deleteNode(string id)
{
	if(id=="0") // you cannot delete root node
		assert(0);
	vector<int> idVector=stoi(split(id,"_"));
	NODE_T* curNode=Root->getmFirstChild();
	NODE_T* lastNode=Root;
	assert(curNode);
	int ind=1;
	PRINTVAR(idVector.size());
	while(ind<idVector.size())
	{
		int nth=idVector[ind];
		assert(curNode);
		lastNode=curNode;
		curNode=curNode->getmNextNSibling(nth);
		assert(curNode);

		if(ind!=idVector.size()-1) // if not reach the target node, go one level deeper
		{
			lastNode=curNode;
			curNode=curNode->getmFirstChild();
		}
		ind++;
	}

	if(id.back()=='0') // is the first child
		lastNode->setmFirstChild(curNode->getmNextSibling());
	else
		lastNode->setmNextSibling(curNode->getmNextSibling());

	return ;
}
	template <typename NODE_DATA_TYPE>
void Tree<NODE_DATA_TYPE>::deleteNode(NODE_T* targetNode)
{
}
	template <typename NODE_DATA_TYPE>
NODE_T* Tree<NODE_DATA_TYPE>::getRoot()
{
	//return list[0];
	return Root;
};
	template <typename NODE_DATA_TYPE>
NODE_T* Tree<NODE_DATA_TYPE>::getNodeById(string id)
{
	if(id=="0")
		return Root;
	vector<int> idVector=stoi(split(id,"_"));
	NODE_T* curNode=Root->getmFirstChild();
	assert(curNode);
	int ind=1;
	PRINTVAR(idVector.size());
	while(ind<idVector.size())
	{
		PRINTVAR(ind);
		int nth=idVector[ind];
		PRINTVAR(nth);
		assert(curNode);
		curNode->show();
		curNode=curNode->getmNextNSibling(nth);
		assert(curNode);

		if(ind!=idVector.size()-1) // if not reach the target node, go one level deeper
			curNode=curNode->getmFirstChild();
		ind++;
	}

	return curNode;
};
// zjc 
	template <typename NODE_DATA_TYPE>
void Tree<NODE_DATA_TYPE>::_print_used_in_show(Node<int>* node)
{
	int lv=split(node->getmIdInATree(),"_").size();
	while(lv!=0)
	{
		cout<<"\t";
		lv--;
	}
	cout<<node->getmIdInATree()<<"\t@"<<node<<endl;
}

	template <typename NODE_DATA_TYPE>
void Tree<NODE_DATA_TYPE>::show()
{
	traverseDFS(Root,"0",_print_used_in_show);
	//traverseDFS(Root,"0");
};
template <typename NODE_DATA_TYPE>
void Tree<NODE_DATA_TYPE>::traverseDFS(NODE_T* fromNode,string fromNodeId,void (*func)(NODE_T*))
{
	vector<int> curIdInATreeVec;
	if(fromNodeId!="")
	{
		fromNode->setmIdInATree(fromNodeId);
		curIdInATreeVec=stoi(split(fromNodeId,"_"));
	}
	else 
	{
		fromNode->setmIdInATree("0");
		curIdInATreeVec.push_back(0);
	}
	//std::cout<<"calling traverseDFS for:\t"<<fromNode->getmData()<<"\t@"<<fromNode<<std::endl;
	NODE_T* curNode=fromNode;
	//curNode->show();
	// do some thing
	if(func)
		func(curNode);
	if(curNode->getmFirstChild())
	{
		NODE_T* curChild=curNode->getmFirstChild();
		curIdInATreeVec.push_back(0);
		traverseDFS(curChild,join(itos(curIdInATreeVec),"_"),func);
		while(curChild->getmNextSibling())
		{
			curChild=curChild->getmNextSibling();
			//
			int curIdTail=curIdInATreeVec.back();
			curIdTail++;
			curIdInATreeVec.pop_back();
			curIdInATreeVec.push_back(curIdTail);
			//
			traverseDFS(curChild,join(itos(curIdInATreeVec),"_"),func);
			//traverseDFS(curChild);
		}
	}
};
template <typename NODE_DATA_TYPE>
void Tree<NODE_DATA_TYPE>::traverseBFS(NODE_T* fromNode,string fromNodeId,void (*func)(NODE_T*))
{
	vector<int> curIdInATreeVec;
	if(fromNodeId!="")
	{
		//PRINTVAR(fromNodeId);
		fromNode->setmIdInATree(fromNodeId);
		curIdInATreeVec=stoi(split(fromNodeId,"_"));
	}
	else 
	{
		fromNode->setmIdInATree("0");
		curIdInATreeVec.push_back(0);
	}
	//std::cout<<"calling traverseBFS for:\t"<<fromNode->getmData()<<"\t@"<<fromNode<<std::endl;
	NODE_T* curNode=fromNode;
	//curNode->show();

	std::deque<NODE_T*> queue;
	queue.push_back(curNode);
	while(queue.size()!=0)
	{
		curNode=queue.front();
		queue.pop_front();
		// do some thing
		if(func)
			func(curNode);
		int cnt_child=0;
		NODE_T* curChild=curNode->getmFirstChild();
		if(!curChild)
			continue;

		vector<int> baseIdVec= stoi(
				split(curNode->getmIdInATree(),"_")
				);

		baseIdVec.push_back(cnt_child);
		//PRINTVAR( join( itos(baseIdVec) ,"_"));
		curChild->setmIdInATree(
				join(
					itos(baseIdVec)
					,"_"
					)
				);
		baseIdVec.pop_back();

		//PRINTVAR(cnt_child);
		while(curChild)
		{
			queue.push_back(curChild);
			curChild=curChild->getmNextSibling();
			//PRINTVAR(curChild);
			if(!curChild)
				break;
			cnt_child++;
			//PRINTVAR(cnt_child);

			baseIdVec.push_back(cnt_child);
			//PRINTVAR( join( itos(baseIdVec) ,"_"));
			curChild->setmIdInATree(
					join(
						itos(baseIdVec)
						,"_"
						)
					);
			baseIdVec.pop_back();

		}
	}
};
