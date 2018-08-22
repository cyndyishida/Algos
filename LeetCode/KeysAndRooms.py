class Solution:

    class node:
        def __init__(self, edges):
            self.edges = edges
            self.seen = False 
            
            
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        adj_list = {i: self.node(rooms[i]) for i in range(len(rooms))}
    
        stack = [0]
        while stack:
            ix = stack.pop(0)
            curr = adj_list[ix]
            if not curr.seen:
                curr.seen = True 
                stack.extend(curr.edges)
        
        for v in adj_list.values():
            if v.seen == False: 
                return False 
        
        
        
        return True 
