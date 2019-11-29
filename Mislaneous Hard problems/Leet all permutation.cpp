/*Leet -----------------------similar to geeks all permutations of a string -----------------------------------------------------

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/
void swap(vector<int>& nums,int left,int i){
    int temp;
    temp = nums[left];
    nums[left] = nums[i];
    nums[i] = temp;
}

void permuteuntil(vector<int>& nums,vector<vector<int>>& result, int left, int right)
{
    if(left == right)
    {
        result.push_back(nums);
    }
    else
    {
        for(int i= left; i <= right; i++)
        {
            swap(nums,left,i);
            permuteuntil(nums,result,left+1,right);
            swap(nums,left,i);  // backtrack
        }
    }
    
}
    vector<vector<int>> permute(vector<int>& nums) {
        
    vector<vector<int>> result;
    vector<int> tmp;
    
    permuteuntil(nums,result,0,nums.size()-1);
    
    return result;
    }
};


/*

permutation 2 in leetcode 
que no 47
n a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/


void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);            //.........................why it isn't back tracked??
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
    
    
    // see the difference between two 
