from pprint import pprint
import pdb

class Node:
    def __init__(self, data):
        self.data = data
        self.discovered = False
        self.explored = False
    def __repr__(self):
        return "Node: {}, V: {}, F: {} "\
            .format(self.data, self.discovered, self.explored )
        
    def addToStack(self,stack):
        if  ( self.data and (not self.discovered )):
            self.discovered = True
            stack.append(self)
            return True
        else:
            return False
    
    def removeFromStack(self,stack ,counter ):
        if self.data ==1 and self.discovered:
            if not self.explored:
                self.explored = True
            else: 
                stack.pop()
                counter[0] +=1
            return True

            return False
       
    def refresh(self):
        self.discovered = False
        self.explored = False  
    
def dfs(grid, row, col, counter, stack ):
    if stack:
        go_back = False
        if col+1 < len(grid[0]):
            
            if grid[row][col +1].addToStack(stack): # right child
                return dfs(grid, row, col+1, counter, stack)
            
            elif (grid[row][col +1].removeFromStack(stack,counter)):
                go_back = True
            
        if row+1 < len(grid):  # bottom child
            if grid[row+1 ][col].addToStack(stack):
                return dfs(grid, row + 1 , col, counter, stack)
            
            elif (grid[row+1][col].removeFromStack(stack,counter)):
                go_back = True
            
        if col - 1 > 0: # left child      
            if grid[row][col-1].addToStack(stack):
                return dfs(grid, row, col -1 , counter, stack)
            
            elif (grid[row ][col-1 ].removeFromStack(stack,counter)):
                go_back = True 
        
        if row - 1 >= 0: # above child      
            if grid[row-1][col].addToStack(stack):
                return dfs(grid, row-1 , col , counter, stack)
            
            elif (grid[row-1 ][col].removeFromStack(stack,counter)):
                go_back = True 
        
        if (row-1 >= 0) and (col + 1 < len(grid[0])) :  # diagonal left up child
            if grid[row-1 ][col+1].addToStack(stack):
                return dfs(grid, row - 1 , col + 1, counter, stack)
           
            elif (grid[row-1][col+1].removeFromStack(stack,counter)):
                go_back = True       
            
        if not stack:
            stack.pop()
        
        
    
def refresh(grid):
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            grid[i][j].refresh()
        
def getBiggestRegion(grid):
    counters = []
    for row in range(len(grid) ):
        for col in range(len(grid[0]) ):
            if grid[row][col].data:
                stack = [grid[row][col]]
                grid[row][col].discovered = True
                counter= [1]
                dfs(grid, row , col, counter, stack )
                counters.append(counter[0])
                refresh(grid)
      
    return max(counters)
    
    
    
fp = open("test.txt")    

n = int(fp.readline().strip())
m = int(fp.readline().strip())
grid = []
for grid_i in range(n):
    grid.append(list( Node(int(i)) for i in fp.readline().strip().split()))
    
print(getBiggestRegion(grid))
