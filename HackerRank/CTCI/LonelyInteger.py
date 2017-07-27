# xor the same number you will always get 0
# initialize x as the first element, and xor every value on

import sys
from copy import deepcopy
def lonely_integer(a):
    x= a[0]
    for i in range(1,len(a)):
        x^= a[i]
    return x      
        

n = int(input().strip())
print(lonely_integer([int(a) for a in input().strip().split()]))
