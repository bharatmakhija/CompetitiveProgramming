#include<bits/stdc++.h>
using namespace std;
 
// Note : n is not size of array, but number of
// elements whose pairwise sum is stored
// in arr[]
void findNumbers(int *arr, int n, int k)
{
   //int k = sizeof(arr)/sizeof(arr[0]);
   //cout << k << endl;....................................this won't give correct size, see this http://stackoverflow.com/questions/2037736/finding-size-of-int-array/
   
    int num[n];
 
    // b-a is calculated here
    int b_minus_a = arr[n-1] - arr[1];
 
    // b is calculated here
    num[1] = (arr[0] + b_minus_a) / 2;
 
    // a is calculated here
    num[0] = arr[0] - num[1];
 
    // to calculate all the other numbers
    for (int i=1; i<=(n-2); i++)
        num[i+1] = arr[i] - num[0];
 
    // display the numbers
    cout << "Numbers are: ";
    for (int i=0; i<n; i++)
        cout << num[i] << " ";
}
 
//Driver program
int main()
{
    int arr[] = {13, 10, 14, 9, 17, 21, 16, 18, 13, 17};
    int n = 5; // n is not size of array, but number of
               // elements whose pairwise sum is stored
               // in arr[]
    int k = sizeof(arr)/sizeof(arr[0]);
    cout << k << endl;           
    findNumbers(arr, n, k);
    return 0;
}
