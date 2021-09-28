#include<bits/stdc++.h>
using namespace std;

void solve(){
    string x;
    cin>>x;
    bool fl =1;
    int res=0;
    for(auto c:x){
        if(c=='0' && fl){
            res++;
            fl = 0;
        }
        else if(c=='1' && !fl){
            res++;
            fl=1;
        }
    }
    cout<<res<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}