#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long int m,n,k;
    cin>>m>>n>>k;
    long long res = n*k;
    if(m>res){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
    return;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}