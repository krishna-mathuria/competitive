#include<bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat, int M, int* lps)
{
    int len = 0;
  
    lps[0] = 0; // lps[0] is always 0
  
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if (len != 0) {
                len = lps[len - 1];

            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
  
int main(){
    int t;
    cin>>t;
    while(t--){
        string pat,txt;
        cin>>txt>>pat;
        int M = pat.size();
        int N =txt.size();
        int lps[M],count=0;
        vector<int> ans;
        bool match = false;
        computeLPSArray(pat, M, lps);
  
        int i = 0; // index for txt[]
        int j = 0; // index for pat[]
        while (i < N) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }
  
            if (j == M) {
                 match=true;
                count++;
                ans.push_back(i-j+1);
                j = lps[j - 1];
            }
  
        else if (i < N && pat[j] != txt[i]) {

            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
   if(!match){
        cout<<"Not Found\n";
    }else{
        cout<<count<<"\n";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    }
    
}