# perform merge sort
# keep global counter that counts every time you don't insert the value from the left side

fp = open("merge1.txt")

def merge(a,b,counter):
    c = []
    a.reverse()
    b.reverse()
    while a and b:
        temp = a if a[-1] < b[-1] else b
        c.append(temp.pop())
        if temp == b:
            counter[0] += len(a)

    restof = a if a else b
    restof.reverse()
    c.extend(restof)
    return c


def mergesort(x,counter):
    if len(x) <= 1:
        return x
    middle = len(x)//2
    a = mergesort(x[:middle],counter)
    b = mergesort(x[middle:],counter)
    return merge(a,b,counter)


def count_inversions(a, counter): 
    mergesort(a,counter)
    #print(mergesort(a,counter))
    return counter[0]

for a0 in range(int(fp.readline().strip())):
    n = int(fp.readline().strip())
    print(count_inversions(list(map(int, fp.readline().strip().split())),[0]) )

