/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/

#include<bits/stdc++.h>
using namespace std;

void binary_search(vector<int>& nums, int target, vector<int>& range)
    {
        int left = 0; 
        int right = nums.size()-1;
        range[0] = -1;
        range[1] = -1;
        
        while(left <= right)
        {
            int mid = (right + left)/2;
            
            if(nums[mid] == target)
            {
             //cout <<"mid is" <<  mid << endl;    
              range[0] = mid;
              range[1] = mid;
             
             int i = mid-1;
             while( i >= 0 && nums[i--] == target)
             range[0]--;
             
             i = mid + 1;
             while( i < nums.size() && nums[i++]== target)
             range[1]++;
             break;
            }
            else if(nums[mid] < target)
            left = mid + 1;
            else
            right = mid -1;
        }
        
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> range(2);
    range[0] = 0;
    range[1] = 0;
    
    binary_search(nums,target,range);
    return range;
    }
int main()
{
	//int x[] = {1,2,4,5,6,6,7,8,9};
	vector<int> k;
	k.insert( k.end(), { 1,2,4,5,6,6,7,8,9 } ); // direct way to insert values into a vector 
	vector<int> result;
	result = searchRange(k,6);
	cout << result[0] << " " << result[1] << endl;
	return 0;
}
