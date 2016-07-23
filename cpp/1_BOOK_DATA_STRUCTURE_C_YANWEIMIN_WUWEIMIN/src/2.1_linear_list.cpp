#include "include.top.h"
using namespace std;

//===============================================================================
MyList::MyList() // FUNC
{
	cout<<"Info: construct MyList"<<endl;
	int len=0;
	m_name="NA";
	m_list_length=len;
	//m_heap_length=len*2; // use m_heap_length to give a margin in heap for ListInsert, etc.
	m_heap_length=LIST_INIT_SIZE; 
	//m_list_element=new int[m_heap_length] ;
	m_list_element=(int*)malloc(LIST_INIT_SIZE*sizeof(int));
	HeapRealloc();
	for(int i=len;i<m_heap_length;i++) 
	{
		*(m_list_element+i)=-1;
	}
}
//===============================================================================
MyList::MyList(int a[], int len) // FUNC
{
	//m_name="NA";
	MyList(a,len,"NA");
}
//===============================================================================
MyList::MyList(int a[], int len, string n) // FUNC
{
	//instanceCounterMyList++;
	m_name=n;
	m_list_length=len;
	//m_heap_length=len*2; // use m_heap_length to give a margin in heap for ListInsert, etc.
	m_heap_length=LIST_INIT_SIZE;
	//m_list_element=new int[m_heap_length] ;
	m_list_element=(int*)malloc(m_heap_length*sizeof(int));
	HeapRealloc();
	printf("DEBUG: INIT MyList, m_list_element=%x\n",m_list_element);
	cout<<"name is:"<<m_name<<endl;
	for(int i=0;i<len;i++)
	{
		*(m_list_element+i)=a[i];
		cout<<"init MyList:"<<*(m_list_element+i)<<endl;
	}
	//for(int i=len;i<m_heap_length;i++) // it's necessary to init the [m_list_length,m_heap_length), or Valgrind checker will release Error because of mem does not initialised.
	//{
	//	*(m_list_element+i)=-1;
	//}
}
//===============================================================================
MyList::MyList(MyList& other) //copying construct func // FUNC
{
	printf("DEBUG: calling copying constructor\n");
	m_name="COPY_"+other.m_name;
	cout<<"name is:"<<m_name<<endl;
	int len=other.ListLength();
	m_list_length=len;
	//m_heap_length=len*2; // use m_heap_length to give a margin in heap for ListInsert, etc.
	m_heap_length=LIST_INIT_SIZE; 
	//m_list_element=new int[m_heap_length] ;
	m_list_element=(int*)malloc(m_heap_length*sizeof(int));
	HeapRealloc();
	//printf("THIS=%d\x",this);
	printf("DEBUG: m_list_element=%x\n",m_list_element);
	for(int i=0;i<len;i++)
	{
		*(m_list_element+i)=other.GetElem(i);
		cout<<"init MyList copy constructor:"<<*(m_list_element+i)<<endl;
	}
	for(int i=len;i<m_heap_length;i++)
	{
		*(m_list_element+i)=-1;
	}
}
//===============================================================================
MyList & MyList::operator=(MyList& other) //copying construct func // FUNC
{
	if(this==&other)
		return *this;

	printf("DEBUG: calling operator =\n");
	m_name="EQUAL_"+other.m_name;
	cout<<"name is:"<<m_name<<endl;
	ClearList();
	int len=other.ListLength();
	m_list_length=len;
	//m_heap_length=len*2; // use m_heap_length to give a margin in heap for ListInsert, etc.
	m_heap_length=LIST_INIT_SIZE;
	//m_list_element=new int[m_heap_length] ;
	m_list_element=(int*)malloc(m_heap_length*sizeof(int));
	HeapRealloc();
	//printf("DEBUG: m_list_element=%x\n",m_list_element);
	for(int i=0;i<m_heap_length;i++)
	{
		if (i<m_list_length) {
			*(m_list_element+i)=other.GetElem(i);
			cout<<"init MyList copy constructor:"<<*(m_list_element+i)<<endl;
		} else {
			*(m_list_element+i)=-1;
		}
	}
}
//===============================================================================
MyList::~MyList() // FUNC
{
	//delete [] m_list_element;
	free(m_list_element);
	m_list_element=NULL;
	//printf("DEBUG delete: m_list_element=%x\n",m_list_element);
	cout<<"DEBUG delete MyList <"<<m_name<<"> m_list_element="<<m_list_element<<endl;
}
//===============================================================================
void MyList::HeapRealloc() // FUNC
{
	int m_heap_length_bk=m_heap_length;
	//while (m_list_length>m_heap_length) 
	//{
	//	// use realloc to handle mem space opened by 'new', will cause valgrind Error
	//	int *newbase=(int*)realloc(m_list_element,(m_heap_length+LIST_INCR_SIZE)*sizeof(int));
	//	if(!newbase) exit(OVERFLOW);
	//	cout<<"DEBUG: newbase="<<newbase<<endl;
	//	m_list_element=newbase;
	//	m_heap_length+=LIST_INCR_SIZE;
	//	cout<<"Info:MyList::HeapRealloc(): add more heap size to"<<m_heap_length<<endl;
	//}
	//m_list_element=new int[m_heap_length] ;
	//m_list_element=(int*)malloc(m_heap_length*sizeof(int));
	
	// use realloc to handle mem space opened by 'new', will cause valgrind Error
	
	printf("DEBUG HeapRealloc: m_list_length=%d;m_heap_length=%d\n",m_list_length,m_heap_length);
	if (m_list_length<=m_heap_length) {//no need to realloc
		return;
	}
	m_heap_length=m_list_length;
	cout <<"DEBUG: HeapRealloc from:"<<m_heap_length_bk<<" to:"<<m_heap_length<<endl;
	int *newbase=(int*)realloc(m_list_element,m_heap_length*sizeof(int));
	for(int i=m_heap_length_bk;i<m_heap_length;i++)
	{
		cout <<"DEBUG: init for address:"<<m_list_element+i<<endl;
		*(m_list_element+i)=-1;
	}
}
//===============================================================================
void MyList::SetName(string n) // FUNC
{
	m_name=n;
}

//===============================================================================
int MyList::ListLength() // FUNC
{ 
	return m_list_length;
}
//===============================================================================
void MyList::PrintItem(int ind) // FUNC
{
	cout<<"PrintItem("<<ind<<") = ("<<m_list_element+ind<<") "<<*(m_list_element+ind)<<endl;
}
//===============================================================================
void MyList::PrintList(int printLen,bool detailed) // default value setting is only allowed in declaration(h files) // FUNC
{
	int max;
	if (printLen==-1) {
		max=m_list_length;
	} else {
		max=printLen;
	}

	if (detailed) {
		cout<<"PrintList details of <"<<m_name<<"> :"<<endl;
		for(int i=0;i<max;i++)
		{
			PrintItem(i);
		}
	}else {
		cout<<"PrintList of <"<<m_name<<"> :"<<endl;
		for(int i=0;i<max;i++)
		{
			cout<<*(m_list_element+i)<<" ";
		}
		cout<<endl;
	}
}

//===============================================================================
void MyList::ClearList() // FUNC
{
	m_list_length=0;
	//delete [] m_list_element;
	free(m_list_element);
	m_list_element=NULL;
	//printf("DEBUG clear: m_list_element=%d\n",m_list_element);
}
//===============================================================================
bool MyList::ListEmpty() // FUNC
{	
	if (m_list_element==NULL) {
		return true;
	}
	if (m_list_length==0) {
		return true;
	}
	return false;
}
//===============================================================================
int MyList::GetElem(int ind) // FUNC
{
	assert (ind<m_list_length) ;
	return *(m_list_element+ind);
}
//===============================================================================
void MyList::SetElem(int ind,int value) // FUNC
{
	assert (ind<m_list_length) ;
	*(m_list_element+ind)=value;
}
//===============================================================================
int MyList::LocateElem(int e,bool (*compare)(int a,int b)) // notice: the format of function-pointer // FUNC
{
	for(int i=0;i<m_list_length;i++)
	{
		cout<<"DEBUG: compare "<<*(m_list_element+i)<<","<<e<<endl;
		if(compare(*(m_list_element+i),e)){
			return i;
		}
	}
	return -1;
}
//===============================================================================
int MyList::PriorElem(int cur_e) // FUNC
{	
  	cout<<"DEBUG: calling MyList::PriorElem "<<cur_e<<endl;
	int ind=LocateElem(cur_e,compare);
	if (ind!=0) {
		return GetElem(ind-1);
	} else {
		return NULL;
	}
}
//===============================================================================
int MyList::NextElem(int cur_e) // FUNC
{
  	cout<<"DEBUG: calling MyList::NextElem "<<cur_e<<endl;
	int ind=LocateElem(cur_e,compare);
	if (ind!=m_list_length-1) {
		return GetElem(ind+1);
	} else {
		return NULL;
	}
}
//===============================================================================
//int MyList::PriorElem(int cur_e) // FUNC
//{	
//	int*pre_e;
//	cout<<"DEBUG: calling MyList::PriorElem "<<cur_e<<endl;
//	if (ListEmpty()) {
//		//pre_e=NULL;
//		return NULL;
//	}
//	for(int i=1;i<m_list_length;i++)
//	{
//		//cout<<"DEBUG: compare"<<*(m_list_element+i)<<","<<cur_e<<endl;
//		cout<<"DEBUG: compare "<<*(m_list_element+i)<<"("<<m_list_element+i<<")"<<","<<cur_e<<endl;
//		if(cur_e==*(m_list_element+i)){
//			pre_e=m_list_element+i-1;
//			return *pre_e;
//		}
//	}
//	pre_e=NULL;
//	return NULL;
//}
//===============================================================================
//int MyList::NextElem(int cur_e) // FUNC
//{	
//	int*next_e;
//	cout<<"DEBUG: calling MyList::NextElem "<<cur_e<<endl;
//	if (ListEmpty()) {
//		//next_e=NULL;
//		return NULL;
//	}
//	for(int i=0;i<m_list_length-1;i++)
//	{
//		cout<<"DEBUG: compare"<<*(m_list_element+i)<<"("<<m_list_element+i<<")"<<","<<cur_e<<endl;
//		if(cur_e==*(m_list_element+i)){
//			next_e=m_list_element+i+1;
//			return *next_e;
//		}
//	}
//	next_e=NULL;
//	return NULL;
//}
//===============================================================================
//cout<<""<<<<""<<<<""<<<<""<<<<""<<<<""<<<<""<<<<""<<<<""<<<<""<<<<""<<<<""<<<<""<<<<""<<<<""<<<<""<<<<""<<<<""<<<<""<<<<""<<endl;
void MyList::ListInsert(int ind , int e) // FUNC
{
	if (ind>m_list_length || ind<0) {
		printf("MyList::ListInsert fail: index=%d,m_list_length=%d",ind,m_list_length);
		return;
	}
	for(int i=m_list_length;i>=0;i--)
	{
		int* ind_ptr=m_list_element+i;
		if(i>=ind){
			printf("DEBUG: move (%x)%d->(%x)\n",m_list_element+i,*(m_list_element+i),m_list_element+i+1);
			//cout<<"DEBUG: move ("<<<<""<<<<<<<<<<<<<<endl;
			//cout<<"DEBUG: move ("<<m_list_element+i<<")"<<*(m_list_element+i)<<"->("<<m_list_element+i+1<<")"<<endl;
			//cout<<"DEBUG: move ("<<ind_ptr<<")"<<*(ind_ptr)<<"->("<<m_list_element+i+1<<")"<<endl;
			*(m_list_element+i+1)=*(m_list_element+i);
		} 
		if(i==ind) {
			*(m_list_element+i)=e;
		}
	}
	m_list_length++;
}
//===============================================================================
void MyList::ListPush(int e) // FUNC
{
	ListInsert(m_list_length,e);
}
//===============================================================================
int MyList::ListPop() // FUNC
{
	int r =GetElem(m_list_length-1);
	m_list_length--;
	return r;
}
//===============================================================================
void MyList::ListDelete(int ind ) // FUNC
{
	for(int i=0;i<m_list_length;i++)
	{
		if(i>=ind){
			printf("DEBUG: move (%x)%d->(%x)\n",m_list_element+i+1,*(m_list_element+i),m_list_element+i);
			*(m_list_element+i)=*(m_list_element+i+1);
		} 
	}
	m_list_length--;
}
//===============================================================================
void MyList::ListTraverse(bool (*visit)(int* a), bool pre_order) // FUNC
{
	if (pre_order) {
		for(int i=0;i<m_list_length;i++)
		{
			visit(m_list_element+i);
		}
	} else {
		for(int i=m_list_length-1;i>=0;i--)
		{
			visit(m_list_element+i);
		}
	}
}
//===============================================================================
void MyList::ListUnion(MyList& b,MyList & Lunion) // FUNC
{
	cout<<"print b:============================"<<endl;
	b.PrintList();
	Lunion=b;
	Lunion.SetName("Lunion");
	//Lunion.PrintList();
	for(int i=0;i<m_list_length;i++)
	{
		if(b.LocateElem(GetElem(i),compare)==-1) 
		{
			Lunion.ListPush(GetElem(i));
		}
	}
}
//===============================================================================
void MyList::ListSwap(int ind1,int ind2) // FUNC
{
	if (  ind1<0 || ind1>=m_list_length
		|| ind2<0 || ind2>=m_list_length
		|| ind1==ind2)
	{
		return ;
	}
	int tmp=GetElem(ind1);
	SetElem(ind1,GetElem(ind2));
	SetElem(ind2,tmp);
}
//===============================================================================
void MyList::ListSort()// bubble sort // FUNC
{
	for(int range=m_list_length-1;range>=0;range--)
	{
		for(int i=0;i<range;i++)
		{
			if(GetElem(i)>GetElem(i+1))
			{
				ListSwap(i,i+1);
			}
		}
	}
}
//===============================================================================
void MyList::ListReverse()// Reverse // FUNC
{
	int list_length_bk=m_list_length;
	int ll[list_length_bk];
	int ind=0;

	while (!ListEmpty())
	{
		ll[ind++]=ListPop();
	}
	for(int i=0;i<list_length_bk;i++)
	{
		ListPush(ll[i]);
	}
}


