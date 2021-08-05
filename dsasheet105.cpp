#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        long long int pr = 1;
        long long int pr2 = 1;
        int zeroes = 0;
        for(int i=0;i<n;i++){
            pr = pr* nums[i];
            if(nums[i]==0) zeroes++;
            else pr2 = pr2 * nums[i];
        }
        vector<long long int> ans;
        for(int i=0;i<n;i++){
            if(zeroes>1) ans.push_back(0);
            else if(nums[i]!=0)
                ans.push_back(pr/nums[i]);
            else ans.push_back(pr2);
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends