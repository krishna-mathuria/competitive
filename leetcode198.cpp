class Solution {
public:
    int solve(vector<int>& nums,vector<int>& dp,long long i){
        if(i>=nums.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int a = solve(nums,dp,i+1);
        int b = solve(nums,dp,i+2)+nums[i];
        dp[i] = max(a,b);
        return dp[i];
        
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
       return solve(nums,dp,0);
    }
};