class Solution {
public:
    void bfs(int i,vector<vector<int>>& isConnected,vector<bool>& vis)
    {
        vis[i] = true;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int temp;
            temp = q.front();
            q.pop();
            for(int k=0;k<isConnected.size();k++){
                if(!vis[k]){ 
                    if(isConnected[temp][k]==1){
                        q.push(k);
                        vis[k]=true;
                    }
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n+1);
        for(int i=0;i<n;i++){
            vis[i]=0;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                bfs(i,isConnected,vis);
            }
        }
        return ans;
    }
};