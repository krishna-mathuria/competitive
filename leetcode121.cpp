class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;
        int mx=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-buy<0) {
                buy = prices[i];
            }
            profit = prices[i]-buy;
            mx = max(mx,profit);
        }
        return mx;
    }
};