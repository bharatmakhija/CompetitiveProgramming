#include<bits/stdc++.h>
using namespace std;
string s;
int k;
void func()
{
	cin >> s;
	cin >> k;
	
	int len = s.length();
	int ans = 0;
	for(int i = 0; i + k -1 < len; i++)
	{
		if(s[i]=='-')
		{
			for(int j= 0; j < k; j++)
			{
				s[i+j] ^= '-'^'+';
			}
			ans++;
		}
	}
	
	for(int i= len - k ; i < len; i++)
	if(s[i]=='-')
	{
		ans = -1;
	}
	
	if(ans == -1)
	cout << "IMPOSSIBLE" << endl;
	else
	cout << ans << endl;
}
int main()
{
	if(freopen("A-large-practice.in", "r", stdin))
	{
		freopen("outfile.in","w",stdout);
	int t;
	cin >> t;
	for(int i = 0; i < t; i ++)
	{
		cout << "Case #" << i+1 << ": "; 
		func();
	}
}
else
cout << "can't open file" << endl;

return 0;
}
