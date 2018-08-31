class Solution {
public:
    
    // O(1) space 
    // O(N) time 
    ListNode* oddEvenList(ListNode* head) 
    {

        auto first = head;
        auto last = head;
        uint32_t counter = 0;

        // count
        
        for(;last && last->next; ++counter, last = last->next)
        {}
        
 
        if (counter >1)
        {
                    
            ListNode* tmp = nullptr;       
            for(uint32_t i = 0; i < (counter+1) / 2; ++i,head = head->next)
            {
                    tmp = head->next;
                    head->next = tmp->next;
                    tmp->next = nullptr;
                    last->next = tmp;
                    last = last->next;
            }
        }


        return first;

    }
};
