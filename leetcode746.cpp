class Solution {
public:
    int dp[1004];
    int f(int i,vector<int>& cost){
        if(i==cost.size()+1) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(f(i+1,cost),f(i+2,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        dp[cost.size()]=0;
        return min(f(0,cost),f(1,cost));
    }
};