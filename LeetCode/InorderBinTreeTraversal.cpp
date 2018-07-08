class Solution {
public:
    void helper(vector<int>& list, TreeNode* &root)
    {
        if (root)
        {
        helper(list, root->left);
        list.emplace_back(root->val);
        helper(list, root->right);
        }
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> list; 
        helper(list, root);
        return list; 
    }
};
