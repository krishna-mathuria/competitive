#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string t;
        t=s;
        s+='$';
        reverse(t.begin(),t.end());
        s+=t;
        vector<int> lps(s.length());
         int len = 0;
        lps[0] = 0; 
        int i = 1;
        while (i < s.length())
        {
            if (s[i] == s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else{
                 if (len != 0)
                {
                    len = lps[len-1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        cout<<t.length()-lps.back();
    }
    return 0;
}