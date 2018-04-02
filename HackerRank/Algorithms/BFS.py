#!/bin/python3

import sys

def bfs(n, m, edges, s):
    # prepare the adjency list 
    adj_list = {}
    for v1, v2 in edges:
        adj_list[v1] = adj_list.get(v1, []) + [v2]
        adj_list[v2] = adj_list.get(v2, []) + [v1]

    # default key(node) value(distance to start node )
    node_dis = {i+1: -1 for i in range(n) if i+1 != s  }
    
    if s in adj_list:
        stack =[(j, 1) for j in adj_list[s]]
        in_stack = set(adj_list[s])
:w
        
        while stack:
            curr, level = stack.pop(0)
            node_dis[curr] = 6* level 
            level +=1 
            
            # traverse current children, guarentee its not already in stack 
            for c in adj_list[curr]:
                if c != s and not c in in_stack  :
                    stack.append((c, level )) 
                    in_stack.add(c)
                
    return list(node_dis.values())
    
    
    
    
    
if __name__ == "__main__":
    q = int(input().strip())
    for a0 in range(q):
        n, m = [ int(i) for i in input().strip().split(' ')]
        
        edges = []
        for edges_i in range(m):
           edges.append([int(edges_temp) for edges_temp in input().strip().split(' ')])
        s = int(input().strip())
        print( " ".join(map(str, bfs(n, m, edges, s))))
