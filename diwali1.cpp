#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long int p,a,b,c,x,y;
    cin>>p>>a>>b>>c>>x>>y;
    long long int cost = min((x*a)+b,(y*a)+c);
    long long int items = p/cost; 
    cout<<items<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}