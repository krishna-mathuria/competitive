#include<bits/stdc++.h>
using namespace std;
 
bool isValid(int arr[],int n,int c,int val){
    int cows_placed =1;
    int idx=0; 
    for(int i=1;i<n;i++){
        if(arr[i]-arr[idx]>=val){
            cows_placed++;
            idx=i;
        }
    }
    if(cows_placed<c){
        return false;
    }
    else return true;
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        int arr[n];
        int mx,mn;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i==0){
                mn=arr[i];
                mx = arr[i];
            }
            if(mn>arr[i]) mn = arr[i];
            if(mx<arr[i]) mx = arr[i];
        }
        sort(arr,arr+n);
        int ans=-1;
        while(mn<=mx){
            int mid = mn + (mx-mn)/2;
            if(isValid(arr,n,c,mid)){
                ans = mid;
                mn = mid+1;
            }
            else{
                mx = mid-1;
            }
        }
        cout<<ans<<"\n";
    }
} 