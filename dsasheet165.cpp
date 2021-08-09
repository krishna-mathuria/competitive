
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(struct Node* node){
        // code here 
    if(node==NULL)
        return 0;
    return 1 + max(height(node->left),height(node->right));
    }
    int diameter(Node* root) {
        // Your code here
    if(root==NULL)
        return 0;
    
    int left = height(root->left);
    int right = height(root->right);

    int l = diameter(root->left);
    int r = diameter(root->right);
    return max(left+right+1,max(l,r));
    }
};