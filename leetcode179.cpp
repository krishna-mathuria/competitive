class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(auto x:nums){
            ans.push_back(to_string(x));
        }
        string s="";
        sort(ans.begin(),ans.end(), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        for(auto y:ans){
            s+=y;
        }
        while(s[0]=='0' && s.length()>1)
            s.erase(0,1);
        return s;
    }
};