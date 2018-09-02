# Algorithms and Data Structures Practice 
Mostly just problems I did on Hackerrank and Leetcode



# Important Notes
Mostly from Algorithm Design Manual 
## Trees  
## Graphs 
- the space complexity for a DFS is the call stack (or iterative space) of the root to the depth of the longest back tracking path i.e. height of tree 
- the space complexity for a BFS is the width of the tree 
- no perfect formula to compute the number of possible paths in a graph bc it depends on the graph structure
## Combinatorial Search and Heuristic Methods
### BackTracking 
- Backtracking guarentees enumeration of all possibilities w/ no duplications in computation 
- 2**N possible subsets (combinations) for N 
- N! possible permuations for N 
### Pruning 
- cutting off the search the instant we have established that a partial solution cannot be extended into a full solution
- removing partial solutions identical to those previously considered requires recognizing underlying symmetries in the search space. 
    i.e. no need to traverse i=2 if path is cyclical to i = 1 
    
