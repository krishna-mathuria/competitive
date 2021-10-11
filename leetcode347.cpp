class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i : nums) ++mp[i];
        for(auto & i : mp) {
            pq.push(i.second);
            while(pq.size() > k) pq.pop();
        }
        vector<int> res;
        for(auto & i : mp) {
            if(i.second >= pq.top()) res.push_back(i.first);
        }
        return res;
    }
};