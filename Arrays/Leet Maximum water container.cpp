/*

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

*/

#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    
    int left=0;
    int right = height.size()-1;
   // int ansind1, ansind2;
    int MaxWater = 0;
    
    if(height.size() < 2)
    return MaxWater;
    
    while(left < right) 
    {
        int curWater = (right-left)* min(height[left],height[right]); 
        
        if(curWater > MaxWater)
        MaxWater = curWater;
        
        if(height[left] < height[right])  // this is important logic to approach closer --> basically we want to keep max height at both ends to get max capicity .. so we want that left and right get fixed and doesn't move 
        left++;                           // so if left reaches max height it gets fixed while right will keep moving forward to see if it still can find any height more that left if yes then left will move, for every    
        else							 // left and right combination we have calculated maxwater possible. however 
        right--;
    }
   
    
    //cout << MaxWater << endl;
    return MaxWater;
    }
int main()
{
   vector<int> v{2,5,8,11,14};
   cout << maxArea(v) << endl;	
	
	return 0;
}
