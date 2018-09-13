/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/*

// recursive 
class Solution {
public:
    
    void grab_nodes(std::vector<int>& nodes, Node* root)
    {
        if (root)
        {
            nodes.emplace_back(root->val);
            for (auto n : root->children)
            {
                grab_nodes(nodes, n );
            }
        }
    }
    
    vector<int> preorder(Node* root) {
        
        
        std::vector<int> nodes;
        grab_nodes(nodes, root);
        return nodes;
        
    }
};

*/
class Solution {
public:
   // iterative  
    void grab_nodes(std::vector<int>& nodes, Node* root)
    {
        
        
        std::stack<Node *> dfs_storage;
        dfs_storage.emplace(root);
        while(!dfs_storage.empty())
        {
            
            
            Node * curr = dfs_storage.top();
            dfs_storage.pop();
            
            if (curr)
            {
                nodes.emplace_back(curr->val);

                for (int i=curr->children.size() - 1; i >=0 ; --i)
                {
                    auto n = curr->children[i];
                    dfs_storage.emplace(n);
                }
                
            }
        }
    }
    
    vector<int> preorder(Node* root) {
        
        
        std::vector<int> nodes;
        grab_nodes(nodes, root);
        return nodes;
        
    }
};


