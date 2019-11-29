/* Leetcode problem:

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/

class Solution {
public:



    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    
    int carry= 0;
    int sum = 0;
    int prev_carry = 0;
    int rem= 0;
    
    sum = l1->val+ l2->val + prev_carry;
    carry = sum / 10; // if sum >= 10 it will generate some carry
    rem = sum % 10; 
    ListNode* x = new ListNode(rem); // node is created with remainder
    ListNode *y;
    y = x;
    l1 = l1->next;
    l2 = l2->next;
    prev_carry = carry; // till this point we created the first node which is being pointed by x and y. 
   
    while(l1 != NULL || l2 != NULL || prev_carry != 0) 
    {
        if(l1 == NULL && l2 == NULL)  // for every possible condition we created the sum variable
        sum = prev_carry;
        else if(l1 == NULL)
        sum = prev_carry + l2->val;
        else if(l2 == NULL)
        sum = prev_carry + l1->val;
        else
        sum = prev_carry + l2->val + l1->val;
        
        carry = sum / 10;
        rem = sum % 10;
        //cout << rem << " " ;
        y->next = new ListNode(rem);
        y= y->next;
        if(l1)
        l1 = l1->next;
        if(l2)
        l2 = l2->next;
        prev_carry = carry;
    }
    return x;
    }
};
