'''
xor every element in the array 
'''
class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i,j = 1, len(nums) -1 
        
        x = nums[0]
        while i < j:
            x ^= nums[i]
            x ^=nums[j]
            j-=1
            i+=1
            
        return x