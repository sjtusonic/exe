#include "include.top.h"
using namespace std;


int main() {
	time_t timer;
	struct tm *tblock;
	timer=time(NULL);
	tblock=localtime(&timer);
	cout<<asctime(tblock)<<endl;
	////////////////////////////////////////////////
	int u[5]={1,2,3,7,21};
	MyList l1(u,5);
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

	cout<<"PriorElem:============"<<endl;
	cout<<l1.PriorElem(7)<<endl;
	printf("NextElem:===================\n");
	cout<<l1.NextElem(1)<<endl;
	printf("ListInsert:===================\n");
	l1.PrintList(-1,true);
	l1.ListInsert(2,999);
	l1.PrintList(-1,true);
	printf("ListDelete:===================\n");
	l1.PrintList(-1,true);
	l1.ListDelete(5);
	l1.PrintList(-1,true);
	printf("ListTraverse,pre_order:===================\n");
	l1.ListTraverse(visit);
	printf("ListTraverse,post_order:===================\n");
	l1.ListTraverse(visit,false);
	////////////////////////////////////////////////
	tblock=localtime(&timer);
	cout<<asctime(tblock)<<endl;
	cout<<"END"<<endl;
	return 0;
}

bool compare(int a,int b)
{
	//if (a==b){return true;}
	//return false;
	return (a==b);
}
bool visit(int *a)
{
	printf("visit (%x)%d\n",a,*a);
}
