from string import ascii_lowercase as ascii
from pprint import pprint
from time import *
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
    for i in entry:
        node = trie.add_child(i)
        node.count +=1
        trie = node
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
    
    
fp = open("test.txt") 
    
root = Node(' ', ' ')   
start = clock()
for z in  range(int(fp.readline())):
    trie = root 
    op, entry = fp.readline().split()
    if op == 'add':
        addToTrie(entry, trie)
    if op == 'find':
        print ( findInTrie(entry, trie) )

print("Time took: ", clock() - start)
