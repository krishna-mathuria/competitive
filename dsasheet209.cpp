class Solution{
  public:
    // Return the Kth smallest element in the given BST 
    void inorder(Node* root,int K,vector<int> &ans){
        if(root==NULL) return;
        inorder(root->left,K,ans);
        ans.push_back(root->data);
        inorder(root->right,K,ans);
    }
    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
        vector<int> ans;
        inorder(root,K,ans);
        if(K>ans.size()) return -1;
        return ans[K-1];
    }
};