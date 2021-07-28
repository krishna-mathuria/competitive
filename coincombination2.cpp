#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
 
 
 
int main(){
    int n,sum;
    cin>>n>>sum;
    int coins[n+2];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    dp[0][0]=1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-coins[i-1] >= 0) {
        	   (dp[i][j] += dp[i][j-coins[i-1]]) %= MOD;
            }
        }
    }
    cout<<dp[n][sum];
    return 0;
}