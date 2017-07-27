'''
create a adjecency list of nodes 
create a queue initalized with the root defined by the problem,
and the empty dictionary for all the reachable nodes from the root (attached to root in some way)
do a dfs, if node is reachable, add the key as the node, and it's parent as the value
for every ndoe in the set

if its in check, do a recursive dfs to find how many nodes away it is from the root 
else print -1
'''
def recursive_root_find(node, root, Graph,Checked ,weight = 0):
    return weight if  root == node else recursive_root_find(Checked[node], root, Graph, Checked, weight + 1)


for k in range(int(input())):
    #initialize 1 based graph
    nodes, edges = [int(i) for i in input().split() ]
    Graph = [ [] for i in range(nodes+1)]
    for i in range(edges):
        u, v = [int(i) for i in input().split() ]
        Graph[u].append(v)
        Graph[v].append(u)
    Graph.pop(0)
    
    # breadth first search 
    root = int(input())
    distance = [root]
    Checked ={}
    
    while distance:
        current = distance.pop(0)
        for node in Graph[current-1]:
            if node not in Checked and node != root: 
                Checked[node] = current
                distance.append(node)

    # go back and find the root 
    for n,i in enumerate(range(1,nodes+1)):
        if i == root:
            continue
        print(6 * recursive_root_find(i, root,Graph, Checked) if i in Checked else -1, end=  )
        
    print(n, end = )

# possible optimization: store distance from root, in bfs so there is not need to recursively go back?
