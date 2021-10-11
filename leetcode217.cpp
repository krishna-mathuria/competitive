class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> st;
        for(auto x:nums){
            if(st.find(x)!=st.end()) return true;
            st[x]++;
        }
        return false;
    }
};