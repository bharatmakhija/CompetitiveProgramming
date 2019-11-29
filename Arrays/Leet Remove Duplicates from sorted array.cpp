/*

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

*/



int removeDuplicates(vector<int>& nums) {
    
    if(nums.size() == 0)
    return 0;
    
    if(nums.size() == 1)
    return 1;
    
    sort(nums.begin(),nums.end());

int len = 1;

   int x = nums[0]; 
   for(auto i = nums.begin() + 1; i != nums.end() ; i++)
   {
       if( x == *i){
       nums.erase(i); 
       i--;  // coz as element is removed size dec by 1 so element at location 2 comes to 1 so we need to reconsider the current location again.
       }
       else
       {
          len++; //  len keeps track of actual length
          x = *i;
       }
   }
  
  return len;
    }
    
    
