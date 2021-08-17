class Solution
{
    public:
    //Function to find the number of islands.

    bool isValid(int x,int y,int n,int m,vector<vector<bool>>& vis,vector<vector<char>> grid){
        if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==0 && grid[x][y]=='1') return true;
        return false;
    }
    void traverse(int i,int j,int n,int m,vector<vector<bool>>& vis, vector<vector<char>> grid){
        int dx[8]= { -1, -1, -1, 0, 0, 1, 1, 1 };
        int dy[8]= { -1, 0, 1, -1, 1, -1, 0, 1 };
        vis[i][j] = true;
        for(int k=0;k<8;k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(isValid(x,y,n,m,vis,grid)){
                traverse(x,y,n,m,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(n+1,vector<bool>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    traverse(i,j,n,m,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};