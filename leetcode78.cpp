class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp);
         for (int num : nums) {
            int n = ans.size();
            for (int i = 0; i < n; i++) {
                ans.push_back(ans[i]); 
                ans.back().push_back(num);
            }
        }
        return ans;
        
    }
};