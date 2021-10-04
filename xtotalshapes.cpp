class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    bool isValid(int x,int y,vector<vector<char>>& grid,vector<vector<bool>>& vis){
        if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && vis[x][y]==false){
            vis[x][y]=true;
            if(grid[x][y]=='X') 
                return true;
            else return false;
        }
        return false;
    }
    void bfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int i,int j){
        vis[i][j]=true;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto temp = q.front();
            int x = temp.first;
            int y = temp.second;
            q.pop();
            if(isValid(x+1,y,grid,vis)){
                q.push({x+1,y});
            }
            if(isValid(x,y+1,grid,vis)){
                q.push({x,y+1});
            }
            if(isValid(x-1,y,grid,vis)){
                q.push({x-1,y});
            }
            if(isValid(x,y-1,grid,vis)){
                q.push({x,y-1});
            }
        }
    }
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),0));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='X'){
                    count++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};