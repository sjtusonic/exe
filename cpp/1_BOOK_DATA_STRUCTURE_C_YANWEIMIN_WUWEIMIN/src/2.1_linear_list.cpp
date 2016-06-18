#include "include.top.h"
using namespace std;

MyList::MyList(int a[], int len)
{
	m_list_length=len;
	m_list_element=new int[len] ;
	printf("DEBUG: m_list_element=%d\n",m_list_element);
	for(int i=0;i<len;i++)
	{
		*(m_list_element+i)=a[i];
		cout<<"init MyList:"<<*(m_list_element+i)<<endl;
	}
}
MyList::~MyList()
{
	delete [] m_list_element;
	m_list_element=NULL;
	printf("DEBUG delete: m_list_element=%d\n",m_list_element);
}
int MyList::ListLength()
{ 
	return m_list_length;
}
void MyList::PrintList(int printLen=-1)
{
	int max;
	if (printLen==-1) {
		max=m_list_length;
	} else {
		max=printLen;
	}

	cout<<"PrintList:"<<endl;
	for(int i=0;i<max;i++)
	{
		cout<<*(m_list_element+i)<<" ";
	}
	cout<<endl;
}

void MyList::ClearList()
{
	m_list_length=0;
	delete [] m_list_element;
	m_list_element=NULL;
	//printf("DEBUG clear: m_list_element=%d\n",m_list_element);
}
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
int MyList::GetElem(int ind)
{
	assert (ind<m_list_length) ;
	return *(m_list_element+ind);
}
int MyList::LocateElem(int e,bool (*compare)(int a,int b))
{
	for(int i=0;i<m_list_length;i++)
	{
		cout<<"DEBUG: compare"<<*(m_list_element+i)<<","<<e<<endl;
		if(compare(*(m_list_element+i),e)){
			return i;
		}
	}
	return -1;
}
