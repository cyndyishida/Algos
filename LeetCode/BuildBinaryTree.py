# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    
    def build_helper(self, preorder, inorder):
        if preorder and inorder:
            root_ix = inorder.index(preorder[0])
            curr = TreeNode(preorder[0])

            curr.left = self.build_helper(preorder[1:root_ix +1 ], inorder[0: root_ix])
            curr.right = self.build_helper(preorder[root_ix + 1: ], inorder[root_ix+1 :])

            return curr
        return None
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        return self.build_helper(preorder, inorder)
