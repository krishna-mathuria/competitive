class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        long long dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        dp[1]=k;
        dp[2]=k*k;
        for(int i=3;i<=n;i++){
            dp[i]=((k-1)*(dp[i-1]+dp[i-2]))%1000000007;
        }
    
        return dp[n];
    }
    
    
};