#define LL long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        LL ans = 0;
        vector<map<LL, int>> mp(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                LL x = (LL)A[i] - (LL)A[j];
                int sum = 0;
                if (mp[j].find(x) != mp[j].end()) {
                    sum = mp[j][x];
                }
                mp[i][x] += sum + 1;
                ans += sum;
            }
        }

        return (int)ans;
    }
};