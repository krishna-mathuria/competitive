class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        // code here
        int ans=0;
        int dp[N+1];
        for(int i=0;i<N;i++){
            dp[i] = 1;
            for(int j=0;j<i;j++){
                    if(abs(A[i]-A[j])==1){
                        dp[i] = max(dp[i],dp[j]+1);
                    }
                }
                ans = max(dp[i],ans);
            }
            return ans;
    }
};