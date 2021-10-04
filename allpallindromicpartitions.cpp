class Solution {
  public:
  bool isValid(string s){
      int n = s.length();
      for(int i=0;i<n/2;i++){
          if(s[i]!=s[n-1-i]){
              return false;
          }
      }
      return true;
  }
  void solve(string s,vector<string>& res,vector<vector<string>>& ans,int idx){
      if(idx==s.length()){
          ans.push_back(res);
          return;
      }
      string temp = "";
      for(int i=idx;i<s.length();i++){
          temp+=s[i];
          if(isValid(temp)){
              res.push_back(temp);
              solve(s,res,ans,i+1);
              res.pop_back();
          }
      }
  }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>> ans;
        vector<string> res;
        solve(S,res,ans,0);
        return ans;
    }
};