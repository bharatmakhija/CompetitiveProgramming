
#include<bits/stdc++.h>
using namespace std;
/* Leet Valid Parenthesis
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

    bool isValid(string s) {
        
        // to check parenthesis -> use stack
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++)  // simple skip characters i.e. just write if -else condition for brackets
        {
            if (s[i] == '(' || s[i] =='{' || s[i] == '[') // any left paranthesis
            {
                st.push(s[i]); 
            }
            
            if( st.empty() && (s[i] == ')' || s[i] =='}' || s[i] == ']'))
            {
                return false;
            }
            
            
            if( !st.empty() && (s[i] == ')' || s[i] =='}' || s[i] == ']'))
            {
                if(s[i] == ')')
                {
                    if(st.top() == '(')
                    {
                        st.pop();
                    }
                    else
                    return false;
                }
                
                if(s[i] == '}')
                {
                    if(st.top() == '{')
                    {
                        st.pop();
                    }
                    else
                    return false;
                }
                
                if(s[i] == ']')
                {
                    if(st.top() == '[')
                    {
                        st.pop();
                    }
                    else
                    return false;
                }
            }
            }
        
        if(st.empty())
        return true;
        else
        return false;
        
    }

int main()
{
	if(isValid("{{[(awd)as]asd}asa}"))
	cout << "its valid";
	else
	cout << "its invalid";
	return 0;
}
