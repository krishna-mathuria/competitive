class Solution {
private:
    struct Node {
        TreeNode* root; 
        TreeNode* parent;
        int depth;
        Node(): root(nullptr), parent(nullptr), depth(0) {}
        Node(TreeNode *root, TreeNode *parent, int depth): root(root), parent(parent), depth(depth) {}
    };
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<Node> q;
        q.push({root, nullptr, 0});
        Node cousin; 
        while (!q.empty()) {
            Node node = q.front();
            q.pop();
            
            if (!node.root) continue;
            
            if (cousin.root && node.depth > cousin.depth)
                return false;
            
            if (node.root->val == x || node.root->val == y) {
                if (cousin.root) {
                    return cousin.parent != node.parent;
                }
                else {
                    cousin = node;
                }
            }
            q.push({node.root->left, node.root, node.depth+1});
            q.push({node.root->right, node.root, node.depth+1});
        }
        return false;
    }
};