#include<bits/stdc++.h>
using namespace std;



int fun(int left, int right, int* arr)
{
	if(left > right)
	return 0;
	
	return max(arr[left] + fun(left+1,right,arr), arr[right] + fun(left,right-1,arr));
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int *arr = new int[n];
		
		for(int i=0; i < n; i++)
		cin >> arr[i];
		
		int left = 0;
		int right = n-1;
		
		int maxnum = max(arr[left] + fun(left+1,right,arr), arr[right] + fun(left,right-1,arr));
		cout << maxnum << endl;
	}
	return 0;
}
