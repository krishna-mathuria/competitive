#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll n, ia,ib,ic;
    vector<ll> a,b,c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ia >> ib >> ic;
        a.push_back(ia);
        b.push_back(ib);
        c.push_back(ic);
    }

    ll dp[100001][3];
    for (int j =0; j < 3; j++){
        for (int i =0; i < 100001; i++) dp[i][j] = 0;
    }
    

    for(int i = 1; i <= n; i++){
        dp[i][1] = max(dp[i-1][0] + b[i-1], dp[i-1][2] + b[i-1]);
        dp[i][2] = max(dp[i-1][0] + c[i-1], dp[i-1][1] + c[i-1]);
        dp[i][0] = max(dp[i-1][1] + a[i-1], dp[i-1][2] + a[i-1]);
    }

    int res = 0;
    res = max({dp[n][0], dp[n][1], dp[n][2]});
    cout << res;
}
