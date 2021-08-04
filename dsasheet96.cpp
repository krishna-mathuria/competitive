#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int arr2[n+1];
        memset(arr2,0,sizeof(arr2));
         int *ans = new int(2);
        for(int i=0;i<n;i++){
            arr2[arr[i]]++;
            if(arr2[arr[i]]==2){
                ans[0] = arr[i];
            }
        }
        for (int i=1;i<=n;i++){
            if(arr2[i]==0){
                ans[1]=i;
                break;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} 