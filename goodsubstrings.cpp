#include<bits/stdc++.h>
using namespace std;

int main(){
    set<string> sets;
    set<string >::iterator itr;
    string s,vals;
    cin>>s>>vals;
    int k,badkeys=0;
    cin>>k;
    for(int i=0;i<s.size();i++){
        string key;
        for(int j=i;j<s.size();j++){
            if(vals[s[j]-'a']=='1'){
                key+=s[j];
                sets.insert(key);
            }
            else{
                if(k<=badkeys){
                    break;
                }
                else{
                    key+=s[j];
                    sets.insert(key);
                    badkeys++;
                }
            }
        }
        badkeys=0;
        
    }
    if(!sets.empty())
        cout<<sets.size()<<"\n";
    else cout<<"0\n";
}

