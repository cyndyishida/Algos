/* algorithm for deleting a node from a singly linked list at a given position. 
 * this is optimial because, you dont need to special case for the head thus saving space. 
 * the std::exchange isn't integral to achieve not needing to special case.  
 * */

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {

    SinglyLinkedListNode** p = &head;
    int i{0};
    while(*p && i++ < position) p = &(*p)->next;
    delete std::exchange(*p, (*p)->next);
    
    return head;
}
