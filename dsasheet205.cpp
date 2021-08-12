class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST

    void inorder(vector<int> &in,Node* root)
    {
        if(!root)
        return;
        inorder(in,root->left);
        in.push_back(root->data);
        inorder(in,root->right);
    }
    void bst(Node* root, vector<int> &in, int &i)
    {
        if(!root)
        {
            return;
        }
        bst(root->left,in,i);
        root->data = in[i++];
        bst(root->right,in,i);
    }
    Node *binaryTreeToBST (Node *root)
    {
    vector<int> in;
    inorder(in, root);
    sort(in.begin(), in.end());
    int i =0;
    bst(root,in,i);
    return root;
    }
};