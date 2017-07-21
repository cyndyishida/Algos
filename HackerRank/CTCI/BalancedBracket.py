'''
 if it's an opening bracket, switch case it & attach an index to it, in queue, append it
 if its a closing bracket, index it from array, and check to see if the last element in the queue has the same index, if at any point it doesn't or the queue has emptied out, return false 
 
 the queue must be empty at the end to be balanced 
'''

def is_matched(expression):
    c_in = ["{", "[", "("]
    c_out = ["}", "]", ")"]
    
    queue = []
    for i in expression:
        if i == c_in[0]:
            queue.append( (i, 0) )
        elif i == c_in[1]: 
            queue.append( (i, 1) )
        elif i == c_in[2]: 
            queue.append( (i, 2) )
        else:
            if not len(queue):
                return False
            if i == c_out[0]:
                if  queue.pop()[1] != 0:
                    return False
            if i == c_out[1]:
                if  queue.pop()[1] != 1:
                    return False
            if i == c_out[2]:
                if  queue.pop()[1] != 2:
                    return False
    return not len(queue)
    

t = int(input().strip())
for a0 in range(t):
    expression = input().strip()
    print( "YES" if is_matched(expression) else "NO")