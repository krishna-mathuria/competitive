#include<bits/stdc++.h>
using namespace std;
 
 
void solve(){
    int n;
    cin>>n;
    long long arr[n],maxm2=0,sum=0,fl=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum<0){
        cout<<"NO\n";
        return;
    }
    for(int i=0;i<n;i++){
        maxm2+=arr[i];
        if(sum==maxm2 && !fl && i!=n-1){
            cout<<"NO\n";
            return;
        }
        else if(sum==maxm2 && !fl && i==n-1){
            cout<<"YES\n";
            return;
        }
        if(sum<=maxm2){
            cout<<"NO\n";
            return;
        }
        if(maxm2<=0){
            maxm2=0;
            fl=1;
        }
    }
    cout<<"YES\n";
} 
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}