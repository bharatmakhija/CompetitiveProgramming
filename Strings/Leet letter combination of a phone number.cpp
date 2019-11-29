/* Letter combination of a phone number 

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons)

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(string digits,map<char,vector<char>> &mp,vector<string> &res, string r)
{
    if(digits.empty())
    {
        res.push_back(r);
    }
    else
    {
        vector<char> vec = mp[digits[0]];
        for(int i=0; i < vec.size(); i++)
        {
            dfs(digits.substr(1),mp,res,r+vec[i]);
        }
    }
}
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        // first task is to map a number to a character --> for that we will use map   
        map<char,vector<char>> mp; // for char '2' corresponding vector is {a,b,c}
        vector<char> v;
        v.clear();
        int num = 2; // numbers will be mapped from 2-9 
        
        
        if(digits == "")
        return res;
        
        for(char i='a'; i <= 'z'; i++)
        {
            v.push_back(i);
        if(i == 'c' ||i == 'f' || i == 'i' || i == 'l' || i == 'o' || i == 's' || i == 'v' || i == 'z') // these are end points i.e if i reaches c, i.e by now a,b,c are in vector, now put them in map
        {
            char c =  '0' + num; // way to convert number to character
            //cout << c << endl;
            mp[c] = v;
            v.clear();
            num++;
        }
        } // in this way we created the map set. 
        // step 2 is to generate all possible combinations and store them in vector of strings 
        // use dfs for that
        
        dfs(digits,mp,res,"");
        
        return res;
    }

int main()
{
   vector<string> res;
   res = letterCombinations("23");
   for(int i=0; i < res.size(); i++)
   cout << res[i] << " ";	
	return 0;
}
