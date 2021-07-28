#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007



int main(){
    ll n,sum;
    cin>>n>>sum;
    ll dp[sum+1],coins[n+1];
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<=n;i++){
        cin>>coins[i];
    }
    dp[0]=1;
    sort(coins+1,coins+n+1);
    for (int i = 1; i <= sum; i++) {
        for (int j = 1; j <= n; j++) {
            if (i-coins[j] >= 0) {
        	   (dp[i] += dp[i-coins[j]]) %= MOD;
            }else{
                break;
            }
        }
    }
    cout<<dp[sum];
}