#include<bits/stdc++.h>
using namespace std;
 
bool isValid(int arr[],int n,int wood,int h){
    int acq=0;
    for(int i=0;i<n;i++){
        if(arr[i]>h) acq +=arr[i]-h;
        if(acq>=wood){
            return true;
        }
    }
    return false;
}
 
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n],end = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(end<arr[i]) end = arr[i];
    }
    int start=0;
    int res =-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(isValid(arr,n,m,mid)){
            res = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    cout<<res;
}