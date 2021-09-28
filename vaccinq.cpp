#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,p,x,y;
    cin>>n>>p>>x>>y;
    int zeros=0;
    int ones=0;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(i<=p){
            if(arr[i]==0) zeros++;
            else ones++;
        }
    }
    long long res = (zeros*x)+(ones*y);
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}