class Solution {
public:
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
    vector<int> ans;
    void leftboundary(TreeNode* root){
        if(root==NULL ||(root->left==NULL && root->right==NULL)) return;
        ans.push_back(root->val);
        if(root->left!=NULL)
            leftboundary(root->left);
        else
            leftboundary(root->right);
        return;
    }
    void leaves(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->val);
            return;
        }
        if(root->left)
            leaves(root->left);
        if(root->right)
            leaves(root->right);
    }
    void rightboundary(TreeNode* root,bool fl){
        if(root==NULL ||(root->left==NULL && root->right==NULL)) return;
        if(root->right!=NULL)
            rightboundary(root->right,1);
        else
            rightboundary(root->left,1);
        if(fl)
        ans.push_back(root->val);
        return;
    }
    vector<int> boundaryOfBinaryTree(TreeNode * root) {
        if(!root) return {};
        // write your code here
        if(root->left)
            leftboundary(root);
            else ans.push_back(root->val);
        leaves(root);
        if(root->right)
        rightboundary(root,0);
        return ans;
    }
};