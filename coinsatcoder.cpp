#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    double arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    double dp[n+1][n+1],res=0;
    memset(dp,0,sizeof(dp));
    dp[1][0] = 1.0 - arr[1];
    for(int i = 2; i <= n; ++i)
        dp[i][0] = dp[i - 1][0] * (1.0 - arr[i]);
        
    dp[1][1] = arr[1];
    for(int i = 2; i <= n; ++i)
        dp[i][i] = dp[i - 1][i - 1] * arr[i];
        
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < i; ++j)
            dp[i][j] = dp[i - 1][j] * (1.0 - arr[i]) + dp[i - 1][j - 1] * arr[i];
    }
    
    for(int i = n / 2 + 1; i <= n; ++i)
        res += dp[n][i];
    
    cout << fixed << setprecision(10) << res;
}