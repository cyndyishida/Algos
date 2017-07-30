'''
Algo: use a trie to solve algo.
node that contains a parent, value, dictionary of children, and a count of how many times it appears inside a word

when adding, iterate over the first 6 characters, if word is longer store the rest in a single node increment the node every it could appear in the path (python classes are default mutable)
for find in trie,
create a boolean to detect non found
for each character in the entry if the node is a child of the previous node keep going and make that the new current node, else its no match and break out 
once your done traverseing return the node count for the last node else return 0
'''


class Node:
    def __init__(self, parent , val):
        self.parent = parent 
        self.val = val
        self.children = {}
        self.count = 0
        
    def __repr__(self):
        return "Parent: {} My Value: {}, NumWords: {} ".format(self.parent, self.val, self.count)
      	
    def get_child(self, obj):
        return self.children[obj] if obj in self.children else None
    
    def add_child(self, obj):
        child = self.get_child(obj)
        if not child:
            child = Node(self.val, obj)
            self.children[obj] = child
        return child
                

def addToTrie(entry, trie):
    for i in range(len(entry)):
        if i <6:
            node = trie.add_child(entry[i])
            node.count +=1
            trie = node
        else:
            node = trie.add_child(entry[i:])
            node.count +=1
            trie = node
            break

    node.add_child('*')
    
def findInTrie(entry, trie): 
    no_match = False  
    word_count = 0
    for ch in entry:
        node = trie.get_child(ch)
        if node:
            trie = node
        else:
            no_match = True
            break
    return 0 if no_match else node.count
    
    
    
root = Node(' ', ' ')   
for z in  range(int(input())):
    trie = root 
    op, entry = input().split()
    if op == 'add':
        addToTrie(entry, trie)
    if op == 'find':
        print ( findInTrie(entry, trie) )

