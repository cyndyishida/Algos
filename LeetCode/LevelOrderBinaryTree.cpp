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
    using dim = vector<int>;
    using Matrix = vector<dim>;
    using tup = std::pair< TreeNode*, size_t>;
    Matrix levelOrder(TreeNode* root) {
        Matrix matrix;
        tup current;
        size_t index = 0;
        
        std::queue<tup> queue_; 
        if (root)
            queue_.push(make_pair(root, index));
            {
                current = queue_.front();
                queue_.pop();
                index = current.second;
                if ( current.second >= matrix.size() )
                {
                    dim vect;
                    vect.emplace_back(current.first->val);
                    matrix.emplace_back(vect);
                }
                else
                {
                    matrix[current.second].emplace_back(current.first->val);
                }
                    
                if (current.first->left )
                    queue_.push(make_pair(current.first->left, index + 1 ));
                if (current.first->right)
                    queue_.push(make_pair(current.first->right, index + 1 ));
            }
        
        return matrix;
    }
        
};
