#include <bits/stdc++.h>
using namespace std;


 void computeLPSArray(int* K,int k,int* lps){
    lps[0]=0;
    int i=1,len=0;
    while(i<k){
        if(K[i]==K[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

void KMP(int* N, int* K,int n, int k,int* lps){
    int i=0,j=0,counter=0;
    while(i<n){
        if(N[i]==K[j]){
            i++;
            j++;
        }
        if(j==k){
            counter++;
            j=lps[j-1];
        }
        else if(i<n && N[i]!=K[j]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    cout<<counter<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int N[n],K[k],diff[n],lps[k];
        for(int i=0;i<n;i++){
            cin>>N[i];
            if(i==0){
                diff[i]=N[i];
            }else{
                diff[i]=N[i]-N[i-1];
            }
        }
        for(int i=0;i<k;i++){
            cin>>K[i];
        }
        computeLPSArray(K,k,lps);
        KMP(diff,K,n,k,lps);
    }
    return 0;
}
