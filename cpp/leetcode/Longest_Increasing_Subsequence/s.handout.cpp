#include <vector>
#include <string>
#include <iostream>
//#include <algorithm>
//#include <deque>
//#include <map>
//#include <assert.h>

using namespace std;

class Solution {
	public:
		int isIncremental(vector<int>& nums,int from,int to)
		{
			for(int i=from;i<=to-1;i++)
			{
				if(nums[i]>nums[i+1])
					return false;
			}
			return true;
		}
		void getMaxIncr(vector<int>&nums,int from,int to,int lowBound,vector<int>&vInd)
		{
			if(from>to)
			{
				return;
			}

			if(from==to && nums[from]>lowBound)
			{
				vInd.push_back(from);
				return;
			}

			//  from < to:
			//      with from:
			vector<int> vIndSub1,vIndSub2;

			if(nums[from]>lowBound)
			{
				vIndSub1.push_back(from);
				getMaxIncr(nums,from+1,to,nums[from],vIndSub1);    
			}

			//      without from:
			getMaxIncr(nums,from+1,to,lowBound,vIndSub2);

			auto added=(vIndSub1.size()>vIndSub2.size())?vIndSub1:vIndSub2;
			for(auto i:added)
			{
				vInd.push_back(i);
			}
		}

		int lengthOfLIS(vector<int>& nums) {
			if(nums.size()==0)
				return 0;
			////////////////
			bool ordered=true;
			for(int i=0;i<nums.size()-1;i++)
			{
				if(nums[i]>=nums[i+1])
				{
					ordered=false;
					break;
				}
			}
			if(ordered)
			{
				return nums.size();
			}
			////////////////
			vector<int> vInd;
			getMaxIncr(nums,0,nums.size()-1,-9999,vInd);
			return vInd.size();
		}
};

int main() 
{
	//vector<int> v={3,2,5,4,1,7};
	vector<int> v={1,2,3,4};
	//vector<int> v={2,2};
	Solution s;
	int R=s.lengthOfLIS(v);
	cout<<"R="<<R<<""<<endl;
}
