#!/bin/python3

import sys



def strange(t, mult):
    if t <= mult:
        return mult -t + 1
    return strange(t - mult, mult * 2)


t = int(input().strip())


print(strange(t, 3))



'''
# formula  [3* 2**i for i in range(100)]
multiple = 3 
while t > multiple:
    t -= multiple
    multiple *= 2 
print(multiple - t + 1 ) # track last valid multiple 
'''



   
