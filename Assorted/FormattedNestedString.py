# Input: a2[3[c]]
# Output: abcccbccc

# Assume the string will always be valid.
# Input: z1[a]
# Input = a2[c]x2[d]
# what if there are no brackets  

#a2[b3[c]]

def get_all_nums(input_list, idx):
    int_val = []
    counter = 0
    while idx > -1 and input_list[idx].isnumeric():
        int_val.insert(0, input_list[idx]) 
        idx -=1 
        counter +=1
    return int("".join(int_val)), counter

def string_stack(input_str): 
    i = 0
    result = list(input_str) 
    auxillary_indicies = [] # treat like stack 
    
    while i < len(result): 
        if result[i] == '[': 
            auxillary_indicies.append(int(i))
        elif result[i] == ']':
            start = auxillary_indicies.pop() 
            num, idx = get_all_nums(result, start-1)
            current = num * result[start+1:i] 
            result[ start-idx : i+1] = current 
       
            if len(auxillary_indicies) != 0: # still within a scope
                i = auxillary_indicies[-1]
                pass 
        i += 1  
            
    return "".join(result) 
    
    
    
print(string_stack("a10[c]"))
print(string_stack("a2[c]x2[d]"))
print(string_stack("z1[a]"))
print(string_stack("a2[b3[c]]"))
print(string_stack("a3[b2[c]1[e]]d"))



