class Solution {
public:
    
    void dfs(int i,int k,vector<int>& vis,vector<vector<int>>& connections){
        vis[i]=k;
        for(auto x : connections[i]){
            if(vis[x]==0)
                dfs(x,k,vis,connections);
            else continue;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>> graph(n);
        for(auto con : connections){
            graph[con[0]].push_back(con[1]);
            graph[con[1]].push_back(con[0]);
        }
        vector<int> vis(n+1);
        for(int i=0;i<n+1;i++){
            vis[i]=0;
        }
        int k=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                k++;
                dfs(i,k,vis,graph);
            }
        }
        return k-1;
    }
};