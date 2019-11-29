/*

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/
#include<bits/stdc++.h>
using namespace std;


    vector<vector<int>> fourSum(vector<int>& num, int target) {
        
    vector<vector<int> > res;
    
        if (num.size() < 4)
            return res;
    
        std::sort(num.begin(),num.end());    // just like 3 sum --> sort first
    
        for (int i = 0; i < num.size()-3; i++) {  // if size is 6 --> index are from 0 to 5, i can be 2 at max , i.e at 0,1,2 , when i is at 2 --> 3 ,4 and 5 indexes will be taken by others
        
            int target_3 = target - num[i];  // see the diff , if val at i is +ve --> target_3 is negative and viceversa.
        
            for (int j = i + 1; j < num.size() - 2; j++) { // setting another pointer just after i , when i is at index 2, it will go from 3 to 3, i.e it will fix on 3
            
                int target_2 = target_3 - num[j]; // now we again generated another target to achieve. 
            
            // now this problem is reduced to finding 2 variables whose sum is equal to target_2 with addition that we need to check that Quadruples dosn't repeat themselves. 
            
                int front = j + 1;
                int back = num.size() - 1;
            
                while(front < back) {
                
                    int two_sum = num[front] + num[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0); // vector of size 4 initialized with 0
                        quadruplet[0] = num[i];   // we fixeted that value of  i will always be at 0th position 
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet); 
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < num.size() && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < num.size() && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
    
    }

int main()
{
	vector<int> nums;
	nums.insert(nums.end(), {1, 0, -1, 0, -2, 2});
	vector<vector<int>> res;
	res = fourSum(nums,0);
	for(auto x =0; x < res.size(); x++)
	{
		for(int i = 0 ; i < res[x].size(); i++)
		cout << res[x][i] << " ";
		cout << endl;
	}
	return 0;
}
