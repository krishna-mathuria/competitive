class Solution 
{
    public:

    int orangesRotting(vector<vector<int>>& grid) {
        int t=-1;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        int n = grid.size();
        int m =grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    grid[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    if(a+dx[k]>=0 && b+dy[k]>=0 && a+dx[k]<n && b+dy[k]<m && grid[a+dx[k]][b+dy[k]]==1){
                        grid[a+dx[k]][b+dy[k]] = 0;
                        q.push({a+dx[k],b+dy[k]});
                    }
                }
            }
            t++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return t;
    }
};