class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> dp(A.size());
        int res = 0;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                dp[i] = dp[i-1] + 1;
                res += dp[i];
            }
        }
        return res;
    }
};