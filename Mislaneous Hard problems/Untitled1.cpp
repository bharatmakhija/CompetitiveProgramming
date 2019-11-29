#include<bits/stdc++.h>
using namespace std;


string func(string s, int n)
{
	int len = s.length();
	if(len == 0 ||  n >= len)
	return "";
	
	if(n == 0)
	
	for(int i=1; i < len; i++)
	{
		if(s[i-1] > s[i] && n != 0)
		 {
		   s.erase(i-1,1);
		 //  cout << s << endl;
		   n--;
		   len--;
		   i--;
		 }
	}
	
	if(n != 0)
	{
	   s.erase(len - n,n);	
	}
	
	return s;
}
int main()
{
	string s = "765028321";
	int n = 5;
	 string res = func(s,n);
	 cout << res;
	return 0;
}

