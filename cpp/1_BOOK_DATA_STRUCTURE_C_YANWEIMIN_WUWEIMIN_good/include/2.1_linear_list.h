#include "include.top.h"
using namespace std;
//int instanceCounterMyList=-1;

class MyList 
{
	public:
		MyList(); // a blank list, name is NA
		MyList(int[],int);
		MyList(int[],int,string);
		MyList(MyList& other);//copying construct func
		MyList & operator=(MyList& other);//copying construct func
		~MyList();


		void SetName(string);
		void PrintItem(int);
		void PrintList(int printLength=-1,bool b=false); // default value setting is only allowed in declaration(h files)
		void ClearList();
		bool ListEmpty();
		int ListLength();
		int GetElem(int ind);
		void SetElem(int ind,int value);
		int LocateElem(int e,bool (*compare)(int,int)); // notice: the format of function-pointer
		int PriorElem(int cur_e);
		int NextElem (int cur_e);
		void ListInsert(int ind , int e);
		void ListPush(int e);
		int ListPop();
		void ListDelete(int ind );
		void ListTraverse(bool (*visit)(int*),bool pre_order=true);
		void ListUnion(MyList&,MyList& Lunion); // how to use the reference of a class
		void ListSwap(int ind1,int ind2);
		void ListSort();  // bubble sort
		void ListReverse();  
		//void ListSort(int start=0,int end=-1);  // quick sort
	private:
		string m_name;
		int *m_list_element;
		int *m_list_relation;
		int m_list_length;
		int m_heap_length;
}; 
