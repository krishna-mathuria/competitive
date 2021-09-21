#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 

void solve(){ 
    ll n; 
    cin>>n; 
    vector<ll> arr(n); 
    for(ll i=0;i<n;i++)cin>>arr[i]; 
    if(n>4){ 
        cout<<"NO"<<endl; 
        return; 
    } 
    cout<<"YES"<<endl; 
    for(ll i=0;i<n;i++){ 
        if(i%4==0) 
            cout<<arr[i]<<" 0\n"; 
        else if(i%4==1) 
            cout<<"0 "<<arr[i]<<endl; 
        else if(i%4==2) 
            cout<<-arr[i]<<" 0\n"; 
        else 
            cout<<"0 "<<-arr[i]<<endl; 
    } 
} 
int main() 
{ 
    ll tc=1; 
    cin>>tc; 
    while(tc--){ 
        solve(); 
    } 
    return 0; 
}