class Solution {
public:
    int getMaxLen(vector<int>& A) {
        int ans = 0, pos = 0, neg = 0;
        for (int &e : A) {
            if (e > 0) {
                pos = pos > 0 ? pos + 1 : 1;
                neg = neg > 0 ? neg + 1 : 0;
            } else if (e < 0) {
                int p = pos, n = neg;
                pos = n > 0 ? n + 1 : 0;
                neg = p > 0 ? p + 1 : 1;
            } else {
                pos = neg = 0;
            }
            ans = max(ans, pos);
        }
        return ans;
    }
};