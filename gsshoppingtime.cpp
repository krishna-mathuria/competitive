#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int sum = 0, res = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum <= k)
        {
          res = i + 1;
        }
        if (mp.find(sum) == mp.end())
        {
        
          mp[sum] = i;
        }
        if (mp.find(sum - k) != mp.end())
        {
          if (res < (i - mp[sum - k]))
          {
            res = i - mp[sum - k];
          }
        }
    }
    cout<<res;
}  