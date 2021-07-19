#include<iostream>
#include<stdio.h>
#include<string>
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
    int k;
    while(cin>>k){
        string pat,txt;
        cin>>pat>>txt;
        int M = pat.size();
        int N =txt.size();
        int lps[M];
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
                printf("%d\n", i - j);
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
        cout<<"\n";
    }
    }
}