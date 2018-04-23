/*
 * start from 0 and go n times if at end then keep the node before it and swap around 
 *
 *
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* temp = head;
        ListNode* after = head;
        ListNode* before = nullptr;
        
        while(temp)
        {
            temp = after;
            for(int i = 0; i < n; i++)
                temp = temp->next;
            
            before = curr;
            curr = after;
            after = after->next;
        }
        
        if (before->next == after)
            head = head->next; 
        else
            before->next = after;

        
        
        return head ;
        
    }
};
