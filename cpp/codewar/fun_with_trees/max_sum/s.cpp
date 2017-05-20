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
		TreeNode* left;
		TreeNode* right;
		int value;
};
class Solution
{
	public:
		static int maxSum(TreeNode* root)
		{
			// TODO: implementation
			if(!root->left )
			{
				if(!root->right)
					return value;
				else
					return maxSum(root->right);
			}
			else
			{
				if(!root->right)
					return maxSum(root->left);
				else
				{
					auto max_left= maxSum(root->left);
					auto max_right= maxSum(root->right);
					return (max_left>max_right)?max_left:max_right;
				}
			}
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
