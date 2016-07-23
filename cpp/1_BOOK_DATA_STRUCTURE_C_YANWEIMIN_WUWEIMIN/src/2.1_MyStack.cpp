#include "include.top.h"
using namespace std;

//===============================================================================
MyStack::MyStack():MyList() {// FUNC
	cout<<"Info: construct MyStack"<<endl;
}
//===============================================================================
MyStack::MyStack(string name):MyList() {// FUNC
	cout<<"Info: construct MyStack"<<endl;
	SetName(name);
}
//===============================================================================
void MyStack::Push(int e) // FUNC
{
	ListPush(e);
}
//===============================================================================
int MyStack::Pop() // FUNC
{
	return ListPop();
}
//===============================================================================
int MyStack::Shift() // FUNC
{
	int r=GetElem(0);
	ListDelete(0);
	return r;
}
//===============================================================================
void MyStack::Unshift(int e) // FUNC
{
	ListInsert(0,e);
}
