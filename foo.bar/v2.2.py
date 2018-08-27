import math
def answer(total_lambs):

    # fib seq
    min_sum = 0
    min_h = 0
    a,b = 0, 1

    while min_sum < total_lambs:
        min_sum +=  (a + b )
        min_h += 1
        a, b = b, a + b

    # geo series 
    max_h = 0
    max_sum = 0
    curr = 1
    while max_sum + curr <= total_lambs:
        max_h += 1
        max_sum += curr
        curr *=2
    if total_lambs -max_sum >= ( curr / 2 ) + (curr / 4):
        max_h +=1
    return min_h - max_h


