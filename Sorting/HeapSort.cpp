// this is about Heap sort , lets check it out :P
//Heap sort is a comparison based sorting technique based on Binary Heap data structure. 
// It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for remaining element.


/*

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible

anything which is a Complete Binary Tree can be easily represented as array and array based representation is space efficient.

A Heap is represented as a complete binary tree therefore it is good to represent it as an array.

If the value in a parent node is greater(or smaller) than the values in its two children nodes. The former is called as max heap and the latter is called min heap.


complete binary tree is filled from left to right.

ex: 4  10  3  5  1   --> this is the array we have to sort

4 will be the root 
10 will be left child and 3 will be right child of 4 
5 and 1 will be left and right child of 10 

                          4
                         
					  10      3
					   
				    5   1  null null 
				    
we want this to get converted in to Max Heap --> i.e. parent value is greater than childs value
				    
*/


