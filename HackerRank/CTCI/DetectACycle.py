"""
store the data, if at any point while were traversing if we see it,
make flag true 


Detect a cycle in a linked list. Note that the head pointer may be 'None' if the list is empty.

A Node is defined as: 
 
    class Node(object):
        def __init__(self, data = None, next_node = None):
            self.data = data
            self.next = next_node
"""


def has_cycle(head):
    if not head:
        return False
    else:
        cycles = False 
        vals = []
        while head and not cycles:
            if head.data not in vals:   
                vals.append(head.data)
                head = head.next
            else:
                cycles = True
                
        return cycles
        
    