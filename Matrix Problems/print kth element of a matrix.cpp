#include<bits/stdc++.h>
using namespace std;

// this program prints kth element of mXn matrix..

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cout << "test case no. " << t << " enter rows and cols \n";
		int m, n;
		cin >> m >> n;
		int arr[m][n];
		cout << "enter matrix \n";
		for(int i=0; i < m; i++)
		for(int j=0; j < n; j++)
		cin >> arr[i][j];
		
		cout << "enter no. of test cases for this matrix" << endl;
		int t1;
		cin >> t1;
		
		while(t1--)
		{
			int val; cin >> val;
			cout << arr[(val -1)/n][(val-1)%n] << endl;
		}
	}
	
	// now consider printing kth element in spiral form of matrix : Print K’th element in spiral form of matrix
	// http://www.geeksforgeeks.org/print-kth-element-spiral-form-matrix/ 
	return 0;
}
