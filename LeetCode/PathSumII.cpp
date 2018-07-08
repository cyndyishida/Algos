class Solution {
    
    using Matrix = vector<vector<int>>;
    void pathSumHelper(TreeNode* &root, Matrix &matrix, vector<int> &path, int &curr, int &sum )
    {
        path.emplace_back(root->val);
        curr += root->val;
        if (!root->left && !root->right)
        {
            if (curr == sum ) 
                matrix.emplace_back(path);
            return ;   
        }
        
        if (root->left)
        {
            pathSumHelper(root->left, matrix, path, curr, sum);
            path.pop_back();
            curr -= root->left->val;
        }
        if (root->right)
        {
            pathSumHelper(root->right, matrix, path, curr, sum);
            path.pop_back();
            curr -= root->right->val; 
        }
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        Matrix matrix; 
        vector<int> path; 
        int curr = 0; 
        if (root)
            pathSumHelper(root, matrix, path, curr, sum );
          
        return matrix;
        
        
        
    }
};
