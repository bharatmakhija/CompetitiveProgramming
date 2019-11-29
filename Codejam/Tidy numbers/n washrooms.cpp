#include<bits/stdc++.h>
using namespace std;


void func(int n, int k, pair<int,int>& p)
{
	queue<int> q;
	
	q.push(n);
	
	while(!q.empty() && k > 0)
	{
		int x = q.front();
		q.pop();
		
		if(x == 1)
		{
			p = make_pair(0,0);
			return ;
		}
		
		if(x % 2 == 0) // even
		{
			q.push(x/2);
			q.push(x/2-1);
		}
		else
		{
				q.push(x/2);
				q.push(x/2);
		}
		
		k--;
	}
	
	while(q.size() > 2)
	q.pop();
	
	p.first = q.front();
	q.pop();
	p.second = q.front();
	q.pop();
}
int main ()
{
	int t; 
	cin >> t;
	int n,k;
	pair<int,int> p ;
	while(t--)
	{
		cin >> n >> k;
		func(n,k,p);
		cout << p.first << " " << p.second << endl;
	}
	
	return 0;
}
