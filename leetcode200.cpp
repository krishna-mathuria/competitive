class Solution {
public:
    bool isValid(int i,int j,vector<vector<bool>>& vis,vector<vector<char>>& grid){
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size()){
            if(!vis[i][j] && grid[i][j]=='1') return true;
        }
        return false;
    }
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& vis)
    {
        vis[i][j] = true;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            pair<int,int> temp;
            temp = q.front();
            int x = temp.first;
            int y = temp.second;
            q.pop();
            if(isValid(x,y+1,vis,grid)){
                vis[x][y+1]=true;
                q.push({x,y+1});
            }
            if(isValid(x,y-1,vis,grid)){
                vis[x][y-1]=true;
                q.push({x,y-1});
            }
            if(isValid(x+1,y,vis,grid)){
                vis[x+1][y]=true;
                q.push({x+1,y});
            }
            if(isValid(x-1,y,vis,grid)){
                vis[x-1][y]=true;
                q.push({x-1,y});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),0));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
};
