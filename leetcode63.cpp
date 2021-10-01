class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size()+1,vector<int>(obstacleGrid[0].size()+1,0));
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1) return 0;
        for(int i=1;i<=obstacleGrid[0].size();i++){
            if(obstacleGrid[0][i-1]==1) break;
            dp[1][i] = 1;
        }
        for(int i=1;i<=obstacleGrid.size();i++){
            if(obstacleGrid[i-1][0]==1) break;
            dp[i][1]=1;
        }
        for(int i=2;i<=obstacleGrid.size();i++){
            for(int j=2;j<=obstacleGrid[0].size();j++){
                if(obstacleGrid[i-1][j-1]==0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else dp[i][j]==0;
            }
        }
        return dp[obstacleGrid.size()][obstacleGrid[0].size()];
    }
};