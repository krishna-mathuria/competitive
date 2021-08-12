class Solution {
public:
    int n;
    TreeNode* build(vector<int>&preorder, int &pos, int min, int max){
        if (pos >= n) return NULL;
        int val = preorder[pos];
        if (val > max || val <min) return NULL;
        
        TreeNode* node = new TreeNode(val);
        pos++;
        node->left = build(preorder, pos, min, val);
        node->right = build(preorder, pos, val, max);
        
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        this->n = preorder.size();
        if(n == 0) return NULL;
        int pos = 0;
        return build(preorder, pos, INT_MIN, INT_MAX);
    }
};