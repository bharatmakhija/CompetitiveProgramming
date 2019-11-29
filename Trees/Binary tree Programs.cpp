#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// structure for node of a tree
struct node{
	int data;
	node *left;
	node *right;
};

node * getnode(int data) // it will return the node of a tree given data , set left and right pointers to NULL!!
{
	node *temp = new node[1];
	temp->data=data;
	temp->left= NULL;
	temp->right=NULL;
	return temp;
}

void printInorder(node *head)   // head then left and then right 
{
	if(head==NULL) 
	return;
	
	cout << head->data << endl;
	
	if(head->left)
	printInorder(head->left);
	
	if(head->right)
	printInorder(head->right);
}

void PrintAncestors(node *head, int target)
{
	// here we are supposed to print all ancestors of the target
	
	static int flag=0;  // flag value will be preserved accross recursive calls. both while  going in and coming out 
	
	if(head== NULL)
	return;
	
	if(head->data == target)
	{
		flag=1;
		return; // if flag is made 1 and returned then it will keep returning!! 
	}
	
	if(flag==0)
	PrintAncestors(head->left,target);
	
	if(flag==0)
	PrintAncestors(head->right,target);
	
	if(flag==1) // as target is reached, recursion wil go back and trace back all its parents , so now flag will remain 1 and head will get printed till the root --> i.e all parents of target will get printed!!
	cout << head->data << endl;	
}

int max(int a, int b)
{
	return a>b?a:b;
}

int maxpath(node *head)
{
	if(head == NULL)
	return 0;
	
	int left; int right;
	
	left = maxpath(head->left);
	right= maxpath(head->right);
	
	int ans;
	ans = head->data + max(left,right);
	
	return ans>=0?ans:0; 
}

int maxpathsum(node *head)
{
	if(head==NULL)
	return 0;
	
	int left; int right;
	left =  maxpath(head->left);
	right = maxpath(head->right);
	
	return (head->data + left + right);
}

int TotalNodes(node *head)
{
	if(head==NULL)
	return 0;
	
	int left, right;
	 left = TotalNodes(head->left);
	 right = TotalNodes(head->right);
	 
	 return 1 + left + right;
}

int LeafNodes(node *head)
{
	if(head == NULL)
	return 0;
	
	int left, right;
	left=LeafNodes(head->left);
	right=LeafNodes(head->right);
	
	if(head->left == NULL && head->right == NULL)
	return 1+ left + right;
	else
	return left+right;	
}

int main()
{
	node *head = getnode(2);
	head->left = getnode(3);
	head->right = getnode(5);
	head->left->left = getnode(4);
	head->left->right = getnode(6);
	head->right->left = getnode(7);
	head->right->right = getnode(-8);
	head->right->right->right = getnode(100);
	
	printInorder(head);
	
	// here i have this dummy tree and will create all the functions like find the height of binary tree, count no of nodes etc etc a long list of functions 
	// so here we go!!!!!!
	
	int target; cin >> target;
	PrintAncestors(head,target);
	
	// well success!! now what  
	// we will create a function that will give max path sum of a binary tree 
	// see this link :-  http://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
	
	int sum=0;
	sum = maxpathsum(head);
	cout << sum << endl;
	// done!!
	// what else..lets count no of nodes.. all leaf nodes, internal nodes , total nodes
	
	int totalnodes;
	totalnodes = TotalNodes(head);
	cout << totalnodes << endl;
	
	// lets find total leaf nodes 
	
	int leafcount;
	leafcount = LeafNodes(head);
	cout << leafcount << endl;
	
	return 0;
}
