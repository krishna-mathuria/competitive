class Solution {
public:
    unordered_map<TreeNode*,int> dp;
    int rob(TreeNode* root) {
         if(root==NULL) return 0;
        if(dp[root]!=0) return dp[root];
        int inc = root->val;
        if(root->left!=NULL){
            inc+=rob(root->left->left) + rob(root->left->right);
        }
        if(root->right!=NULL){
            inc += rob(root->right->left) + rob(root->right->right);
        }
        int temp = 0;
        temp +=rob(root->left)+rob(root->right);
        dp[root] = max(temp,inc);
        return dp[root];
    }
};