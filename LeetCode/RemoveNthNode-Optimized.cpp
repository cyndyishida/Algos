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

        std::unordered_map<int, ListNode*> indexes;
        ListNode* curr = head;
        int len(0);
        
        while(curr)
        {
            indexes[len++] = curr;
            curr = curr->next;
        }

        int remove_at = len - n;        
        if (remove_at == 0)
                head = head->next;
        else
            indexes[remove_at-1]->next = indexes[remove_at+1]; // thank god for c++ inits 

        
        return head;   
    }
};
