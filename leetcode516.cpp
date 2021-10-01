class Solution {
public:
    int longestPalindromeSubseq(string s) {
        long long int mod = 1000000007;
        int n = s.length();
        int dp[n][n];
        for(int g = 0; g < n; g++){
            for(int j = g, i = 0; j < n; i++, j++){
                if(g == 0){
                    dp[i][j] = 1;
                }
                else if(g == 1){
                    if(s[i] == s[j]) dp[i][j] = 2;
                    else dp[i][j] = 1;
                }
                else if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1]+2; 
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};