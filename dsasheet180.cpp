class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    void toSumTree(Node *root)
    {
        // Your code here
        if(root==NULL) return;
        if(!root->left && !root->right)
            root->data = 0;
        else{
             int left = 0;
             int right = 0;
             if(root->left){
                 left = root->left->data;
                 toSumTree(root->left);
                 left+=root->left->data;
             }
             if(root->right){
                 right = root->right->data;
                 toSumTree(root->right);
                 right+=root->right->data;
             }
             root->data = left+right;
        }
    }
};