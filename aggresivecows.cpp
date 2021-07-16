#include<bits/stdc++.h>
using namespace std;

int check(int mid,int arr[],int n,int c){
    int cows_placed=1;
    int pos=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-pos>=mid){
            pos=arr[i];
            cows_placed++;
        }
        if(cows_placed==c){
            return 1;
        }
    }
    return 0;
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int low,high,minm,mid;
        low=arr[0];
        high=arr[n-1];
        minm=-1;
        while(low<=high){
            mid=low+(high-low)/2;
            
            if(check(mid,arr,n,c)){
                minm=mid;
                low=mid+1;
            }else{
                high = mid-1;
            }
            
        }
        cout<<endl<<minm;
    }
    
    return 0;
}