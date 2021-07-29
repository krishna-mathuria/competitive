class Solution {
public:
    int getMaximumGenerated(int n) {
        int arr[n+2],mx=0;
        arr[0]=0;
        arr[1]=1;
        for(int i=1;i<=n/2;i++){
            arr[2*i]=arr[i];
            arr[(2*i)+1]=arr[i]+arr[i+1];
        }
        for(int i=0;i<=n;i++){
            if(mx<arr[i]) mx=arr[i];
        }
        return mx;
    }
};