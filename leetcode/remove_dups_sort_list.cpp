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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL)return head;
        
        ListNode *cur = head->next;
        ListNode *prev = head;
        while(cur!=NULL)
        {
            if(prev->val != cur->val)
            {
                prev->next = cur;
                prev = cur;
            }
            cur = cur->next;
            if(cur == NULL)
                prev->next = cur;
        }
        return head;
    }
};
