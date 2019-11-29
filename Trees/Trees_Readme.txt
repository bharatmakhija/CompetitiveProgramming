lets delve in to the world of trees: 
--------------------------------------
if a node of tree can have n childrens --> it is N-ary tree.
if a node of tree has 2 childrens --> it is Bi-nary tree.

we will see binary trees only:
---------------------------------------------------------
root: starting of the tree... i.e. that node which has no parent node
leaf nodes: if boths of its children are null then that node is called leaf node.  
intermediate nodes: all nodes except root and leaf nodes. 


Traversals:
-----------------
Inorder --> head, left and right
Preorder --> left , head, right
postorder --> right , left and then head 


size of  a tree == number of elements present in the tree
----------------------------------------------------------

see these--
.............................................................................................................................
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
................................................................................................................................
print ancestors of given target value assuming no element is repeated in the tree. 

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
................................................................................................................................
given a tree find max path sum of the tree .. i.e.
value of head + max path value of leftsubtree + maxpath value of right sub tree

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
.................................................................................................................................................................
count total number of nodes present in binary tree: // or the size of the binary tree
-----------------------------------------------------

int TotalNodes(node *head)
{
	if(head==NULL)
	return 0;
	
	int left, right;
	 left = TotalNodes(head->left);
	 right = TotalNodes(head->right);
	 
	 return 1 + left + right;
}
...................................................................................................................................................
Total number of leat nodes
--------------------------------

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
........................................................................................................................................................

