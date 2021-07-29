#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,i=0,a[100005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<n/2;j++){
        int temp = a[j];
        a[j]=a[n-j-1];
        a[n-j-1]=temp;
    }
    for(int j=0;j<n;j++){
        cout<<a[j]<<" ";
    }
}