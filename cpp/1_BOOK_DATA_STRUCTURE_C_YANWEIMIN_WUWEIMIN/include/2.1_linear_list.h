class MyList 
{
	public:
		MyList(int[],int);
		~MyList();

		void PrintList(int);
		void ClearList();
		bool ListEmpty();
		int ListLength();
		int GetElem(int ind);
		int LocateElem(int e,bool (*compare)(int,int));
		//void PriorElem();
		//void NextElem();
		//void ListInsert();
		//void ListDelete();
		//void ListTraverse();
	private:
		int *m_list_element;
		int *m_list_relation;
		int m_list_length;
}; 
