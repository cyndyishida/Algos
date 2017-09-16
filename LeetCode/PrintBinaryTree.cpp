
class Solution {
public:
    
    using Matrix = vector<vector<string>>; 
    
    int height( TreeNode* root ){ return root? 1 + std::max(height(root->left) , height(root->right)) : -1 ; }
    
    void find_index( Matrix& string_matrix, TreeNode* root, int start, int end, int distance)
    {
        if (root)
        {
            int index = (end + start) /2;  
            string_matrix[distance+1][index] = to_string(root->val);
            
            find_index(string_matrix, root->left, start, index, distance + 1);
            find_index(string_matrix, root->right, index +1 , end, distance + 1 );            
        }
        
    }
    
    
    
    
    Matrix printTree(TreeNode* root) {
        
        // upfront info         
        int max_height = height(root);
        int spaces= std::pow(2, max_height+1);
        
        cout << max_height << endl;
        vector<string> list(spaces - 1 , "");
        Matrix string_matrix(max_height+1, list );
        
    
        
        
        int start = 0;
        int end = list.size();
        int mid = list.size() / 2;
        int distance = 0;
        // root placing
        string_matrix[distance][mid] = to_string(root->val);
    
        find_index(string_matrix, root->left,start, mid, distance);
        find_index(string_matrix, root->right, mid+1, end, distance);
        
        

        
        
        
        return string_matrix; 
    }    
};
