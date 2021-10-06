class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> helper;
        for(auto x: strs){
            string temp = x;
            sort(temp.begin(),temp.end());
            helper[temp].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto y: helper ){
            ans.push_back(y.second);
        }
        return ans;
    }
};