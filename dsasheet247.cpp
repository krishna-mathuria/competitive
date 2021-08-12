#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        n--;
        m--;
        int arr1[n];
        int arr2[m];
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        for(int i=0;i<m;i++){
            cin>>arr2[i];
        }
        sort(arr1,arr1+n,greater<int>());
        sort(arr2,arr2+m,greater<int>());
        int h=1,v=1;
        int i=0,j=0;
        int cost=0;
        while(i<n && j<m){
            if(arr1[i]>arr2[j]){
                cost +=arr1[i]*h;
                v++;
                i++;
            }
            else{
                cost+=arr2[j]*v;
                h++;
                j++;
            }
        }
        while(i<n){
            cost += arr1[i]*h;
            i++;
        }
        while(j<m){
            cost+=arr2[j]*v;
            j++;
        }
        cout<<cost<<endl;
    }
}