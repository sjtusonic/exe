#ifndef M_2_1_MYSTACK_H
#define M_2_1_MYSTACK_H
#include "include.top.h"
using namespace std;
//int instanceCounterMyList=-1;

class MyStack:public MyList
{
	public:
		MyStack();
		MyStack(string);

		void Push(int e);
		int Pop();
		void Unshift(int e);
		int Shift();
	//private:
		//string m_name;
		//int *m_list_element;
		//int *m_list_relation;
		//int m_list_length;
		//int m_heap_length;
}; 
#endif //M_2_1_MYSTACK_H
