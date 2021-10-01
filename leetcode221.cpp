class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size()==0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), mx = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            if(matrix[i][0]=='1') mx=1;
            dp[i][0] = matrix[i][0]-'0';
        }
        for(int i=0;i<n;i++){
            if(matrix[0][i]=='1') mx=1;
            dp[0][i] = matrix[0][i]-'0';
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i && j && matrix[i][j]=='0'){
                    dp[i][j]=0;
                }
                else if(i && j) {
                    dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}) + 1;
                }
                mx = max(mx,dp[i][j]);
            }
        }
        return mx*mx;
        
    }
};