'''
first strip out the constant and coefficent, 
perform a simple simplication
return as string 
'''

def parser(a):
    a_a = a.index('+')
    a_a_num = int(a[:a_a] )
    a_b_num = int(a[a_a+1:-1])
        
    return  a_a_num, a_b_num

class Solution(object):
    
    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        first_a, first_b = parser(a)                        
        second_a, second_b = parser(b)       
        
        val_1 = first_a * second_a
        val_2 = (first_a * second_b) + (first_b * second_a) # i coefficent
        val_3 = first_b * second_b * -1 # i^2 coefficent 
        return str(val_1 + val_3 )+ "+"+str(val_2) + "i"