class Solution {
public:
    int dp[100001][2][2];
    int solution(int ind, int cur_state, int transactions, vector<int>&prices){
        if(ind>=prices.size() || transactions==2)
            return 0;
        if(dp[ind][cur_state][transactions]!=-1)
            return dp[ind][cur_state][transactions];
        int profit=0;
        if(cur_state==0){
            int buy=solution(ind+1, 1, transactions, prices)-prices[ind];
            int notBuy=solution(ind+1, 0, transactions, prices);
            profit=max(buy, notBuy);
        }else{
            int sell=solution(ind+1, 0, transactions+1, prices)+prices[ind];
            int notSell=solution(ind+1, 1, transactions, prices);
            profit=max(sell, notSell);
        }
        return dp[ind][cur_state][transactions]=profit;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        memset(dp, -1, sizeof(dp));
        return solution(0, 0, 0, prices);
    }
};