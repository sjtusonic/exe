#define PRINTVAR(a) std::cout<<#a<<"\t=\t"<<a<<"\t@"<<__FILE__<<":"<<__LINE__<<":"<<__FUNCTION__<<"()"<<std::endl;

#define PRINT_VECTOR(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<"VEC:\t"<<#a<<"="<<*u<<std::endl;}

#define PRINT_VECTOR_hor(a)  for(auto u=a.begin();u!=a.end();u++) {std::cout<<*u<<"\t";};std::cout<<""<<std::endl;
//#define PRINT_VECTOR_hor(a) 
#define PRINT_DEBUG_INFO() \
	(::std::cout<<"DEBUG: FILE="<<__FILE__<<":LINE=" <<__LINE__<<":FUNC="<<__FUNCTION__<<"() compiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl)

#define PRINT_DEBUG_INFO_PREFIX(p) \
	(::std::cout<<p<<"zjc debug: FILE=" <<__FILE__<<":\tLINE=" <<__LINE__<<":\tFUNC="<<__FUNCTION__<<" \tcompiled in " <<__TIME__<<"-" <<__DATE__<<"" <<::std::endl    )

#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <assert.h>

class TreeNode 
{
	public:
		TreeNode(int value, TreeNode* left, TreeNode* right)
			: m_value(value), m_left(left), m_right(right)
		{
		}

		TreeNode(int value)
			: m_value(value), m_left(NULL), m_right(NULL)
		{
		}

		bool operator==(const TreeNode& rhs) const
		{
			//... // Already implemented for you and used in test cases 
			PRINT_DEBUG_INFO();
			bool t=!(m_value==rhs.m_value);
			if(t) 
				return false;
			PRINT_DEBUG_INFO();
			t=!(m_left==rhs.m_left);
			if(t) 
				return false;
			PRINT_DEBUG_INFO();
			t=!(m_right==rhs.m_right);
			if(t) 
				return false;
			PRINT_DEBUG_INFO();
			t= !(m_left==NULL) && !((*m_left)==(*(rhs.m_left)));
			if(t) 
				return false;
			PRINT_DEBUG_INFO();
			t= !(m_right==NULL) && !((*m_right)==(*(rhs.m_right)));
			if(t) 
				return false;
			PRINT_DEBUG_INFO();

			return true;
		}
		void show()
		{
			std::cout<<"show TreeNode:"<<this<<":"<<m_value<<std::endl;
		}
		bool have2Children()
		{
			return (m_left!=NULL && m_right!=NULL);
		}
		void setChild(TreeNode* childPtr)
		{
			if(m_left==NULL)
				m_left=childPtr;
			else if(m_right==NULL)
				m_right=childPtr;
			return;
		}
		//...
		int m_value;
		TreeNode* m_left;
		TreeNode* m_right;
};

class Solution
{
	public:
		static TreeNode* arrayToTree(std::vector<int> arr) 
		{
			TreeNode* rootNode;
			std::deque<TreeNode*> queueOfNode;
			int cntr=0;
			for(auto i:arr)
			{
				auto node=new TreeNode(i);
				if(cntr==0)
					rootNode=node;
				node->show();
				// father point to children
				if(!queueOfNode.empty())
				{
					auto fr=queueOfNode.front();
					assert(!fr->have2Children());
					fr->setChild(node);
				}
				// push to queue
				queueOfNode.push_back(node);
				// pop front of queue
				if(!queueOfNode.empty())
				{
					auto fr=queueOfNode.front();
					if(fr->have2Children())
						queueOfNode.pop_front();
				}

				PRINTVAR(queueOfNode.size());
				cntr++;
			}

			PRINT_VECTOR_hor(arr);
			return rootNode; // TODO: implementation
		}
};

int main ()
{
	std::vector<int> arr = {17, 0, -4, 3, 15};
	//TreeNode* expected = new TreeNode(17, new TreeNode(0, new TreeNode(3), new TreeNode(15)), new TreeNode(-4));
	//Assert::That(*Solution::arrayToTree(arr), Equals(*expected));
	
	//*Solution::arrayToTree(arr);
	auto n1=TreeNode(1);
	auto n2=TreeNode(1);
	PRINTVAR((n1==n2));
	return 0;
}
