// C++ program to split an array into Two
// equal sum subarrays
#include<bits/stdc++.h>
using namespace std;
 
// Retunrs split point. If not possible, then
// return -1.
int findSplitPoint(int arr[], int n)
{
    int i = 0; 
    int j = n-1;
   // assuming array is in increasing order 
   
    int leftsum = arr[i];  // first element
    int rightsum = arr[j]; // last element 
    
    while(1)
    {
    	if(leftsum == rightsum && i == j-1)
    	return i;
    	
    	if(i == j)
    	break;
    	if(leftsum < rightsum ) 
    	{
    		i++;
    		
    		if(i == j)
    		break;
    		else
    		leftsum = leftsum + arr[i];
		}
		else
		{
    		j--;
    		if(i == j)
    		break;
    		else
    		rightsum = rightsum + arr[j];
		}
	}
 
    // if it is not possible to split array
    // into two parts.
    return -1;
}
 
// Prints two parts after finding split point using
// findSplitPoint()
void printTwoParts(int arr[], int n)
{
    int splitPoint = findSplitPoint(arr, n);
 
    if (splitPoint == -1)
    {
        cout << "Not Possible" <<endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if(splitPoint == i)
            cout << endl;
        cout << arr[i] << " " ;
    }
}
 
// driver program
int main()
{
    int arr[] = {1 , 2 , 3 , 4 , 5 , 5 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printTwoParts(arr, n);
    return 0;
}
