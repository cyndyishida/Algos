"""
given an array, find the highest count of elements in a subarray where the theres only 2 distinct elements
so like [1,2,1,3,1,2,1,2,1] would be 5
"""

def unique_type(type_0, A):
    next_unique = None
    type_2 = None
    for i in A:
        if i != type_0:
            type_2 =  i
            break
    return (False, type_2) if type_2 else (True, len(A))



def solution(A):
    # write your code in Python 3.6

    # greedy approach storing active state in counter and
    type_0 = A[0]
    type_2 = unique_type(type_0, A)
    if type_2[0]:
        return type_2[1]
    else:
        type_2 = type_2[1]

    stale_vals = []
    counter = 0

    i = 0

    while i < len(A):
        curr = (type_0, type_2)
        if A[i] in curr: # O(1) bc tuple is always len(2)
            counter += 1
        else:
            # store state in storage and clear counter
            stale_vals.append(counter)
            counter = 0
            i -=1
            type_0 = A[i]
            type_2 = unique_type(type_0, A[i:])[1]
            curr = (type_0, type_2)
            counter += 1

        i += 1

    stale_vals.append(counter) # could be copy but doesnt matter since we want the max


    return max(stale_vals)



