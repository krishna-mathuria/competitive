class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> mp(60);
        int res=0;
        for (auto t : time) {
            res += mp[(60 - t % 60) % 60];
            mp[t % 60]++;
        }
        return res;
    }
};