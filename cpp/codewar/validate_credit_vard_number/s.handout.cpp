#include <vector>
#include <string>
#include <iostream>
#include <deque>

class Solution
{
  public:
    static TreeNode* arrayToTree(std::vector<int> arr) 
    {
    if(arr.empty())
    return NULL;
      TreeNode* rootNode;
      std::deque<TreeNode*> queueOfNode;
      int cntr=0;
      for(auto i:arr)
      {
        auto node=new TreeNode(i);
        if(cntr==0)
          rootNode=node;
        // father point to children
        if(!queueOfNode.empty())
        {
          auto fr=queueOfNode.front();
          if(fr->m_left==NULL)
            fr->m_left=node;
          else if(fr->m_right==NULL)
            fr->m_right=node;
          
        }
        // push to queue
        queueOfNode.push_back(node);
        // pop front of queue
        if(!queueOfNode.empty())
        {
          auto fr=queueOfNode.front();
          if(fr->m_left!=NULL&&fr->m_right!=NULL)
            queueOfNode.pop_front();
        }
        cntr++;
      }
      return rootNode; // TODO: implementation
    }
};
