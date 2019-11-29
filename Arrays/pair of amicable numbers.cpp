#include<bits/stdc++.h>
using namespace std;

/*

Given an array of integers, print the number of pairs in the array that form an amicable pair. Two numbers are amicable if
 the first is equal to the sum of divisors of the second, and if the second number is equal to the sum of divisors of the first.

*/

// Calculate the sum of proper divisors
int sumOfDiv(int x)
{
    // 1 is a proper divisor
    int sum = 1;
    for (int i=2; i<=sqrt(x); i++)
    {
        if (x%i == 0)
        { 
        //    cout << i << " ";
            sum += i;
 
            // To handle perfect squares
            if (x/i != i){
			
                sum += x/i;
      //          cout << x/i << " ";
            }
        }
    }
    //cout << endl;
    return sum;
}

int countpairs(int arr[], int n)
{
	int count = 0;
	
	unordered_set<int> s;
	for(int i=0; i < n ; i++)
	s.insert(arr[i]);
	
	for(int i=0; i < n; i++)
	{
		int num = sumOfDiv(arr[i]);
		
		if(s.find(num) != s.end())
		if(sumOfDiv(num) == arr[i])
		count++;
	}
	
	return count/2;
}

int main()
{
   //cout << sumOfDiv(100) << endl;	
   int arr1[] = {220, 284, 1184, 1210, 2 , 5};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << countpairs(arr1, n1) << endl;
	
	return 0;
}
