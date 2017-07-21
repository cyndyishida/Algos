'''
store the number as key and the difference of that number as value
for every value check first if the difference val is in the dictionary

- added additional index from the array as the value to print out correctly
- added function so the printing would be liked by hackerrank
- 1 indexed???
 
'''


def print_smaller(a, b):
    smaller = a if a < b else b
    larger = b if a == smaller else a
    print(smaller, larger)

for a0 in range(int(input().strip())):
    target = int(input().strip())
    n = int(input().strip())
    a = list(map(int, input().strip().split(' ')))
    hasht = {}
    for n,val in enumerate(a):
        diff = target - val
        if diff in hasht:
            print_smaller(hasht[diff][1] + 1 , n + 1)
            break
        else:
            hasht[val] = (diff ,n) 