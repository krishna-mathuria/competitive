#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &A, int k) {
        // Your code goes here
        sort(A.begin(),A.end());
        int n = A.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i+1; j < n - 2; j++)
            {

                int l = j + 1;
                int r = n-1;

                while (l < r)
                {
                    if( A[i] + A[j] + A[l] + A[r] == k)
                    {
                        ans.push_back({A[i],A[j],A[l],A[r]});
                        l++; r--;
                    }
                    else if (A[i] + A[j] + A[l] + A[r] < k)
                        l++;
                    else 
                        r--;
                } 
            } 
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
} 