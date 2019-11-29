//leet Longest Divisible subset

class Solution {
public:
// 1 2 3 9 18  --> 
void largestDivisibleSubsethelper(vector<int>& nums,vector<int>&  res,vector<int>&  temp,int index)
{
    if(index >= nums.size())
    {
        if(temp.size() > res.size())
        {
            res.clear();
            for(int i=0; i < temp.size(); i++)
            res.push_back(temp[i]);
        }
        
        return;
    }
    
    // include and move
    if(temp.size() == 0){
    temp.push_back(nums[index]);
    largestDivisibleSubsethelper(nums,res,temp,index+1);
    temp.pop_back();
    }
    else
    {
        bool flag = true;
        for(int j=0; j < temp.size() && flag; j++)
        {   // cout << nums[index] << " " << index << endl;
            //if(nums[index] != 0 && temp[j] != 0 )
            if(temp[j] % nums[index] != 0 && nums[index] % temp[j] != 0)
             {
                 flag = false;
             }
        }
        
        if(flag)
        {
          temp.push_back(nums[index]);
          largestDivisibleSubsethelper(nums,res,temp,index+1);  
          temp.pop_back(); // don't include
        }
    }
     // simply move
    largestDivisibleSubsethelper(nums,res,temp,index+1);
}
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
    vector<int> res;
    if(nums.size() == 0)
    return res;
    vector<int> temp;
    temp.clear();
    largestDivisibleSubsethelper(nums,res,temp,0);
    return res;
    
    }
};



// this is my solution, though it is correct its exceeding time limit.. check why? how to approach such problems 
//--------------------------------------------------------------------------------------------------------------------
/*
which things are increasing complexity:
	
	1. every time we are clearing result vector and loading it again from temp -- extra and unnecessary
	2. Given a set of integers that satisfies the property that each pair of integers inside the set are mutually divisible, for a new integer S, S can be placed into the set as long as it can divide 
	the smallest number of the set or is divisible by the largest number of the set.

For example, let's say we have a set P = { 4, 8, 16 }, P satisfies the divisible condition. Now consider a new number 2, it can divide the smallest number 4, so it can be placed into the set; similarly, 
32 can be divided by 16, the biggest number in P, it can also placed into P.

so we don't need to check all the numbers. 

----------------------this is how we will do it ---------------------------------------------------------------------------------------------------------------





