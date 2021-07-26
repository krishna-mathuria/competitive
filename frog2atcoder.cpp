#include<bits/stdc++.h>
 
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;

    vector<ll> arr(n),dp(n,INT_MAX);
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    dp[0] = 0;
    dp[1] = abs(arr[0]-arr[1]);
 
    for(ll i=2;i<n;i++)
    {
        vector<ll> ardp;
        for(ll j=1;j<=k;j++)
        {   
            if(i-j>=0){
            ardp.push_back(abs(arr[i]-arr[i-j])+dp[i-j]);
            }
        }
       ll smallest = INT_MAX;
       for(ll j=0;j<ardp.size();j++){
           if(ardp[j]<smallest){
               smallest=ardp[j];
           }
           
       }
       dp[i]=smallest;
    }
    
    cout<<dp[n-1];
    return 0;
}