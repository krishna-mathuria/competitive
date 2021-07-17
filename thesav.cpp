#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,flag=0;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s[0]==0){
            cout<<"NO\n";
            continue;
        }
        for(int i=2;i<n;i++){
            if(s[i]==0){
                if(s[i-1] == "*" || s[i-2]=="*"){
                    continue;
                }
                else{
                    cout<<"NO\n";
                    flag=1;
                    break;
                }
            }
        }
        if(!flag){
            cout<<"YES\n";
        }
        
    }
    return 0;
}
