class Solution{   
public:
int dp[1001][1001];
int solve(int arr[],int i,int n){
    if(i==n) return arr[i];
    if(dp[i][n]!=-1) return dp[i][n];
    
    return dp[i][n] = max(arr[i]-solve(arr,i+1,n),arr[n] - solve(arr,i,n-1));
}
    bool is1winner(int N,int arr[]) {
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,N-1)>0;
    }
};