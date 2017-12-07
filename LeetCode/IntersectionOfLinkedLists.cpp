

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
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        

        size_t len_a = 0, len_b = 0;
        
        
        auto A = headA;
        auto B = headB;
        
        // get len of A 
        ListNode* prevA = nullptr;
        while(headA->next )
        {
            prevA = headA;
            headA = headA->next;
            ++len_a;
        }
        
        // get len of B 
        ListNode* prevB = nullptr;
        while(headB )
        {
            prevB = headB;
            headB = headB->next;
            ++len_b;
        }
        
        
        // no connection
        if (len_a == 0 || len_b == 0 || prevB != prevA)
            return NULL;
        

        
        if (len_a >= len_b)
        {
            len_a = abs(len_a - len_b);
            
            for (int i = 0; i < len_a ; ++i)
                A = A->next;
            
            
            
        }
        else
        {
            len_b = abs(len_b - len_a);
            
            for (int i = 0; i < len_b ; ++i)
                B = B->next;
        
        }
        
        
   
        while (A != B )
        {
            

            A = A->next;
            B = B->next; 
                
        }
        
        
        
        return A;
        

    }




};






