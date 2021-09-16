#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int k=1;k<=t;k++){
        int n;
        cin>>n;
        string str;
        long long sum=0;
        cin>>str;
        stack<int> s;
        int res[n];
        for (int i = n - 1; i >= 0; i--) {

            res[i] = s.empty() ? INT_MAX : s.top();
            if(str[i]=='1')
                s.push(i);
        }
        stack<int> s2;
        int res2[n];
        for (int i = 0; i < n; i++) {
 
            res2[i] = s2.empty() ? INT_MAX : s2.top();
            if(str[i]=='1')
                s2.push(i);
        }
        
        
        for(int i=0;i<n;i++){
            if(str[i]=='0'){
                sum+=min(abs(res[i]-i),abs(res2[i]-i));
            }
        }
        cout<<"Case #"<<k<<": "<<sum<<endl;
    }
}