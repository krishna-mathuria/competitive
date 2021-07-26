#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[102][100005];

ll knapsack(ll wt[],ll v[],ll N,ll W,ll sum){
    if(N==0){
       if(sum!=0){
        return INT_MAX;
        }
    return 0;
    }

    if(dp[N][sum]!=-1)
        return dp[N][sum];
        
    else{
        return dp[N][sum] = min(knapsack(wt,v,N-1,W,sum-v[N])+wt[N],knapsack(wt,v,N-1,W,sum));
    }
    
}

int main(){
    memset(dp,-1,sizeof(dp));
    ll n,w,sum=0,mx=0,j;
    cin>>n>>w;
    ll wt[n+1],v[n+1];
    for(ll i=1;i<=n;i++){
        cin>>wt[i]>>v[i];
        sum+=v[i];
    }
    dp[1][0]=0;
    dp[1][v[1]]=wt[1];
    for(ll i=sum;i>0;i--){
        if(knapsack(wt,v,n,w,i)<=w){
            cout<<i;
            break;
        }
    }
}