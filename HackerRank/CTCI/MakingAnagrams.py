'''
algorithm: iterate over the larger list and if a character is in both remove it 
from the smaller one, and count each time it isn't in the larger one.
return the counter plus the length of the smaller 

'''
def number_needed(a, b):
    larger = a if len(a) > len(b) else b
    smaller = b if a == larger else a 
    counter = 0
    for i in larger:
        if i in smaller:
            smaller.remove(i)
        else:
            counter +=1
    return counter + len(smaller)
    
print(number_needed([i for i in input().strip()], [i for i in input().strip()]))

