class Solution:
    def swap_elements(self, nums, idx):
        el = nums[idx]
        nums[idx+1: ]= sorted(nums[idx+1:])
        for n in range(idx+1, len(nums)):
            if nums[n] > el: 
                ch = n
                break 
        nums[idx], nums[n] = nums[n], nums[idx]
            
    
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        idx = len(nums) -1
        was_swaped = True 
        while idx >= 0 and was_swaped:
            if idx -1 >= 0: 
                prev = idx -1 
                if nums[prev] < nums[idx]:
                    was_swaped = False 
            idx -=1 
        if not was_swaped: 
            self.swap_elements(nums, idx)
        else: 
            nums.sort()
