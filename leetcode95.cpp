class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return helper(1,n);
    }
    
    vector<TreeNode*> helper(int s, int e) {
        if (s > e) {
             return vector<TreeNode*>(1,NULL);
        }
        
        vector<TreeNode*> result;
        for (int i=s; i <= e; ++i) {
            vector<TreeNode*> left, right;
                left = helper(s,i-1);
                right = helper(i+1,e);
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        TreeNode* root = new TreeNode(i);
                        root->left = left[j];
                        root->right = right[k];
                        result.push_back(root);
                    }
                }
        }
        
        return result;
    }
};