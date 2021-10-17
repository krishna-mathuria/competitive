int solve(TreeNode* root,int targetSum)
    {
        if(root==NULL) return 0;
        
        return (targetSum == root->val?1:0)+solve(root->left,targetSum-(root->val))+solve(root->right,targetSum-(root->val));
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        return solve(root,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
    }