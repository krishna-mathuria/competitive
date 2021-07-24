#include<bits/stdc++.h>
using namespace std; 
#define md 1000000007
int main(){
    long long n,m,k,ans=1;
    cin>>n>>m>>k;
    if(k==1 || k>n){
        for(int i=1;i<=n;i++){
            ans = (ans*m)%md;
        }
    }
    else if(k==n){
        for(int i=1;i<=(n+1)/2;i++){
            ans = (ans*m)%md;
        }
    }
    else if(k%2==1){
        ans =(m*m)%md;
    }
    else if(k%2==0){
        ans=m%md;
    }
    cout<<ans;
}