#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long int a,b;
    cin>>a>>b;
    if(b%2!=0 && a%2==0){
        cout<<"NO\n";
        return;
    }
    map<long long,long long> mp;
    long long x = b;
    int i=0;
    while(mp.find(x)==mp.end()){
        mp[x]++;
        if((x*b)%a==0){
            cout<<"YES\n";
            return;
        }
        x = (x*b)%a;
        i++;
        if(i==101) break;
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