class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if(m*n!=original.size()) return {};
        int h=0;
        for(int i=0;i<m;i++){
            vector<int> res;
            for(int i=0;i<n;i++){
                res.push_back(original[h]);
                h++;
            }
            ans.push_back(res);
        }
        return ans;
    }
};