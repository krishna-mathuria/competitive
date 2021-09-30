class Solution {
public:
    int trap(vector<int>& arr) {
        int n =arr.size();
        int right[n],left[n];
        int mx=arr[0];
        for(int i=0;i<n;i++){
            mx = max(arr[i],mx);
            left[i]=mx;
        }
        mx = arr[n-1];
        for(int i=n-1;i>=0;i--){
            mx = max(arr[i],mx);
            right[i]=mx;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+= min(left[i],right[i]) - arr[i];
        }
        return ans;
    }
};