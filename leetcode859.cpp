class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        int slen = unordered_set<char>(s.begin(), s.end()).size();
        if (s == goal && slen < goal.size()) return true;
        vector<int> idx;
                        
        for (int i = 0; i < s.size(); i++) {
          if (s[i] != goal[i]) idx.push_back(i);
          if (idx.size() > 2) return false;
        } 
        
        return idx.size() == 2 &&
               s[idx[0]] == goal[idx[1]] &&
               s[idx[1]] == goal[idx[0]]; 
    }
};