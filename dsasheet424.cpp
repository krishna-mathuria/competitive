#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=4;
    int dp[n+1];
    dp[0]=0;
    dp[1] = 0;
    dp[2] = 1;
    for(int i=3;i<=n;i++){
        dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
    }
    cout<<dp[n];
}
 