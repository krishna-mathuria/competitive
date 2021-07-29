#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll a[n],sum=0,biggest=INT_MIN;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        if(a[i]>biggest) biggest=a[i];
    }
    if(sum%2==0 && biggest<=sum-biggest){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}