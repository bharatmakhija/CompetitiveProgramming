#include<bits/stdc++.h>
using namespace std;
/*
in a given string in which we toggle all characters.

Examples:

Input  : gfg
Output : GFG

Input  : aBc12#
Output : AbC12#
*/


int main(){

string s;
cin >> s;

for(int i=0; i < s.length(); i++)
//cout << s[i];
if(s[i] >= 'A' && s[i] <= 'Z')
cout << char(s[i] - 'A' + 'a');
else if (s[i] >= 'a' && s[i] <= 'z')
cout << char(s[i]-'a'+'A');
else
cout << s[i];
//cout << s << endl;	
	return 0;
}
