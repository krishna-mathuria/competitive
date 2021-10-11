class Solution {
public:
    int mx=0;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        int left = solve(root->left);
        int right = solve(root->right);
        mx = max(mx,left + right );
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int x = solve(root)-1;
        mx=max(x,mx);
        return mx;
    }
};