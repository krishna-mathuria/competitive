class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
    map<int,int> m;
    queue<pair<struct Node*,int> > que;
    que.push(make_pair(root,0));
    
    while(!que.empty())
    {
        pair<struct Node*,int> cur=que.front();
        que.pop();
        if(m.find(cur.second)==m.end())
            m[cur.second]=cur.first->data;
            
        if(cur.first->left)
        que.push(make_pair(cur.first->left,cur.second-1));
        if(cur.first->right)
        que.push(make_pair(cur.first->right,cur.second+1));
        
    }
    auto p=m.begin();
    while(p!=m.end())
    {
        ans.push_back(p->second);
        p++;
    }
        return ans;
    }

};