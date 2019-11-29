/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> nums;
        
        for(auto i = nums1.begin(); i < nums1.end(); i++)
        {
            nums.push_back(*i);
        }
        
        for(auto i = nums2.begin(); i < nums2.end(); i++)
        {
            nums.push_back(*i);
        }
        
        sort(nums.begin(),nums.end());
        
        double ans;
        int n = nums.size();
        if(n % 2 == 1 ) // odd
        ans = nums[(n-1)/2];
        else
        ans = double(nums[n/2] + nums[(n/2)-1])/2;
        
        return ans;
    }
};


