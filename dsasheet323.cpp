class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        long long ans1 = 0;
        
        if(n==1)
            return ans1;
        
        priority_queue<long long, vector<long long>, greater<long long>> ans;
        
        for(long long i=0; i<n; i++) 
            ans.push(arr[i]); 
        while(ans.size()>1){
            long long x = ans.top();
            ans.pop();
            long long y = ans.top();
            ans.pop();
            ans1 += (x+y);
            ans.push(x+y);
        }
        return ans1;
    }
};