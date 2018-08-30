## brute force
#def answer(start, length):
#    x = 0
#    for i in range(length, 0, -1):
#        for j in range(i):
#            x ^= start
#            start += 1
#
#        start += (length - i)
#
#    return x

# brute force



# take advantage of the cycical pattern bit representation
# when incremented
def xor_bitRep (val):
    result  = 0
    if val % 4 == 0:
        result = val
    elif val % 4 == 1:
        result =  1
    elif val % 4 == 2:
        result = val+1
    else:
        result = 0

    return result

def answer(start, length):
    result = 0
    j = 0
    for i in range(length -1 , 0, -1):
        j += 1
        x = start + i
        y = start
        result ^= xor_bitRep( x ) ^ xor_bitRep(y-1)
        start = x + j
    return result ^ start



