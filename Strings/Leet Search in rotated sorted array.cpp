#include <bits/stdc++.h> 
using namespace std;



int findtarget(vector<int>& nums, int target, int left, int right)
{
    if(left == right)
    if(nums[left] == target)
    return left;
    else
    return -1;
    
    while(left < right)
    {
    
        int mid = (left + right)/2;
        if(nums[mid] == target)
        return mid;
        else if (nums[mid] < target)
        left = mid + 1;
        else
        right = mid - 1;
    }
    
    if(left == right)
    if(nums[left] == target)
    return left;
    
	return -1;
}

 int search(vector<int>& nums, int target) {
     
    if(nums.size() == 0)
    return -1;
    
    if(nums.size()== 1)
    if(nums[0]==target)
    return 0;
    else 
    return -1;
    
    
    int l = 0;
    int r = nums.size()-1;
    int mid;
    while(l<r)
    {
        mid = (l + r)/2;
        if(nums[mid] > nums[r])
        l = mid + 1;
        else
        r = mid;
    }
        // l == r now point to smallest element of the array
   //  cout << "middle element " << l  << endl;   
    int sml = l;
    l = 0;
    r = nums.size()-1;
    int left,right;
    int ans;
    // if smallest element is at left most corner --> its in ascending order only
    if(sml == 0){
    left = 0;
    right = nums.size()-1;
    }
    
    if(nums[sml] <= target && nums[r] >= target){
    left = sml;
    right = r;
    }
    else
    {
        left = l;
        right = sml -1;
    }
    
    ans = findtarget(nums,target,left,right);
    return ans;
}



int main()
{
	vector<int> nums;
	
	int a[] = {2,1};
	nums.insert(nums.begin(),a,a+2);
	int ans = search(nums,1);
	cout << ans << endl;
	return 0;
}
