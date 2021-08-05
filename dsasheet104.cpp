#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        ll sum = 0;
    	unordered_map<int, int>mp;
    	mp[0] = 1;
    	int temp = 0;
    	for (int i = 0; i < n; i++) {
    		temp += arr[i];
    		if (mp.find(temp) != mp.end()) {
    			sum += mp[temp];
    			mp[temp]++;
    		}
    		else {
    			mp[temp]++;
    		}
    	}
    	return sum;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
} 