class Solution:
    
    def findMax(self, nums):
        max_ = nums[0]
        max_idx = 0 
        for i in range(1, len(nums)):
            if nums[i] > max_:
                max_idx = i
                max_ = nums[i]
        return max_idx
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if nums:
            max_idx = self.findMax(nums)
            curr = TreeNode(nums[max_idx])
            curr.left = self.constructMaximumBinaryTree(nums[:max_idx])
            curr.right = self.constructMaximumBinaryTree(nums[max_idx+1:])
            
            return curr 
        
        
    
    
