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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        
        bool same = (!p && !q) || (( p &&q ) && (p->val == q->val)); 
        std::queue<TreeNode*> ps;
        std::queue<TreeNode*> qs;
        ps.push(p);
        qs.push(q);
        while ( (!ps.empty()) && !(qs.empty()) && same)
        {
            auto p = ps.front();
            auto q = qs.front();
            ps.pop();
            qs.pop();
            
            if (p){
                ps.push(p->left);
                ps.push(p->right);
            }
            if (q) {
                qs.push(q->left);
                qs.push(q->right);                
            }
            
            same = (!p && !q) || (( p &&q ) && (p->val == q->val)); 
        }
        
        return same ;
        
    }
};
