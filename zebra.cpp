#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        char curr = s[0];
        int i;
        for(i=0;i<n;i++){
            if(s[i]!=curr){
                if(k==1) break;
                k--;
                curr = s[i];
                if(k==1) break;
            }
        }
        bool fl=0;
        for(int j=n-1;j>=i;j--){
            if(s[j]!=curr){
                cout<<j+1<<"\n";
                fl=1;
                break;
            }
        }
        if(!fl)
        cout<<-1<<"\n";
    }
    return 0;
}