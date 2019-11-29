#include<bits/stdc++.h>
using namespace std;

/*

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

int threeSumClosest(vector<int>& nums, int target) {
        
    int sum = 0;
    
    int minn = INT_MAX;
    sort(nums.begin(), nums.end());
    int flag = 1;
    int ans;
    for(int i =0; i < nums.size()-2 && flag; i++)
    {
     
      int j = i+1;
      int k = nums.size()-1;
      
        while(j < k && flag)
        {
          int sum = nums[i] + nums[j] + nums[k];
            
            if(sum == target){
            minn = abs(sum-target);
            ans = sum;
            j++;
            k--;
            flag = 0;
            continue;
            }
            
            if(abs(sum-target) < minn)
            {
             minn = abs(sum - target);
             ans = sum;
            }
            
            if(sum < target)
            j++;
            
            if(sum > target)
            k--;
        }
    }
    
        return ans;
    }
    
    
int main()
{
	vector<int> nums;
	nums.insert(nums.end(),{-1, 2, 1, -4});
	cout << threeSumClosest(nums,1) << endl;
	return 0;
}
