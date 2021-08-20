
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int dp[W+1]={0};
        for(int i=0;i<N;i++){
            for(int j=wt[i];j<=W;j++){
                dp[j] = max(dp[j],val[i]+dp[j-wt[i]]);
            }
        }
        return dp[W];
        
    }
};