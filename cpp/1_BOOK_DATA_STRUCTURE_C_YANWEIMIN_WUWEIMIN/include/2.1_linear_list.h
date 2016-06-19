class MyList 
{
	public:
		MyList(int[],int);
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
		void ListDelete(int ind );
		void ListTraverse(bool (*visit)(int*),bool pre_order=true);
	private:
		int *m_list_element;
		int *m_list_relation;
		int m_list_length;
		int m_heap_length;
}; 
