class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        for(auto x: num){
            while(ans.size() && ans.back() > x && k){
                ans.pop_back();
                k--;
            }
            if(ans.size() || x!='0')
                ans.push_back(x);
        }
        while(ans.size() && k--) ans.pop_back();
        return ans.size() ? ans : "0";
    }
};