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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* rightbefore = nullptr;
        ListNode* curr = head;
        int len(0);
        while (curr->next )
        {
            ++len;
            rightbefore = curr;
            curr = curr->next;
        }
        len++;
        ListNode* chop = head;
        int remove_at  = len - n;
        cout << remove_at << endl;
        if (remove_at == 0)
            head = head->next;
        else if (n == 1)
            rightbefore->next = NULL;
        else
        {
            for (int i = 0; i < (remove_at-1) ; ++i)
                chop = chop->next;                
            chop->next = chop->next->next;
            
        }
        
        
        return head;   
    }
};
