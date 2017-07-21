'''
pop from front and append k times - 
O(K) algo 
'''
def array_left_rotation(a, n, k):
    for i in range(k):
        a.append(a.pop(0))

n, k = map(int, input().strip().split(' '))
a = list(map(int, input().strip().split(' ')))
array_left_rotation(a, n, k)
print(*a, sep=' ')