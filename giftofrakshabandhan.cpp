#include<bits/stdc++.h>
using namespace std;

vector<int> zFunction(string s) {
    int n=s.size(),left=0,right=0;
    vector<int> zval(n,0);
    zval.push_back(0);
    for(int i = 1; i < n; i++) {
        if(i>right){
            left=right=i;
            while(right<n && s[right]==s[right-left]){
                right++;
            }
            zval[i]=right-left;
            right--;
        }else{
            int k1 = i -left;
            if(zval[k1]<right-i+1){
                zval[i]=zval[k1];
            }else{
                left=i;
                while(right<n && s[right]==s[right-left]){
                    right++;
                }
                zval[i]=right-left;
                right--;
            }
        }
    }
    return zval;
    
}

int main(){
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    vector<int> zval = zFunction(s);
    int q,l;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>l;
        cout<<min(zval[l],l)<<"\n";
    }
    return 0;
}