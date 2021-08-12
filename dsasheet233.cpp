#include<bits/stdc++.h>
using namespace std;

int maxProductSubset(int a[],int n){
    int c0=0,cn=0;
    int mxn = INT_MIN;
    int prod = 1;
    for(int i=0;i<n;i++){
        if(a[i]<0) {
            cn++;
            mxn = max(mxn,a[i]);
        }
        else if(a[i]==0) {
            c0++;
            continue;
        }
        prod *= a[i];
    }
    if(c0==n) return 0;
    if(cn%2==1){
        if (cn == 1 && c0 > 0 && c0 + cn == n)
            return 0;
        return prod/mxn;
    }
    return prod;
}


int main()
{
    int a[] = {  -1, -1, -2, 4, 3  };
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n);
    return 0;
}