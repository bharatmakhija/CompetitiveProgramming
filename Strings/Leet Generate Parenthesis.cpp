/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]


*/
#include<bits/stdc++.h>
using namespace std;

void gp(string s, int l, int r, int n,vector<string> &res)
{ 

  // l and r are 2 vars
    if(l > n)
    return;
    
    if(l == n && r == n)
    res.push_back(s);
    else
    {
      
      gp(s + '(', l+1,r,n,res); // it will keep inserting "(" char till l == n 
      
      if(l > r)
      gp(s + ')', l,r+1,n,res);
         
    }
}
    vector<string> generateParenthesis(int n) {
        
        vector<string> res; //will solv it recursively
        gp("",0,0,n,res); 
        return res;
    }
int main()
{
	vector<string> res;
	res = generateParenthesis(3);
	for(int i=0; i < res.size(); i++)
	cout << res[i] << " ";
	cout << endl;
	return 0;
}
