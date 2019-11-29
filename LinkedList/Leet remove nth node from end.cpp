/*
Given a linked list, remove the nth node from the end of list and return its head.
 Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
   
   Given n will always be valid.
   Try to do this in one pass.


**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


#include<bits/stdc++.h>
using namespace std;

 ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == NULL)
        return NULL;
        
        if(n==0)
        return head;
        
        ListNode *p1, *p2,*p3;
        
        
       // case for first element
       
       p1 = head;
       p2 = head;
       
       while(n)
       {        
           p2 = p2->next;
           n--;
           if(n==0 && p2 == NULL)
           {
               head = head->next;
               return head;
           }
           
           if(p2 == NULL)
           return NULL;
       }
       
     
       while(p2 != NULL)
       {   p3 = p1;
           p1 = p1->next;
           p2 = p2->next;
       }
       
       p3->next = p1->next;
       
       return head;
        
    }

