/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void inorder(TreeNode* root, std::vector<int>&  els) {
        if (root) {
            inorder(root->left, els);
            els.emplace_back(root->val);
            inorder(root->right, els);
            
        }
        
    }
    
    int getMinimumDifference(TreeNode* root) {
        int min_diff = INT_MAX;
        std::vector<int> els;
        inorder(root, els);
        auto it = els.begin();
        auto temp = it + 1; 
        int ab; 
        for( ;temp != els.end() ; ++it, ++temp){
            ab = abs(*it- *temp );
            if (ab < min_diff)
                min_diff = ab;
            
        }
        
        
        return min_diff;
        
    }
    
    
    
    
};
