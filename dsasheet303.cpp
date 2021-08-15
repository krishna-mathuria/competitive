class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m =  grid[0].size();
	    
	    vector<vector<int>> res(n,(vector<int> (m,INT_MAX)));
	    queue<pair<int,int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push({i,j});
	                res[i][j]=0;
	            }
	        }
	    }
	    
	    int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++){
                int x = a+dx[k];
                int y = b+dy[k];
                if(x>=0 && y>=0 && x<n && y<m){
                    if(res[x][y]>res[a][b]+1){
                        res[x][y] = res[a][b]+1;
                        q.push({x,y});
                    }
                }
            }
        }
	    return res;
	}
};
