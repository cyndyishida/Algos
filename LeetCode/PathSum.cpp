
class Solution {
public:

    bool pathHelper(TreeNode* root, int sum, int curr)
    {
        bool has_sum = false;

        curr += root->val;
        bool lhs = false, rhs = false;
        if (root->left && root->right)
        {
            lhs = pathHelper(root->left, sum, curr);
            rhs = pathHelper(root->right, sum, curr);
        }
        else if (root->right) rhs = pathHelper(root->right, sum, curr);
        else if (root->left) lhs = pathHelper(root->left, sum, curr);
        else return curr == sum;
        
        return lhs || rhs;

    }


    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        return pathHelper(root, sum, 0);




    }
};
