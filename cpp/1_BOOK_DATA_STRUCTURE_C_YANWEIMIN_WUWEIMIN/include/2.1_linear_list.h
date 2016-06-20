class MyList 
{
	public:
		MyList(int[],int);
		MyList(MyList& other);//copying construct func
		MyList & operator=(MyList& other);//copying construct func
		~MyList();


		void PrintItem(int);
		void PrintList(int printLength=-1,bool b=false); // default value setting is only allowed in declaration(h files)
		void ClearList();
		bool ListEmpty();
		int ListLength();
		int GetElem(int ind);
		int LocateElem(int e,bool (*compare)(int,int)); // notice: the format of function-pointer
		int PriorElem(int cur_e);
		int NextElem (int cur_e);
		void ListInsert(int ind , int e);
		void ListPush(int e);
		int ListPop();
		void ListDelete(int ind );
		void ListTraverse(bool (*visit)(int*),bool pre_order=true);
		void ListUnion(MyList&,MyList& Lunion); // how to use the reference of a class
	private:
		int *m_list_element;
		int *m_list_relation;
		int m_list_length;
		int m_heap_length;
}; 
