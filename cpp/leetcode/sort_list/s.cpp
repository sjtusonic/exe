/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define SIMPLE_LOG 1
#define LNX 1
//#define DBG 0

#if (SIMPLE_LOG)
#define DLOG(x)
#else
#define DLOG(x) cout<<#x<<"="<<x<<" @"<<__LINE__<<endl;
#endif

#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";

#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<"VEC:\t"<<#a<<"="<<*u<<std::endl;}
#define PRINT_VECTOR_hor(a)  std::cout<<#a<<":\t";for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;

#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)

#if (SIMPLE_LOG)
#define DENTER 
#define DRETURN 
#else
#define DENTER \
	LVCALL++; PRLVCALL; ::std::cout<<"-->"<<__FUNCTION__<<":LINE="<<__LINE__<<::std::endl;
#define DRETURN \
	PRLVCALL; ::std::cout<<"<--"<<__FUNCTION__<<::std::endl; LVCALL--;
#endif

#define DEBUG_MARK PRINT_DEBUG_INFO()
#define PRINT_COUT(p) \
	(::std::cout<<p<<"\t"   )
#define PRINT_ENDL() \
	(::std::cout<<::std::endl)
#define DPRINT(x) \
	(::std::cout<<x<<::std::endl   )
#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )



#define verbose_PRINT_VECTOR_hor(a)  std::cout<<#a<<":\t";for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;
#define verbose_PRINTVAR_hor(a) std::cout<<#a<<"("<<a<<")\t";
#define verbose_PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;
#define verbose_PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )

#if SIMPLE_LOG
#define PRINTVAR(a)
#define PRINTVAR_hor(a)
#define PRINT_VECTOR(a)
#define PRINT_VECTOR_hor(a)
#define PRINT_DEBUG_INFO()

#define DEBUG_MARK
#define PRINT_DEBUG_INFO_PREFIX(p)
#define DPRINT(x)
#define PRINT_COUT(p)

#define DENTER
#define DRETURN
#endif

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
#include <regex>
#include <map>
#include <assert.h>
#include<string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <stdlib.h>     /* srand, rand */


using namespace std;

#if (SIMPLE_LOG)
#else
static int LV=0;
static int LVCALL=0;
#define PRLV     for(int u12=LV;    u12>0;u12--) {std::cout<<" .. ";}
#define PRLVCALL for(int u12=LVCALL;u12>0;u12--) {std::cout<<" .. ";}
#endif

#if LNX
struct ListNode
{
	int val;
	ListNode *next;
	ListNode (int x):val (x), next (0)
	{}
	ListNode (int x,ListNode* n):val (x), next (n)
	{
	}
};
#endif

class Solution
{
	public:
		int getLen (ListNode * head)
		{
			int r = 0;
			while (head)
			{
				r++;
				head = head->next;
			}
			return r;
		}
		ListNode *getIthItem (ListNode * head, int i)
		{
			int r = 0;
			while (head)
			{
				if (r == i)
					return head;
				r++;
				head = head->next;
			}
			return 0;
		}
		void show (ListNode * head, bool withAddr=0)
		{
#if SIMPLE_LOG
			return;
#endif
			DENTER;
			vector<ListNode*> record;
			while (head)
			{
				cout << head->val ;
				if(withAddr)
					cout <<"[@"<< head<<"]" ;
				if(find(record.begin(),record.end(),head)!=record.end())
				{
					cout<<"Warning: GOT LOOP!"<<endl;
					break;
				}
				record.push_back(head);
				cout<< "\t";
				head = head->next;
			}
			cout << endl;
			DRETURN;
		}
		void swap (int& a,int& b)
		{
			DPRINT("swap:"<<a<<","<<b);
			int tmp=a;
			a=b;
			b=tmp;
		}
		void swap (ListNode *& head, int i, int j)
		{
			if (i > j)
				return swap (head, j, i);
			if(i==j)
				return;
			auto n1 = getIthItem (head, i);
			auto n2 = getIthItem (head, j);
			auto n2pre = getIthItem (head, j - 1);
			//pre
			if(i!=0)
			{
				auto n1pre = getIthItem (head, i - 1);
				// swap
				auto tmp=n1pre->next; n1pre->next=n2pre->next; n2pre->next=tmp;
			}
			else 
			{ // swap
				auto tmp=head; head= n2pre->next; n2pre->next=tmp;
			}
			//next
			auto tmp=n1->next;
			n1->next=n2->next;
			n2->next=tmp;
		}
		ListNode *sortList (ListNode * head)
		{
			if (head == 0)
				return 0;

			auto newhead=head;
			mergeSort(newhead,0,getLen(head)-1);
			bubbleSort(newhead,0,0);
			DLOG(newhead);

			return newhead;
		}
		void mergeSort(ListNode*&head,int from,int to)
		{
			DENTER;
			DLOG(from);
			DLOG(to);
			if(from==to)
				return;
			if(to-from<=40)
			{
				bubbleSort(head,from,to);
				return;
			}
			if(to-from==1)
			{
				auto pFrom=getIthItem(head,from);
				auto pTo=pFrom->next;
				if(pFrom->val>pTo->val)
					swap(pFrom->val,pTo->val);
				DRETURN;
				return;
			}
			int mid=(from+to)/2;
			mergeSort(head,from,mid);
			mergeSort(head,mid+1,to);
			merge(head,from,mid+1,to+1);
			DLOG(head);
			DRETURN;
		}
		void merge(ListNode*&head,int from,int mid,int to)
		{
			DENTER;
			vector<int> inp={from,mid,to};
			PRINT_VECTOR_hor(inp);
			//show(head,1);
			ListNode* n1=getIthItem(head,from);
			ListNode* n2=getIthItem(head,mid);
			ListNode* NFROM=n1;
			ListNode* NMID=n2;
			ListNode* NTO=getIthItem(head,to);
			ListNode* NPRE=0;
			if(from==0)
			{
				NPRE=new ListNode(-999);
				NPRE->next=NFROM;
			}
			else
				NPRE=getIthItem(head,from-1);
			//DLOG(NPRE);
			//DLOG(NFROM);
			//DLOG(NMID);
			//DLOG(NTO);

			ListNode* nNew=NPRE;
			//DLOG(n1);
			//DLOG(n2);
			//DLOG(nNew);
			while(n1!=NMID && n2!=NTO)
			{
				//DPRINT("------------------------->");
				if(n1->val<=n2->val)
				{
					//DPRINT("n1val="<<n1->val<<" <=n2val="<<n2->val);
					DPRINT("ADD:"<<n1->val);
					DPRINT(nNew<<"->"<<n1);
					nNew->next=n1;
					n1=n1->next;
					nNew=nNew->next;
				}
				else
				{
					//DPRINT("n1val="<<n1->val<<" >n2val="<<n2->val);
					DPRINT("ADD:"<<n2->val);
					DPRINT(nNew<<"->"<<n2);
					nNew->next=n2;
					n2=n2->next;
					nNew=nNew->next;
				}
				//DLOG(n1);
				//DLOG(n2);
				//DLOG(nNew);
				//DPRINT("<-------------------------");
			}
			//DLOG((n1!=NMID));
			if(n1!=NMID)
			{
				nNew->next=n1;
				DPRINT(nNew<<"->"<<n1);
				//NMID->next=NTO;
				//DPRINT(NMID<<"->"<<NTO);
				while(nNew->next!=NMID)
					nNew=nNew->next;
				nNew->next=NTO;
				DPRINT(nNew<<"->"<<NTO);
			}

			//DLOG((n2!=NTO));
			if(n2!=NTO)
			{
				nNew->next=n2;
				DPRINT(nNew<<"->"<<n2);
			}
			//NPRE->next=NFROM;
			if(from==0)
				head=NPRE->next;
			//show(head,1);
			DRETURN;
		}
		int qSort (ListNode *& head,int from,int to)
		{
			ListNode* pivot=head;
			ListNode* g1=head;
			ListNode* g2=head;
			// LI:
			// (head,g1] is smaller
			// (g1,g2] is larger
			while(g2->next)
			{
				g2=g2->next;
				if(g2->val<pivot->val)
				{
					g1=g1->next;
				}
			}
			return 0;
		}
		ListNode* bubbleSort(ListNode*& head,int from,int to)
		{
			DENTER;
			auto fromPtr=getIthItem(head,from);
			auto toPtr=getIthItem(head,to);
			toPtr=toPtr->next;
			ListNode* p1=fromPtr ;
			bool flag_swap=1;
			while(flag_swap)
			{
				flag_swap=0;
				DLOG(p1);
				ListNode* p2=p1;
				while(p2!=toPtr && p2->next!=toPtr)
				{
					DLOG(p2);
					if(p2->next->val<p2->val)
					{
						swap(p2->next->val,p2->val);
						flag_swap=1;
					}
					p2=p2->next;
					show(head);
				}
			}
			DRETURN;
			return head;
		}
};


#if LNX
vector<int> genRandVec(int len) 
{
	vector<int> r;
	while(len>0)
	{
		srand (time(NULL)+len);
		/* generate secret number between 1 and 10: */
		int randi=rand();
		int i = randi % len;
		r.push_back(i);
		len--;
	}
	return r;
}

ListNode* vecToListNode(  vector<int> list) 
{
	// Generate list from the input

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for(int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}
int main ()
{
	// ListNode *head = new ListNode(0);
	//ListNode *head = vecToListNode({0,1,2,3,4,5,6});
	//ListNode *head = vecToListNode({3,2,5,1,4,6,0,55,66,34,23,13,53,1,32});
	//                              0 1 2 3 4 5 6

	//ListNode *head = vecToListNode({1,3,3, 1,1,3,2,2,1});
	//ListNode *head = vecToListNode({10,3,2,4,5,6,8});
	//                              0 1 2 3 4 5 6
	ListNode *head = vecToListNode(genRandVec(150000));
	DEBUG_MARK;
	Solution().show(head,1);

	DLOG(head);
	//Solution().merge(head,0,2,5);

#if 1
	auto ans=Solution().sortList(head);
	DEBUG_MARK;
	DLOG(ans);
	Solution().show(ans,1);
#endif
	//ListNode *ret = Solution ().sortList (head);
	//DEBUG_MARK;
	//Solution().show(ret,1);
	return 0;
}
#endif
