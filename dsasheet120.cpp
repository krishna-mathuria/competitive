#include<bits/stdc++.h>
using namespace std;

bool isValid(int cook[],int n,int p,int mid){
    int cnt = 0;
    for(int i=0;i<n;i++){
        int c = 0;
        int time = mid;
        int perpratas = cook[i]; 
        while(time > 0){
            time = time - perpratas;
            if( time >= 0){
                c += 1;
                perpratas  += cook[i];
            }
        }
        cnt += c;
        if(cnt >= p)
            return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,p;
        cin>>p>>n;
        int arr[n];
        int mx = 0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]>mx) mx =arr[i];
        }
        int low = 0;
        int high = 10000007;
        int ans=-1;
        while(low<=high){
            int mid = (high+low)/2;
            if(isValid(arr,n,p,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        cout<<ans<<"\n";
    }
}