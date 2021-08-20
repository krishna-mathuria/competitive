class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        int dp[W+1];
        for(int i=0;i<=W;i++){
            dp[i]=1000000000;
        }
        dp[0]=0;
        for(int i=1;i<W+1;i++){
            for(int j=0;j<N;j++){
                if(cost[j]!=-1 && j+1<=i){
                    dp[i] = min(dp[i],dp[i-(j+1)] + cost[j]);
                }
            }
        }
        return dp[W]==1000000000? -1 : dp[W];
	} 
};