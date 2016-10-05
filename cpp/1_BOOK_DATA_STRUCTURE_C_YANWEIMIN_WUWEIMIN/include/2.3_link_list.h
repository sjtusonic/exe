#ifndef M_2_3_LINK_LIST_H
#define M_2_3_LINK_LIST_H
class Node{
public:
	Node(){
	}
	Node(int d ,Node* p)
	{
		m_data=d;
		m_next=p;
	}
	~Node()
	{
	}
	int GetData(){return m_data;}
	Node* GetNext(){
		return m_next;
	}
private:
	int m_data;
	Node* m_next;
};

class MyLinkList {
	public:
		MyLinkList(); // a blank list, name is NA
		MyLinkList(string name);
		MyLinkList(int[],int);
		MyLinkList(int[],int,string);
		MyLinkList(MyLinkList& other);//copying construct func
		MyLinkList & operator=(MyLinkList& other);//copying construct func
		~MyLinkList();


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
		void ListUnshift(int e);
		int ListShift();
		void ListDelete(int ind );
		void ListTraverse(bool (*visit)(int*),bool pre_order=true);
		void ListUnion(MyLinkList&,MyLinkList& Lunion); // how to use the reference of a class
		void ListSwap(int ind1,int ind2);
		void ListSort();  // bubble sort
		void ListReverse();  
		void HeapRealloc();

	private:
		Node* HeadPtr;
		string m_name;
	
};
//LNode * head;
#endif //M_2_3_LINK_LIST_H
