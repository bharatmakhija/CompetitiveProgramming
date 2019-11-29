/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

#include<bits/stdc++.h>
using namespace std;


string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()){return "";}
        if (strs.size()==1){return strs[0];}
        
		// if first string is null, it will infact never go in the loop and return first string 
        for (int i=0;i<strs[0].size();i++) // visiting all chars of first string if its not null  
		{
            for (int j=0;j<strs.size()-1;j++) // visiting all strings one by one, if vectors size is 3, i.e. they are at 0,1,2 index , so j will traverse 0,1 only
			{
                if (i>=strs[j+1].size() || strs[j][i]!=strs[j+1][i])
				{
                    return strs[j].substr(0,i);
                }
            }
        }
         
        return strs[0];
    }
int main()
{
	vector<string> s;
	s.push_back("bharat");
	s.push_back("bhar");
	s.push_back("bha");
	cout << longestCommonPrefix(s) << endl;
	return 0;
}

/*

[bharat , bhar , bha]  --> vectors size is 3 --> j = 0; j < vec.size() -1 --> j < 2 ; j++
i will go from o to sizeof(bharat)
i.e i = 0 ; i < 6; i++

i= 0, j = 0 
if first character only of 2 strings doesn't match return null i.e substr(0,i) where i = 0 right now

if(strs[j][i] != strs[j+1][i])
return strs[j].substrs(0,i);

repeat for all other strings --> j = 1 now so 1st and 2nd string 1st character will be matched from above condition.  
 
 i= 1, same way, i = 2 sameway , i = 3;
 j = 0 --> matches 
 j = 1 then 
 
 strs[1][3] != strs[2][3] --> true but strs[2][3] actually doesn't exist as size of string at index 2 is smaller. so we need to create logic for size as well
 ..
 
 if(i >= strs[j+1].size())         // another condition
 return strs[j].substr(0,i);

so overall we created the condition as 

if(i >= strs[j+1].size() || strs[j][i] != strs[j+1][i]) .. so if ith character being matched is there in both the strings then only it will be compared 
return strs[j].substrs(0,i);

Done!!
*/
