class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        deque<TreeNode*> q;
        vector<vector<int>> ans;
        q.push_front(root);
        int level=1;
        while(!q.empty()){
            int size = q.size();
            vector<int> vec;
            while(size--){
                TreeNode* temp;
                if(level%2==0){
                    temp = q.front();
                    q.pop_front();
                }
                else{
                    temp = q.back();
                    q.pop_back();
                }
                vec.push_back(temp->val);
                if(level%2==1){
                    if(temp->left) q.push_front(temp->left);
                    if(temp->right) q.push_front(temp->right);
                }
                else{
                    if(temp->right) q.push_back(temp->right);
                    if(temp->left) q.push_back(temp->left);
                }
            }
            level++;
            ans.push_back(vec);
        }
        return ans;
    }
};