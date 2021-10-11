class Solution {
public:
    int t=0;
    int ans=0;
    void solve(TreeNode* root,int k){
        if(root==NULL) return;
        solve(root->left,k);
        t++;
        if(k==t){
            ans = root->val;
        }
        solve(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        solve(root,k);
        return ans;
    }
};