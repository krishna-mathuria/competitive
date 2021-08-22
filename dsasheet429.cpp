class Solution {
public:
    int dp[501];
    int suffix[501];
    int getans(int node, int k,vector<int>&nums)
    {   
        if(node>=nums.size())
         return 0;
         if(node!=0){
            if(suffix[node]+(nums.size()-node-1)<=k)
            {   
               return dp[node]=0;
            }
         }
         else
         {
             if(suffix[node]+(nums.size()-1)<=k)
             return dp[node]=0;
         }
        if(dp[node]!=-1) return dp[node];
        int x=100000000;
        int i=node;
        int sum=0;
         int y;
        while(i<nums.size()&&nums[i]+sum<=k)
        {
             sum+=nums[i];
              y=getans(i+1,k,nums);
             x=min(x,((k-sum)*(k-sum))+y);
             i++;
             sum++;
        }
     
        return dp[node]=x;
    }
   int solveWordWrap(vector<int>nums, int k) 
    { 
         for(int i=nums.size()-1;i>=0;i--)
         {
             if(i==nums.size()-1)
              suffix[i]=nums[i];
              else
              suffix[i]=suffix[i+1]+nums[i];
         }
        memset(dp,-1,sizeof(dp));
         getans(0,k,nums);
        return dp[0];
    } 
};