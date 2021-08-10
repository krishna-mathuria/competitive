class Solution {
public:
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }
    void addLeaves(Node* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }

    vector <int> printBoundary(Node *root)
    {
        //Your code here
         if (!root) return {};

        vector<int> res;
        if (!isLeaf(root)) res.push_back(root->data);
        // add left boundary
        Node* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) res.push_back(cur->data);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
        // add leaf nodes
        addLeaves(root, res);

        cur = root->right;
        vector<int> tmp;
        // add right boundary
        while (cur) {
            if (!isLeaf(cur)) tmp.push_back(cur->data);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for (int i = tmp.size()-1; i >= 0; --i) {
            res.push_back(tmp[i]);
        }
        return res;
    }
};