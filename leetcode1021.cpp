class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans;
        for (char c : s) {
            if (c == '(') {
                if (count++) {
                    ans += '(';
                }
            } else {
                if (--count) {
                    ans += ')';
                }
            }
        }
        return ans;
    }
};