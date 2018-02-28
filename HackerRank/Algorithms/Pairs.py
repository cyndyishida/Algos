#!/bin/python3

import sys

#def pairs(k, arr):
#    # Complete this function
#    # initial 
#    count = 0 
#    #arr.sort()
#    for i in range(len(arr)  -1 ):
#        for j in range(i+1, len(arr)):
#            if abs(arr[i] - arr[j]) == k:
#                count +=1 
#            
#    
#    return count 

    
def pairs(k, arr):
    # Complete this function
    # optimized.
    # linear algorithm 
    # checkthe addition value is in the set, since its all unique 
    count = 0
    
    for el in arr:
        if el + k in arr:
            count += 1 
    return count 


