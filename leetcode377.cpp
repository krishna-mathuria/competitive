class Solution {
public:
    int dp[1001];
   int getSum(vector<int> &nums,int target)
    {
        if(target==0)
            return 1;
       
        if(target<0)
            return 0;
       
        if(dp[target]!=-1)
            return dp[target];
       
        int count=0;
        for(int i=0;i<nums.size();i++)
            count+=getSum(nums,target-nums[i]);

        return dp[target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int res= getSum(nums,target);
        return res;
    }
};