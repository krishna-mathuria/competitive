class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    bool isValid(int x,int y,int n,int m,vector<vector<bool>> vis){
        if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==0) return true;
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image[0].size();
        int n = image.size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n+1,vector<bool>(m+1,0));
        q.push({sr,sc});
        int color = image[sr][sc];
        image[sr][sc]=newColor;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int xd = x+dx[i];
                int yd = y+dy[i];
                if(isValid(xd,yd,n,m,vis)){
                    vis[xd][yd]=1;
                    if(image[xd][yd]==color){
                        image[xd][yd] = newColor;
                        q.push({xd,yd});
                    }
                }
            }
        }
        return image;
    }
};