/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/

ListNode* reverse(ListNode* x)
   {
       ListNode* res;
       res = x->next;
       res->next = x;
       x->next = NULL;
       return res;
   }

    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL)
        return NULL;
        
        if(head->next ==NULL)
        return head;
        
        ListNode * Head = new ListNode(0);
        ListNode *a;
        ListNode *b;
        ListNode *temp;
        
        temp = Head;
        a = head;
        
        while(a != NULL){
            // keep other part in b
            if(a->next == NULL)
            {
                temp->next = a;
                break;
            }
            b = a->next->next;
            a->next->next = NULL;
            temp->next = reverse(a);
            temp = temp->next->next;
            a = b;
        }
        
        return Head->next;
    }
