def getTotalX(a, b):
    #
    # Write your code here.
    #
    count = 0 
    div =[]
    smallest = min((a[0], b[0]))
    largest = max((a[-1], b[-1]))
    for i in range(smallest, largest +1):
        factor = True
        x = 0 
        while x < len(a) and factor:
            if  i % a[x] : 
                factor = False
            x +=1 
        if factor:
            factor = True 
            x = 0 
            while x < len(b) and factor:
                if b[x] % i :
                    factor = False 
                x +=1 
                    
            if factor:
                div.append(i)
            

    
    return len(div)
