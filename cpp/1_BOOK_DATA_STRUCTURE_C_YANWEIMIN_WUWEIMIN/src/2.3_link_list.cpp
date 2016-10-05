#include "include.top.h"
using namespace std;

//===============================================================================
MyLinkList::MyLinkList() // a blank list, name is NA
{
	HeadPtr=NULL;
}
//===============================================================================
MyLinkList::MyLinkList(string name):m_name(name) // a blank list, name is NA
{
}
//===============================================================================
MyLinkList::MyLinkList(int[],int)
{}
//===============================================================================
MyLinkList::MyLinkList(int[],int,string)
{}
//===============================================================================
MyLinkList::MyLinkList(MyLinkList& other)//copying construct func
{}
//===============================================================================
MyLinkList & MyLinkList::operator=(MyLinkList& other)//copying construct func
{}
//===============================================================================
MyLinkList::~MyLinkList()
{}



//===============================================================================
void MyLinkList::ListUnshift(int e)
{
	cout<<"ListUnshift "<<e<<""<<endl;
	Node curNode=Node(e,HeadPtr);
	HeadPtr=&curNode;
}
//===============================================================================
int MyLinkList::ListShift()
{
	HeadPtr=HeadPtr->GetNext();
}

//===============================================================================
void MyLinkList::SetName(string s)
{
	m_name=s;
}
//===============================================================================
void MyLinkList::PrintItem(int)
{}
//===============================================================================
void MyLinkList::PrintList(int printLength,bool detailed) // default value setting is only allowed in declaration(h files)
{
	int cnt=0;
	Node* curPtr=HeadPtr;
	if(detailed){
		cout<<"PrintList details of <"<<m_name<<"> :"<<endl;
		while (curPtr!=NULL){

			cout<<"("<<cnt<<")"<<curPtr->GetData()<<endl;
			cnt++;
			curPtr=curPtr->GetNext();
			if (printLength!=-1&& cnt>printLength) {
				break;
			}
		}
		cout<<"============================="<<""<<endl;
	} else {
		cout<<"PrintList of <"<<m_name<<"> :"<<endl;
		while (curPtr!=NULL){

			cout<<curPtr->GetData()<<" ";
			cnt++;
			curPtr=curPtr->GetNext();
			if (printLength!=-1&& cnt>printLength) {
				break;
			}
		}
		cout<<endl;
		cout<<"============================="<<""<<endl;
	}
}
//===============================================================================
void MyLinkList::ClearList()
{}
//===============================================================================
bool MyLinkList::ListEmpty()
{}
//===============================================================================
int MyLinkList::ListLength()
{}
//===============================================================================
int MyLinkList::GetElem(int ind)
{}
//===============================================================================
void MyLinkList::SetElem(int ind,int value)
{}
//===============================================================================
int MyLinkList::LocateElem(int e,bool (*compare)(int,int)) // notice: the format of function-pointer
{}
//===============================================================================
int MyLinkList::PriorElem(int cur_e)
{}
//===============================================================================
int MyLinkList::NextElem (int cur_e)
{}
//===============================================================================
void MyLinkList::ListInsert(int ind , int e)
{}
//===============================================================================
void MyLinkList::ListPush(int e)
{}
//===============================================================================
int MyLinkList::ListPop()
{}
//===============================================================================
void MyLinkList::ListDelete(int ind )
{}
//===============================================================================
void MyLinkList::ListTraverse(bool (*visit)(int*),bool pre_order)
{}
//===============================================================================
void MyLinkList::ListUnion(MyLinkList&,MyLinkList& Lunion) // how to use the reference of a class
{}
//===============================================================================
void MyLinkList::ListSwap(int ind1,int ind2)
{}
//===============================================================================
void MyLinkList::ListSort()  // bubble sort
{}
//===============================================================================
void MyLinkList::ListReverse()  
{}
//===============================================================================
void MyLinkList::HeapRealloc()
{}
//===============================================================================
