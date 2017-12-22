count = 0

def helper(sum_a, exp, i, sum_c=1, used = []): 
    if i > 0:
        result = i ** exp
        sum_c += result
        used.append(i)
        if sum(i**exp for i in used) == sum_a :
            global count
            count += 1
            sum_c = 0
            used.remove(i)
        i -= 1
        helper(sum_a, exp, i, sum_c)
        if sum_c - result >= 0:
            used.pop()
            helper(sum_a, exp, i, sum_c - result)

            
            
def recurse(sum_a, exp):
    i = int(sum_a ** (1 / exp))  # exp-root
    
    helper(sum_a, exp, i)


sum_a = int(input())
exp = int(input())
recurse(sum_a, exp)
print(count)
