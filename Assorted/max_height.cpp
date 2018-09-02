/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/* Computes the height of binary tree with given root.  */
int height(Node* node)
{
    if (!node)
        return 0;
        
   else if (node->left )
       height(node->left);
       
   else if (node->right)
       height(node->right ) ;
   
    return std::max(height(node->left), height(node->right)) + 1;
}
