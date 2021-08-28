#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    int t,n,k,i;
    cin>>t;
    while(t--){ 
        cin>>n; 
        set<ll> st; 
        for(i=1; i<n+1; i++){ 
            int k;
            cin>>k;
            st.insert(k-i);
        } 
        
        cout<<n-st.size()+1<<"\n"; 
    } 
}