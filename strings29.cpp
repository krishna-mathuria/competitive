#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        int mx1=0,mx2=0;
        string ans1="",ans2="";
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mx2<mp[arr[i]] && mx1>mp[arr[i]]){
                ans2= arr[i];
                mx2=mp[arr[i]];
            }
            else if(mx1<mp[arr[i]]){
                mx2 = mx1;
                ans2 = ans1;
                mx1=mp[arr[i]];
                ans1 = arr[i];
            }
        }
        return ans2;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}