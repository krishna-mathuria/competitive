#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    bool arr[26]={0};
    string s;
    cin>>s;
    int ans=0,occ=0;
    for(int i=0;i<s.size();i++){
        if(arr[s[i]-'A']==0){
            occ++; 
            arr[s[i]-'A']++;
        }
        else if(arr[s[i]-'A']==1){
            if(n<occ){
                ans++;
                occ--;
            }
            else{
                occ--;
            }
        }
    }cout<<ans<<endl;
    }
    return 0;
    
}