/ Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {

    auto first = head;
    
    SinglyLinkedListNode* before = nullptr;
    auto curr = new SinglyLinkedListNode(data); 
    for(uint32_t i = 0; i < position && head; ++i)
    {   
        before = head;
        head = head->next;
    }
    
    if (!head)
        before->next = curr;
    else if (!before)
    {
        curr->next = head;
        first = curr;
    }   
    else
    {
        before->next = curr;
        curr->next = head;
    }
    
    
    return first;
    
    

}
