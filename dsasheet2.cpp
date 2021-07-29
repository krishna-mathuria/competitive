#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,mx=INT_MIN,mn=INT_MAX,a[100005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>mx) mx = a[i];
        if(a[i]<mn) mn=a[i];
    }
    cout<<"MAX "<<mx<<"\nMIN "<<mn;
}