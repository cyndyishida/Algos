
'''
given a set of strings return the ascii sum and if any of the unique sets have the same string sum in their collection return that value 
'''

def find_common_ascii_score(data):
    """
      TODO: Fill in this function
      NOTE: To find the ASCII value, use n = ord(character)
      Finds the common ASCII score across collections of strings
      :param data JSON object with collections of strings
      :return: Single score across all collections, or if none exists -1
    """


    full_set = set()
    n = 0 
    for key, values in data.items(): 
        temp_set = set()
        for v in values: 
            temp_set.add(sum(ord(ch) for ch in v))
       
        full_set = temp_set if n == 0 else full_set.intersection(temp_set)
        n += 1
        
        
        
    answer = -1
    if len(full_set) != 0:
        answer = full_set.pop()
    
    return answer 
   
