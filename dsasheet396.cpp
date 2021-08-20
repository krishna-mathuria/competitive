class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int ans = INT_MIN;
	    vector<int> dp(arr,arr+n);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[i]>arr[j] and dp[i]<dp[j]+arr[i])
	                dp[i]=dp[j]+arr[i];
	        }
	        ans = max(dp[i],ans);
	    }
	    return ans;
	}  
};