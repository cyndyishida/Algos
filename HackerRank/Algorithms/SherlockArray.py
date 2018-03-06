def solve(a):
    '''
    keep track of index 
    maintain sum before and after 
    add to the start and remove from the end whenever sum isn' equal to eachother  
    '''
    start = a[0]
    end = sum(a[1:])
    i = 1 
    found = False 
    while not found and i < len(a) - 1 :
        end -= a[i]
        if end == start:
            found = True 
        start += a[i]
        i +=1 
    # sanity check, any element w/ 1 element is valid  
    return "YES" if found or len(a) == 1 else "NO"
