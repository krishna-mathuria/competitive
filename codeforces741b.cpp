#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(x==y){
            cout<<0<<endl;
            continue;
        }
        else if((y/2)+1>=x) {
            cout<<y%((y/2)+1)<<endl;
            continue;
        }
        else{
            cout<<y%x<<"\n";
            continue;
        }
    }
}