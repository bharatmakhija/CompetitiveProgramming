/* Leetcode:

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
    if(s== "")
    return 0;
    
    int *visited = new int[256];
    fill(visited,visited+256,-1);
    int len = s.length();
    int currentlen = 1;
    int maxlen = 1;
    int previndex;
    visited[s[0]]= 0;
    for(int i=1;i<len;i++)
    {
        previndex = visited[s[i]];
        
        if(previndex == -1 || i - currentlen > previndex )
        {
            currentlen++;
        }
        else
        {
            if(currentlen > maxlen)
            maxlen = currentlen;
            currentlen = i - previndex;
            //cout << currentlen << "  " << maxlen << endl;
        }
        visited[s[i]]= i;
    }
    if(currentlen > maxlen)
    maxlen = currentlen;
    return maxlen;
    }
};

/*
 1. if string is null return null.
 2. there are 256 charcters possible: create array of 256 and initialize it with -1.
    int *visited = new int[256];
    fill(visited,visited+256,-1); // use fill function 
lets say string is : pwwkew	 --> its ans is wke i.e. 3. or (kew will also do)
intially these are initialized to -1. 

no matter what: ans will be atleast 1: ex: bbbbb --> ans is 1.
so
int len = s.len(); //length of the string. 
int maxlen = 1;
int currentlen = 1; (so when currentlen > maxlen --> update maxlen to currentlen)

current condition is 
----------------------------------------

 -1(p) -1(w) -1(k) -1(e)  // i.e visited[p] = -1 and so on. 
 
string : pwwkew 

make visited of s[0] = 0; now:

 0(p) -1(w) -1(k) -1(e) 
 
 traverse the string : i = 1 to len  
 
 if (visited[s[i]] == -1) // it means we haven't encountered it before so increse currentlen by 1.
 and 
 visited[s[i]] = i; // i.e. w became it ith visited character. 

 
 0(p) 1(w) -1(k) -1(e) 
 
 now i = 2 ; which is w again
 for this visited[s[i]] != -1 so it will not be included. (so max substring possible starting from p is of length 2)
 so update maxlen :
 if(currentlen > maxlen)
  maxlen = currentlen;
  
 currentlen will also be updated: 

currentlen = i - visited[s[i]]; 
			= 2 - 1 
			
currentlen becomes 1. w is 3rd visited character(2nd from index 0)
update the array.

current condition:
------------------------------
 0(p) 2(w) -1(k) -1(e)
 currentlen = 1;             2nd w is being considered as the starting point  in pwwkew
 maxlen = 2;         // if noting found larger than pw then maxlen is stored here
 --------------------------------
 
 i = 3;
 visited[s[i]] == -1 ; 
 currentlen = 2;
 
 0(p) 2(w) 3(k) -1(e)
 
 i = 4; i.e. e charcters
 currentlen = 3;
 
 0(p) 2(w) 3(k) 4(e)
 
 i = 5; its w again
 so should include this w or not. i.e. if last w is included we shouldn't include this else we should.
 so how to check if last w is included or not. 
 
 i is at 5. currentlen is 3. i.e. last 3 characters 2,3,4 are included. 
 
 so if last w is 2nd 3rd or 4th character then its included. 
 if its 0th or 1st character then its not included. 
 
 if( visited[s[i]] < i - currentlen) --> it means its not inclded then keep increasing the current length else not. 
 
 in our case: visited[s[i]] = 2 (for w) , i = 5, currentlen = 3;
 so 2 < 5-3 is false, so w is already included. so 
 
 update maxlen. 
 
 currentlen = i - visited[s[i]] 
 it will become 3, i.e last w is removed , this w is inclded and keep moving on i.e. now we started 
 considering string from k onwards. 
 


*/
