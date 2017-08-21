/*
Difficulty: Medium
create an array with the values from the linked list
perform a insertion sort on the array
load the values back into the linked list 

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
    ListNode* insertionSortList(ListNode* head) {
        
        std::vector<int> sorted;
        
        for (auto temp = head; temp != nullptr ; temp = temp->next)
            sorted.emplace_back(temp->val);

        
        
        for (size_t i = 1; i < sorted.size(); ++i)
        {
  
            size_t j = i-1;
            bool swap = false;
            while ( sorted[i] < sorted[j] ) 
            {
                swap = true;
                if (j != 0)
                    --j;
                else
                    break;
            }
            
           
            // remove selected element from array and insert into sorted portion of the array
            if (swap)
            {
                int remove_me = sorted[i];
                sorted.erase(sorted.begin() + i);
                sorted.insert(sorted.begin() + j ,remove_me );
            }
        }
    
        auto iter = head;
        for (size_t k = 0; k < sorted.size() && iter; iter= iter->next, ++k)
            iter->val = sorted[k];

        
        
        return head;
    }
};