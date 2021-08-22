class Solution{
    public:
    int dp[1001][1001];
    int solve(int arr[],int x,int y){
        if(x>y) return 0;
        
        if(dp[x][y]!=-1) return dp[x][y];
        
        int left  = min(solve(arr,x+1,y-1),solve(arr,x+2,y));
        int right = min(solve(arr,x+1,y-1),solve(arr,x,y-2));
        
        dp[x][y]=max(arr[x]+left,arr[y]+right);
        
        return dp[x][y];
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,n-1);
    }
};