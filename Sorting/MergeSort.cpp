// this is merge sort:
/*
selection sort, bubble sort or insertion sort are not so fast as are of Order of n square in avg case
Merge Sort is Order of nlogn in worst case

it uses recursion as a programming concept
ex:

say i have an array : 2 4 1 6 8 5 3 7  ---------> sorting it ----> 1 2 3 4 5 6 7 8
merge sort basically divides the arrays in to two halfs and then merges them in the sorted order

lets divide the array in 2 arrays ::  2 4 1 6  and  8 5 3 7 
these two will be broken further and so on and merged in sorted order so suppose it will become

                                     1 2 4 6    and    3 5 7 8 
                                      
 now we have to merge them in sorted order to get our array back
 
   let i points to 1's location and j points to 3's location
   
   if(value at i < value at j   AND  i < sizeofarray AND j < sizeofarray) {
   select element from i's position;
   i++;
   }
   else
   {
     select element from j's position 
      j++;
   }


ex : 1 and 3 are compared --> 1 is selected for position 1. i is incremented.
     2 and 3 are compared --> 2 is selected for position 2. i is incremented.
     4 and 3 are compared --> 3 is selected for position 3. j is incremented.
     4 and 5 are compared --> 4 is selected for position 4. i is incremented.
     5 and 6 are compared --> 5 is selected for position 5. j is incremented.
     6 and 7 are compared --> 6 is selected for position 6. i is incremented and reaches the bound.
     so now all the elements are present in array two and they are already sorted. so just copy and paste them as it is. 
     
     
     // so in any case when one array is exhausted we just jave to copy the remaining elements from another , so code is
     
     if(i < sizeofarray)
     {
	   select ith element and copy it in original array.
	   i++;
	 }
	 
	 if(j < sizeofarray)
     {
	   select jth element and copy it in original array.
	   j++;
	 }
*/


#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

void Merge(int *arr, int * left, int *right, int len1, int len2)
{
	
	int k = 0;
	int i = 0;
	int j = 0;
	while(i < len1 && j < len2 )
	{
		if(left[i] < right[j])
		arr[k++] = left[i++];
		else
		arr[k++] = right[j++];
			
	} 
	//  by this either one of the two arrays is exhausted , so only one of the while loop will run
	
	while(i < len1)
	arr[k++] = left[i++];
	
	while(j < len2)
	arr[k++] = right[j++];
	
}

void printarray(int *x, int len)
{
	for(int i= 0; i < len; i++)
	cout << x[i] << " ";
	cout << "\n";
}

void MergeSort(int *arr, int l, int r)
{
	printf("Reaches in Merge sort for l = %d and r = %d \n",l,r);
	if(l < r){
	
	int len1,len2;	//lets split array in two halfs
	int mid;
	if((r - l)%2 == 0) // if it is even ==> it has odd number of values
     mid = (l+ r)/2;
     else
	 mid = (l + r + 1)/2;
	  
	// now will create 2 arrays and include mid int the right one
	
	
	len1 = mid - l;     // length of first array
	len2 = r + 1 - mid;
	
	int * left = new int[len1];
	int * right = new int[len2];
	
	int k = 0;
	for(int i=0; i < len1; i++)
	{
	   left[i] = arr[k++];
    }
    
    for(int i=0; i < len2; i++)
	{
	   right[i] = arr[k++];
    }
    // both arrays are populated
    cout << "printing left and right arrays\n";
    printarray(left,len1);
	printarray(right,len2);     
    MergeSort(left,l,mid-1);
    MergeSort(right,mid,r);
    
    Merge(arr,left,right,len1,len2);
}
}

int main()
{
	int n; 
	printf("enter no. of elements\n");
	cin >> n;
	int *arr = new int[n];
	printf("enter elements \n");
	for(int i=0; i < n; i++)
	cin >> arr[i];
	MergeSort(arr,0,n-1);
	for(int i=0; i < n; i++)
	cout << arr[i] << " ";
	return 0;
}
