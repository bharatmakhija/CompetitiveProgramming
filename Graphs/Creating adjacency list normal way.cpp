#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*

for directly creating an adjacency list .. without graph datastructure this is another way!!
FYI here as you can see.. we can create multiple constuctors in a class.

*/
class node
{
	private:
	int value;
	node *next;
	public:
	node()  // empty constuctor
	{
		
	}
	
	node(int v,node * k) // node when value and next pointer is given.
	{
		value=v;
		next=k;
	}
	
void addedge(node **ptr,int src,int dest)
{
	node * abc = new node(dest-1,ptr[src-1]);
	ptr[src-1]= abc;
	node *cdf = new node(src-1,ptr[dest-1]);
	ptr[dest-1]=cdf;
}

	
	void printlist(node **ptr,int n)
	{ 
		for(int i=0;i<n;i++)
		{
			cout << i << " ";
			node *x= ptr[i];
			while(x)
			{
				cout << x->value << " ";
				x= x->next;
			}
			cout << endl;
		}
		
	}
};

	
	
int main()
{
	
	int n,m; // n is number of vertices, m is number of edges
	cin >> n >>m;
	node *adj[n]; // i.e. every adj[i] is a pointer which can point to a node sturcture , (node stucture contains  a value variable and next pointer )
	// infact adj is a pointer to pointer which is pointing to continuous location of size n. each location can store only location of a node type. so adj is a pointer to pointer of type node while adj[0]
	for(int i=0;i<n;i++)
	adj[i]= NULL;     // every adj[i] is initially pointing to NULL.  
	node **ptr;    // TO tranverse this adj[](array of pointers) what we need is a pointer to a pointer of type node. 
	ptr= adj;     // ptr now points to adj[0], this proves both adj and ptr are double pointers. so when i write adj[0] it becomes single pointer.
	
	for(int i=0;i<m;i++)  // for every edge i will need to insert into adjacency list
	{
		int x;int y;
		cin >> x >>y;
		/*
		   Now adj is array of pointer to node. 
		   adj[0] infact is element of array. 
		   
		   to access any variable or fuction of a class. 
		   If its an Object --> use dot "." notation
		   if its an array --> use pointing "->" notation. 
		*/
		adj[i]->addedge(ptr,x,y);  // see how fuction is accessed. 
	}
	adj[0]->printlist(ptr,n);

	return 0;
}
