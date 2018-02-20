global count 
count = 0


# recursive solution
def subsets(array, total, i ):
    if total ==0:
        return 1
    elif total < 0:
        return 0
    elif i <0 :
        return 0

    else:
        return subsets(array, total - array[i], i -1) + subsets(array, total, i -1)








x = [2,4,6,8,10,2]

total = 20
print("amount: ", subsets(x, total,len(x)-1 )) 

# 2 + 2 + 6 + 10
# 4 + 6 + 10
# 8 + 2  + 10
# 6 + 2 + 2 + 10
# 4 + 6 + 8 + 2 
# 8 + 2 + 10  


#for i in (range(int(input())):
#    array = [int(i) for i in input().split(",")]
#    total = int(input())
#    global count 
#    count = 0
#    print(subsets(array, total) )  
