#include "include.top.h"
using namespace std;

int f_test_linear_list() { // FUNC
	int u[5]={101,77,303,7,21};
	MyList l0(u,15,"l0");
	//MyList l0(u,23);
	l0.PrintList(l0.ListLength(),true);
	return 0;
	cout<<l0.ListLength()<<endl;
	MyList l1(u,5,"l1");
	MyList lX(l1);
	l1.PrintList(5);
	l1.PrintList(5,true);
	cout<<"LENGTH="<<l1.ListLength()<<endl;
	cout<<"GET ELEMENT="<<l1.GetElem(4)<<endl;
	if (0) { 
		cout<<"ClearList..."<<endl;
		l1.ClearList();
		cout<<"GET ELEMENT="<<l1.GetElem(4)<<endl; // will cause segment fault
	}

	cout<<"LocateElem:"<<endl;
	cout<<l1.LocateElem(3,compare)<<endl;

	cout<<"copy constructor:============"<<endl;
	MyList ltemp(l1);
	l1.PrintList(-1,true);
	ltemp.PrintList(-1,true);
	//return 0;
	cout<<"PriorElem:============"<<endl;
	cout<<l1.PriorElem(7)<<endl;
	printf("NextElem:===================\n");
	cout<<l1.NextElem(1)<<endl;
	printf("ListInsert:===================\n");
	l1.PrintList(-1,true);
	l1.ListInsert(5,999);
	l1.PrintList(-1,true);
	//return 0;
	printf("ListDelete:===================\n");
	l1.PrintList(-1,true);
	l1.ListDelete(5);
	l1.PrintList(-1,true);
	printf("ListTraverse,pre_order:===================\n");
	l1.ListTraverse(visit);
	printf("ListTraverse,post_order:===================\n");
	l1.ListTraverse(visit,false);
	printf("ListPush:=========\n");
	l1.PrintList(-1);
	l1.ListPush(9);
	l1.ListPush(8);
	l1.ListPush(7);
	l1.PrintList(-1);
	printf("ListPop:=========\n");
	l1.PrintList(-1);
	cout<<l1.ListPop()<<endl;
	cout<<l1.ListPop()<<endl;
	cout<<l1.ListPop()<<endl;
	cout<<l1.ListPop()<<endl;
	cout<<l1.ListPop()<<endl;
	l1.PrintList(-1);
	printf("ListUnion:=========\n");
	return 0;
	l1.PrintList(-1);
	int v[5]={33,44,55,66,77};
	MyList l2(v,5,"l2");
	l2.PrintList(-1);
	MyList lunion(v,5,"lunion");
	l1.ListUnion(l2,lunion);
	lunion.PrintList(-1);
	return 0;
	printf("ListSwap:=========\n");
	l1.PrintList(-1);
	l1.ListSwap(0,1);
	l1.PrintList(-1);
	printf("ListSort:=========\n");
	l1.ListPush(-3);
	l1.ListPush(-5);
	l1.PrintList(-1);
	l1.ListSort();
	l1.PrintList(-1);
	printf("ListReverse:=========\n");
	l1.PrintList(-1);
	l1.ListReverse();
	l1.PrintList(-1);
	l1.ListSort();
	l1.PrintList(-1);
	printf("HeapRealloc:==========\n");
	MyList l3(v,15,"l3");
	l1.PrintList(-1);
	l1.ListPush(1);
	l1.ListPush(1);
	l1.ListPush(1);
	l1.ListPush(1);
	return 0;
}
int f_test_LinkList() { // FUNC
	cout<<"================================"<<endl;
	cout<<"TEST LINK LIST"<<endl;
	MyLinkList l01("l01");
	l01.ListUnshift(9);
	l01.ListUnshift(8);
	l01.ListUnshift(7);
	l01.PrintList(-1);

	return 0;
	int u[5]={101,77,303,7,21};
	MyLinkList l0(u,15,"l0");
	//MyList l0(u,23);
	l0.PrintList(l0.ListLength(),true);
	return 0;
	cout<<l0.ListLength()<<endl;
	MyList l1(u,5,"l1");
	MyList lX(l1);
	l1.PrintList(5);
	l1.PrintList(5,true);
	cout<<"LENGTH="<<l1.ListLength()<<endl;
	cout<<"GET ELEMENT="<<l1.GetElem(4)<<endl;
	if (0) { 
		cout<<"ClearList..."<<endl;
		l1.ClearList();
		cout<<"GET ELEMENT="<<l1.GetElem(4)<<endl; // will cause segment fault
	}

	cout<<"LocateElem:"<<endl;
	cout<<l1.LocateElem(3,compare)<<endl;

	cout<<"copy constructor:============"<<endl;
	MyList ltemp(l1);
	l1.PrintList(-1,true);
	ltemp.PrintList(-1,true);
	//return 0;
	cout<<"PriorElem:============"<<endl;
	cout<<l1.PriorElem(7)<<endl;
	printf("NextElem:===================\n");
	cout<<l1.NextElem(1)<<endl;
	printf("ListInsert:===================\n");
	l1.PrintList(-1,true);
	l1.ListInsert(5,999);
	l1.PrintList(-1,true);
	//return 0;
	printf("ListDelete:===================\n");
	l1.PrintList(-1,true);
	l1.ListDelete(5);
	l1.PrintList(-1,true);
	printf("ListTraverse,pre_order:===================\n");
	l1.ListTraverse(visit);
	printf("ListTraverse,post_order:===================\n");
	l1.ListTraverse(visit,false);
	printf("ListPush:=========\n");
	l1.PrintList(-1);
	l1.ListPush(9);
	l1.ListPush(8);
	l1.ListPush(7);
	l1.PrintList(-1);
	printf("ListPop:=========\n");
	l1.PrintList(-1);
	cout<<l1.ListPop()<<endl;
	cout<<l1.ListPop()<<endl;
	cout<<l1.ListPop()<<endl;
	cout<<l1.ListPop()<<endl;
	cout<<l1.ListPop()<<endl;
	l1.PrintList(-1);
	printf("ListUnion:=========\n");
	return 0;
	l1.PrintList(-1);
	int v[5]={33,44,55,66,77};
	MyList l2(v,5,"l2");
	l2.PrintList(-1);
	MyList lunion(v,5,"lunion");
	l1.ListUnion(l2,lunion);
	lunion.PrintList(-1);
	return 0;
	printf("ListSwap:=========\n");
	l1.PrintList(-1);
	l1.ListSwap(0,1);
	l1.PrintList(-1);
	printf("ListSort:=========\n");
	l1.ListPush(-3);
	l1.ListPush(-5);
	l1.PrintList(-1);
	l1.ListSort();
	l1.PrintList(-1);
	printf("ListReverse:=========\n");
	l1.PrintList(-1);
	l1.ListReverse();
	l1.PrintList(-1);
	l1.ListSort();
	l1.PrintList(-1);
	printf("HeapRealloc:==========\n");
	MyList l3(v,15,"l3");
	l1.PrintList(-1);
	l1.ListPush(1);
	l1.ListPush(1);
	l1.ListPush(1);
	l1.ListPush(1);
	cout<<"================================"<<endl;
	return 0;
}
int f_test_Stack() { // FUNC
	cout<<"================================"<<endl;
	cout<<"TEST STACK"<<endl;
	MyStack l0;
	//MyList l0(u,23);
	l0.Push(1);
	l0.Push(2);
	l0.Push(3);
	l0.PrintList(l0.ListLength(),true);
	cout<<"POP!"<<endl;
	cout<<l0.Pop()<<endl;
	cout<<"POP!"<<endl;
	cout<<l0.Pop()<<endl;
	cout<<"================================"<<endl;
	l0.Unshift(9);
	l0.Unshift(8);
	l0.Unshift(7);
	l0.Unshift(6);
	l0.Unshift(9);
	l0.Unshift(8);
	l0.Unshift(7);
	l0.PrintList(l0.ListLength(),true);
	cout<<"SHIFT!"<<endl;
	cout<<l0.Shift()<<endl;
	cout<<"SHIFT!"<<endl;
	cout<<l0.Shift()<<endl;
	cout<<"SHIFT!"<<endl;
	cout<<l0.Shift()<<endl;
	l0.PrintList(l0.ListLength(),true);
	cout<<"================================"<<endl;
	return 0;
}

bool compare(int a,int b) // FUNC
{
	//if (a==b){return true;}
	//return false;
	return (a==b);
}
bool visit(int *a) // FUNC
{
	printf("visit (%x)%d\n",a,*a);
	return true;
}
