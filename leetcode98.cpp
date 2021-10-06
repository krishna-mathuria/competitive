class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return recursive(root, LONG_MIN, LONG_MAX);
    }
    
    bool recursive(TreeNode* node, long lower, long upper) {
        if (node==NULL) return true;

        if (lower < node->val && node->val < upper) {
            return recursive(node->left, lower, node->val) && recursive(node->right, node->val, upper);
        }

        return false;
    }
};