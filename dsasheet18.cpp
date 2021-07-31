// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    struct Node {
        int value = 0;
    };
    int getPairsCount(int arr[], int n, int k) {
        // code here
        long long ans=0;
        unordered_map<int,Node> mp;
        for(int i=0;i<n;i++){
            if(arr[i]>k) continue;
            if(mp.find(k-arr[i])!=mp.end())
                ans+=mp[k-arr[i]].value;
            mp[arr[i]].value++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends