
"""
#O(n^3)
#brute force
def answer(l):
    counter = 0
    i,j,k = 0,1,2
    while k < len(l):
        i = 0
        while k - i >= 2:
            j = i + 1
            while j < k:
                if l[k] % l[j] == 0  and l[j] % l[i] == 0 :
                    counter += 1
                j += 1
            i +=1
        k += 1
    return counter
"""

def answer(l):
    count = 0
    # O(n^2)
    for i in range(len(l)):
        div_count = sum(1 for j in range(i) if not l[i] % l[j] )
        mul_count = sum(1 for j in range(i+1, len(l)) if not l[j] % l[i])
        count += div_count * mul_count

    return count

