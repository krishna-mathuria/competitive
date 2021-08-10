class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            root = t.first;
            mp[t.second] = root->data;
            if(root->left)q.push({root->left,t.second-1});
            if(root->right)q.push({root->right,t.second+1});
        }
        vector<int> ans;
        for(auto i:mp) ans.push_back(i.second);
        return ans;
    }
};
