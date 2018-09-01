/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next;
        
        while( current )
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            
        }
     
        return prev;
    }
};
