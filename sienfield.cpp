#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main(){
    string s;
    int i=1;
    while(cin>>s){
        stack<char> st;
        int n = s.size();
        int count=0;
        if(s[0]=='-'){
            break;
        }
        else{
            for(int i=0;i<n;++i){
                if(s[i]=='{') 
                    st.push(s[i]);
                else if(!st.empty() && st.top()=='{'){
                    st.pop();
                    continue;
                }
                else{
                    count++;
                    st.push('{');
                }
            }
            count += st.size() / 2;
           cout<<i++<<". "<<count<<"\n";
        }
    }
    return 0;
}