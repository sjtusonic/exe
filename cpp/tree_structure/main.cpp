#include <string>
#include <deque>
#include "../POJ/include/lib.h"

#include "tree.class.h"
#include "tree.class.cpp" // to write templated class into h/cpp files separately, h/cpp should included both into main.cpp to fix compile errors

using namespace std;
void f(Node<int>* node);

int main()
{
	//tree<> T;
	std::cout<<"NODE:"<<std::endl;
	Node<int> n(3);
	n.show();
	Node<int> m;
	m.show();
	std::cout<<"TREE:"<<std::endl;
	Tree<int> T;
	T.insertNode(T.getRoot(),0,2);
	T.insertNode(T.getRoot(),0,1);
	T.insertNode(T.getRoot(),0,0);
	T.insertNode(T.getNodeById("0_1"),0,12);
	T.insertNode(T.getNodeById("0_1"),0,11);
	T.insertNode(T.getNodeById("0_1"),0,10);
	T.insertNode(T.getNodeById("0_1_1"),0,111);
	T.insertNode(T.getNodeById("0_1_1"),0,110);
	PRINT_DEBUG_INFO();
	std::cout<<"=================================="<<std::endl;
	std::cout<<"TRAVERSE BFS:"<<std::endl;
	T.traverseBFS(f);
	std::cout<<"=================================="<<std::endl;
	std::cout<<"=================================="<<std::endl;
	std::cout<<"TRAVERSE DFS:"<<std::endl;
	T.traverseDFS(f);
	std::cout<<"=================================="<<std::endl;
	//auto nn=T.getNodeById("0_1_1_0");
	std::cout<<"=================================="<<std::endl;
	std::cout<<"SHOW:"<<std::endl;
	//T.traverseDFS(Tree<int>::_print_used_in_show);
	//T.traverseDFS(f);
	T.show();
	std::cout<<"=================================="<<std::endl;

	/*
	// Create a deque containing integers
	std::deque<int> d = {7, 5, 16, 8};

	// Add an integer to the beginning and end of the deque
	d.push_back(13);
	d.push_back(14);
	d.push_back(15);
	PRINTVAR(d.front());
	d.pop_front();
	PRINTVAR(d.front());
	d.pop_front();
	PRINTVAR(d.front());
	d.pop_front();


	// Iterate and print values of deque
	for(int n : d) {
	std::cout << n << '\n';
	}
	*/
	return 0;
};

void f(Node<int>* node)
{
	cout<<"do for node:"<<node->getmIdInATree()<<"\t@"<<node<<endl;
}
