class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> arr;
    void solve(struct Node* root){
        if(root==NULL) return;
        solve(root->left);
        arr.push_back(root->data);
        solve(root->right);
    }
    vector<int> inOrder(Node* root) {
        // Your code here
        solve(root);
        return arr;
    }
};