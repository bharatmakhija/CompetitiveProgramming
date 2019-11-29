#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

/*
Tile complexity of insertion sort is order of n square

it takes maximum time when elements are arranged inreverse order and minimum time (of order of n ) when elements are arranged in increasing order(nearly sorted).

it is generally used when number of elemets are small

It is inplace sorting algorithm i.e. we dont need to create another array to sort it , just a single key variable is used. 

it is a stable sorting algorithm. what do u mean by a stable sorting algorithm ::

A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input array to be sorted.
Some sorting algorithms are stable by nature like Insertion sort, Merge Sort, Bubble Sort, etc

can we Improve insertion sort? if yes! How?

Any sorting algorithm can be improved if we can reduce the no. of comparasions however we need to keep check that it remains stable. 

Yes Insertion sort can be improved using "BINARY INSERTION SORT"

We can use binary search to reduce the number of comparisons in normal insertion sort. Binary Insertion Sort find use binary search to find the proper location to insert the selected item at each iteration. 
In normal insertion, sort it takes O(i) (at ith iteration) in worst case. we can reduce it to O(logi) by using binary search.

Binary Insertion sort will actually make sense when the array size is large say 2000 or more elements and all are arranged in reverse order. in that case it will reduce the no of comparasions to exactly half 
of the elements.
Happy Coding!! 
Peace!

*/
void insertionSort(int *a, int len)
{
	for(int i = 1; i < len; i++){
	 
	 int key = a[i];
	 int j = i-1;
	
	while(j >= 0 && key < a[j])
	{
		a[j+1] = a[j];
		j--;
	}	
	  
	  a[j+1] = key;	
	}
}


int binarySearch(int *a,int key, int lowlimit, int uplimit)
{
	if(uplimit <= lowlimit)
    {
    	if(key > a[lowlimit])
    	return lowlimit + 1;
    	else
    	return lowlimit;
	}
	
	int mid = (lowlimit + uplimit)/2;
	
	if(key == a[mid])
	return mid + 1;
	
	if(key < a[mid])
	return binarySearch(a,key,lowlimit,mid-1);
	
	return binarySearch(a,key,mid+1,uplimit);
}


void binaryInsertionSort(int *a, int len)
{
	for(int i = 1; i < len; i++)
	{
		int key = a[i];
		int j = i-1;
		
		int loc = binarySearch(a,key,0,j); // this is the location where you are supposed to insert
		
		while(j >= loc)
		{
			a[j+1] = a[j];
			j--;
		}
		
		a[j+1] = key;
	}
}

int main()
{
	int n; 
	cin >> n;
	int *a = new int[n];
	for(int i=0; i < n; i++)
	cin >> a[i];
	printf("Enter number 1 for Insertion Sort or anything else for Binary Insertion Sort");
	int flag;
	cin >> flag;
	if(flag == 1)
	insertionSort(a,n);
	else
	binaryInsertionSort(a,n);	
	for(int i= 0; i < n; i++)
	printf("%d ",a[i]);
	return 0;
}


