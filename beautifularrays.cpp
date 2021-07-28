#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
 
ll solve(vector<int>& v, int n, ll x)
{
    ll dp[n+1][2][2];
    memset(dp, 0, sizeof dp);
 
    dp[0][1][0] = v[0];
    dp[0][1][1] = x*v[0];
 
    ll answer = max(0LL,max(1LL*v[0], x*v[0]));
 
    for(int i = 1; i < n; i++){
        dp[i][1][0] = max(1LL*v[i], v[i] + dp[i-1][1][0]);
        dp[i][1][1] = max(x*v[i], x*v[i] + max(dp[i-1][1][1], dp[i-1][1][0]));
        dp[i][0][0] = max(1LL*v[i], v[i] + max(dp[i-1][1][1], dp[i-1][0][0]));
        answer = max(answer, max(dp[i][1][0], max(dp[i][1][1], dp[i][0][0])));
    }
 
    return answer;
}
 
int main() {
    fast_io;
    int n,x;    
 
    cin >> n >> x;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    cout << solve(v,n,x) <<'\n';
 
    return 0;
}