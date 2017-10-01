/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        std::array<int, 20000> random_vals(INT_MIN);
        if (head)
        {
            RandomListNode deep_copy_head = *head;
            RandomListNode* deep_copy = &deep_copy_head;
            uint8_t counter = 0;
            while (head->next)
            {   ++counter;
                if (head->random)
                {
                    random_vals[counter] = head->random->label;
                }
                head = head->next;
                *(deep_copy->next) = *head;
            }
            
            


            
          for (auto el : random_vals)
                if (el != INT_MIN)
                    cout << el << " ";
            
            cout << "\n";

            return deep_copy;
        }
        return nullptr;
    }
};
