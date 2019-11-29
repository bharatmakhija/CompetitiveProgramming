/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/


#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans; // its initialized to null by def
        
        if(nums.empty()|| nums.size() < 3) // return ans directly
        return ans;
        
         sort(nums.begin(),nums.end()); // sort it becomes -4 -1 -1 0 1 2
        
        for(int i = 0; i <= nums.size() - 3; i++) // as we are finding triplets
        {
            while(i != 0 && nums[i] == nums[i-1] && i < nums.size())
            i++;
            
            if(i >= nums.size()-2)
            break;
            
            //overall we will be using 3 pointers i is set to 0, j at i+ 1 i.e 1 and k at last of vector
            int j = i+1;
            int k = nums.size() - 1;
            // fix i and move j and k as binary search i.e. if sum == 0 save it, sum < 0 --> move j forward and if sum > 0 move k backward
            while(j < k)
            {
                
                if( nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> vec;
                    
                    vec.push_back(nums[i]);
                    vec.push_back(nums[j]);
                    vec.push_back(nums[k]);
                    j++;
                    k--;
              
                ans.push_back(vec);    
                    
                while(j < k && nums[j]==nums[j-1])  // this is done to avoid duplicate entries 
                j++;
                
                while(j < k && nums[k]==nums[k+1])  // same here
                k--;
                
                }
                else if ( nums[i] + nums[j] + nums[k] < 0)
                j++;
                else                     // if sum > 0 then
                k--;
            }
            
            
            } // end of for
         
        return ans;
    }
int main()
{
	vector<int> nums;
	nums.insert(nums.end(), {-1, 0, 1, 2, -1, -4});
	vector<vector<int>> res;
	res = threeSum(nums);
	for(auto x =0; x < res.size(); x++)
	{
		for(int i = 0 ; i < res[x].size(); i++)
		cout << res[x][i] << " ";
		cout << endl;
	}
	return 0;
}
