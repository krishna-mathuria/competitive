class Solution
{
    public:
    void inorder(Node* root,int K,vector<int> &ans){
        if(root==NULL) return;
        inorder(root->left,K,ans);
        ans.push_back(root->data);
        inorder(root->right,K,ans);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int> ans;
        inorder(root,K,ans);
        return ans[ans.size()-K];
    }
};