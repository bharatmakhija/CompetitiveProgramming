/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
  
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      
	 // story starts here .. k is given     
     if(head == NULL)
     return NULL;
     
     if(k == 1) // if k == 1 i.e. no reversal is required also if k > length of the list this condition is indirectly checked below
     return head;
     
     
     int num = k;
     
     ListNode* x = head;
     ListNode* y;
     ListNode* L1;
     ListNode* temp = head;
     ListNode* L2;
     num--;
     
     while(num--){
     if(temp->next != NULL)     
     temp = temp->next;
     else
     return head;  // see here if temp --> next == null it means k is more than size of linked list and so we return heaad
     }
     
     // now temp points at kth element up to which we need to reverse.. so lets divide ll in to 2 linked list 1st is x which is needed to be reversed and second is y on which we will process further.
     if(temp->next != NULL)
     y = temp->next;  // second list
     else
     y = NULL;  // second list can be null as when when length of linked list == k
     
     temp->next = NULL; 
     
        L1 = reverseList(x,reverseKGroup(y,k)); // now x will be reversed and y will become another head and k will remain same and will be assigned to L1
        return L1;
    }
};

// function use is here

 ListNode* reverseList(ListNode* head, ListNode* L2)
 {
 	// this is another function which  reverses the head and attaches L2 at its end and returns the linked list
 	
     if(head == NULL)
     return NULL;
     
     if(head->next == NULL) // single element
     return head->next;
     
     ListNode* x;
     ListNode* y;
     ListNode* a;
     
     // first part is to reverse the head list 
     a = head; // 1st element
     x= a->next; //2nd element
     y= x->next; // 3rd element
     
     while(x != NULL)
     {
         x->next = a;
         a = x;
         x = y;
         if(y != NULL)
         y = y->next;
     }
     head->next = L2;
     return a;
 }

