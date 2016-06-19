#include "include.top.h"
using namespace std;

//===============================================================================
MyList::MyList(int a[], int len)
{
	m_list_length=len;
	m_heap_length=len*2; // use m_heap_length to give a margin in heap for ListInsert, etc.
	m_list_element=new int[m_heap_length] ;
	printf("DEBUG: m_list_element=%x\n",m_list_element);
	for(int i=0;i<len;i++)
	{
		*(m_list_element+i)=a[i];
		cout<<"init MyList:"<<*(m_list_element+i)<<endl;
	}
}
//===============================================================================
MyList::~MyList()
{
	delete [] m_list_element;
	m_list_element=NULL;
	printf("DEBUG delete: m_list_element=%x\n",m_list_element);
}
//===============================================================================
int MyList::ListLength()
{ 
	return m_list_length;
}
//===============================================================================
void MyList::PrintItem(int ind)
{
	cout<<"PrintItem("<<ind<<") = ("<<m_list_element+ind<<") "<<*(m_list_element+ind)<<endl;
}
//===============================================================================
void MyList::PrintList(int printLen,bool detailed) // default value setting is only allowed in declaration(h files)
{
	int max;
	if (printLen==-1) {
		max=m_list_length;
	} else {
		max=printLen;
	}

	if (detailed) {
		cout<<"PrintList details:"<<endl;
		for(int i=0;i<max;i++)
		{
			PrintItem(i);
		}
	}else {
		cout<<"PrintList:"<<endl;
		for(int i=0;i<max;i++)
		{
			cout<<*(m_list_element+i)<<" ";
		}
		cout<<endl;
	}
}

//===============================================================================
void MyList::ClearList()
{
	m_list_length=0;
	delete [] m_list_element;
	m_list_element=NULL;
	//printf("DEBUG clear: m_list_element=%d\n",m_list_element);
}
//===============================================================================
bool MyList::ListEmpty()
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
int MyList::GetElem(int ind)
{
	assert (ind<m_list_length) ;
	return *(m_list_element+ind);
}
//===============================================================================
int MyList::LocateElem(int e,bool (*compare)(int a,int b)) // notice: the format of function-pointer
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
int MyList::PriorElem(int cur_e)
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
int MyList::NextElem(int cur_e)
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
//int MyList::PriorElem(int cur_e)
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
//int MyList::NextElem(int cur_e)
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
void MyList::ListInsert(int ind , int e)
{
	for(int i=m_list_length-1;i>=0;i--)
	{
		if(i>=ind){
			printf("DEBUG: move (%x)%d->(%x)\n",m_list_element+i,*(m_list_element+i),m_list_element+i+1);
			*(m_list_element+i+1)=*(m_list_element+i);
		} 
		if(i==ind) {
			*(m_list_element+i)=e;
		}
	}
	m_list_length++;
}
//===============================================================================
void MyList::ListDelete(int ind )
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
void MyList::ListTraverse(bool (*visit)(int* a), bool pre_order)
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
