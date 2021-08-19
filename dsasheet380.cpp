#define MOD 1000000007
class Solution{
public:
    int nCr(int n, int r){
        // code here
        if(r>n) return 0;
        int dp[r+2]={0};
        dp[0]=1;
        for(int i=0;i<n+1;i++){
            for(int j=min(r,i);j>=1;j--){
                dp[j]=(dp[j]+dp[j-1])%MOD;
            }
        }
        return dp[r];
    }
};