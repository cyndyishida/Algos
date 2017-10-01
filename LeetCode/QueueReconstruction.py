from operator import itemgetter
from copy import deepcopy
class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        largest_height = sorted(people, key=itemgetter(0), reverse = True)
        final_array = []
        
        while largest_height:
            temp_array = []
            current_max = largest_height[0][0]
            stop = False
            while largest_height and not stop:
                if largest_height[0][0] == current_max:
                    temp_array.append(largest_height.pop(0))
                    temp_array.sort(key=itemgetter(1))
                else:
                    stop = True
            if not final_array: 
                final_array = deepcopy(temp_array)
            else:
                for i in temp_array:
                    if i[1] == 0:
                        for index, j in enumerate(final_array):
                            if j[0] > i[0]:
                                break
                        final_array.insert(index, i)
                    else:
                        count_greaterthan = 0
                        for index, j in enumerate(final_array):
                            if j[0] >= i[0]:
                                count_greaterthan +=1
                            if count_greaterthan == i[1]:
                                break     
                        final_array.insert(index+1, i) # place after 
                
                        
        
        return final_array
