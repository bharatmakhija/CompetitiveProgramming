/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // so its taking vector of pointers to the lists 
        // see the code its easy to understand..always remember we want that everytime i will be having only 2 lists to merge
        ListNode* head =new ListNode(0);  
        if (lists.size()==0){return NULL;}
        head->next = lists[0];
        ListNode *p;
        ListNode *q;
        for (int i=1;i<lists.size();i++){
            p = head;
            q = lists[i];
            while (q){
                if (!p->next){
                    p->next = q;
                    break;
                }
                if (p->next->val<q->val){
                    p=p->next;
                }else{
                    ListNode *l = p->next;
                    p->next = q;
                    q=q->next;
                    p->next->next = l;
                    p=p->next;
                }
            }
        }
        return head->next;
    }
};
