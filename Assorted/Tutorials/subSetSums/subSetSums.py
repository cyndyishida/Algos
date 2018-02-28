from pprint import pprint 

# recursive solution (1.76)
def subsets(array, total, i ):
    if total ==0:
        return 1
    elif total < 0:
        return 0
    elif i <0 :
        return 0

    else:
        return subsets(array, total - array[i], i -1) + subsets(array, total, i -1)




# memoized solution (0.05)  
def subset_memo(array, total, i, memo = {} ):
    if not (total, i) in memo: 
        if total == 0: 
            memo[(total, i)] = 1
        elif total < 0 or i < 0 : 
            memo[(total, i)] = 0
        else:
            memo[(total, i)] = subset_memo(array, total - array[i] , i - 1, memo) + \
subset_memo(array, total , i - 1, memo)
        
        
        
    return memo[(total,i)]


def valid_sum(r, current_sum, c):
    if r > len(current_sum):
        return False 
    if r == len(current_sum):
        return sum(current_sum) == c
    



# dynamic solution 
def subset_dp(array, total): 
    count = {}
    rows = len(array) + 1 # 0 should be the empty set. # denotes how many elements are being used
    cols = total + 1 
    
    count[(0,0)] = 1

    for el in array:
        count[ el ] = count.get(el, 0) + 1 


    for r in range(2, rows): # r represents how many elements are used
        if r > 2: 
            break

        c_sum = 0
        c = 1
        non_redundent = 0 
        last =c 
        while c < total +1 :
            if c in count:
                non_redundent +=1  
                if non_redundent >= r : 
                    count[c_sum + c] = count.get(c_sum + c , 0 ) + 1 
                    count [c_sum -last ] =  count.get(c_sum -last , 0 ) + 1 
                c_sum += c 
                last = c 
                
            c += 1




    #dp = [[0]*cols for g in range(rows) ]
    #
    #dp[0][0] = 1

    #for el in array:
    #            dp[1][el] += 1


    #for r in range(2, rows): # r represents how many elements are used    
    #    #if r > 2:
    #    #    break
    #    c_sum = 0
    #    for c in range(1, cols): # c represents current total   
    #        if dp[r-1][c] != 0: 
    #            count[(c, r) ] = count.get((c,r), 1 ) 
    #            c_sum += c 
    #            count[(c_sum, r + 1 )] = count.get((c_sum ,r ),1) 
    #        dp[r][c] =  count.get((c,r), 0 ) 
    #            


    #dp.insert(0,[m for m in range(17) ])
    #pprint(dp)
    pprint(count)





x = [2,4,6,10]

total = 16 
print("amount: ", subsets(x, total,len(x)-1 )) 
y = {}
print("amount: ", subset_memo(x, total,len(x)-1,y ))

print("\n")
print("amount: ", subset_dp(x, total))  
