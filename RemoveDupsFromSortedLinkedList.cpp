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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = nullptr;
        auto curr = head;
        bool found;
        while (curr)
        {
            found = false;
            while (curr->next && curr->val == curr->next->val) 
            {
                curr = curr->next;
                found = true;
            }
            if (found) 
                if (!prev || prev->val == curr->val)
                    head = curr->next;
                else 
                    prev->next = curr->next;                
            else
                prev = curr;
            
            curr = curr->next;

                
        }
        
        
        return head;
    }
};
