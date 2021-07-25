class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        vector<int> in(inorder), post(postorder);
        return postdfs(in, post, (TreeNode *)NULL);
    }

    TreeNode * postdfs(vector<int> & in, vector<int> & post, TreeNode * stop) {
        if ( post.empty() || (stop && in.back() == stop->val) ) {
            return NULL;
        }
        TreeNode * root = new TreeNode(post.back());
        post.pop_back();
        root->right = postdfs(in, post, root);
        cout<<in.back();
        in.pop_back();
        root->left = postdfs(in, post, stop);
        return root;
    }
};