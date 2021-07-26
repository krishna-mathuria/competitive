#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[102][100002];


ll knapsack(ll w[],ll v[],ll N,ll W){
    if(N==0 || W==0){
        return 0;
    }    
    if(dp[N][W]!=-1)
        return dp[N][W];
    
    if(w[N]<=W){
        return dp[N][W]= max(v[N]+knapsack(w,v,N-1,W-w[N]),knapsack(w,v,N-1,W));
    }
    else if(w[N]>W){
        return dp[N][W]=knapsack(w,v,N-1,W);
    }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    ll N,W;
    cin>>N>>W;
    ll w[N+1],v[N+1];
    for(ll i=1;i<=N;i++){
        cin>>w[i]>>v[i];
    }
    cout<<knapsack(w,v,N,W);
}