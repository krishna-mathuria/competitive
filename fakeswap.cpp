#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s,p;
        cin>>s>>p;
        if(s==p){
            cout<<"YES\n";
            continue;
        }
        int a=0,b=0;
        for(int i=0;i<n;i++){            
            if(p[i]=='0') a++;
            else b++;
        }
        if(a && b){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}