

/* Leet Merge 2 sorted Linked Lists
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/
#include<bits/stdc++.h>
using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
    
    ListNode* res = new ListNode(0);
    ListNode* head = res;   
    ListNode* p1 = res;
     // what is the use of res you must be wondering , no use just for initializing structure pointer
     // when constructor for a strcture is defined you just can't create a pointer as " ListNode *p; " it will give error 
     // it must be initialized while decalration either as in line 14 or 15.
    if(l1 == NULL && l2 == NULL)
    return NULL;
    
    if(l1 == NULL)
    return l2;
    
    if(l2 == NULL)
    return l1;
    
    if(l1->val < l2->val || l1->val == l2->val)
    {
      head = l1;
      l1 = l1->next;
    }
    else
    {
     head = l2;
     l2 = l2->next;
    }
    
    p1 = head;
    
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val < l2->val || l1->val == l2->val)
        {
            p1->next = l1;
            l1 = l1->next;
            p1 = p1->next;
        }
        else
        {
            p1->next = l2;
            l2 = l2->next;
            p1 = p1->next;
        }
    }
    
    if(l1 != NULL)
    p1->next = l1;
    
    if(l2 != NULL)
    p1->next = l2;
    
    return head;
    
	}
