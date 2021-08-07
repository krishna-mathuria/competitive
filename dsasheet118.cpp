#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int count(int n){
            if(n < 5) return 0;
            return n/5 + count(n/5);
        }
        int findNum(int n){
            int l = 0;
            int r = 50000;
            int ans = 50000;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(count(mid) >= n){
                    ans = mid;
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            return ans;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}