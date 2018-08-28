# memoized solution 
def find_all_starting(start,plus, original , mem):



    key = "st: " + str(start) + " pl: " + str(plus) + " or: "+ str(original)

    if key in mem:
        return mem[key]

    count =  0


    if start < plus:
        if start + plus == original:
            count +=1
            while start < plus:
                start += 1
                count += find_all_starting(start, plus - start,plus, mem)
        else:
            start +=1
            original = plus
            plus= original - start
            count += find_all_starting(start, plus, original, mem)


        mem[key] = count
        return count
    else:
        mem[key] = 0
        return 0


def answer(n):
    start = 1
    count = 0
    mem_table = {}
    while start < (n - start):

        count += find_all_starting(start,n -start, n , mem_table)
        start +=1

    return count


