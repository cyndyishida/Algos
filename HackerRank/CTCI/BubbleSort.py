'''
basic bubble sort algo 

'''
def bubblesort (array):
    swap_count = 0
    for i in range(len(array) ):
        for j in range( len(array) - 1):
            if (array[j] > array[j+1]):
                array[j+1], array[j] = array[j], array[j+1]
                swap_count += 1 

    return swap_count 
            
                

n = int(input().strip())
a = list( int(i) for i in input().strip().split())
print("Array is sorted in",bubblesort(a), "swaps.")
print("First Element:", a[0])
print("Last Element:", a[-1])