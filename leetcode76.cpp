class Solution {
public:
    string minWindow(string s, string t) {
        vector toBeFound(128, 0);
        for (auto c : t) toBeFound[c]++;
        int counter = t.size();
        int start = 0;
        int end = 0;
        int minLen = INT_MAX;
        int head = 0;
        while (end < s.size()) {
            if (toBeFound[s[end]] > 0) {
                counter--;
            }
            toBeFound[s[end]]--;
            end++;

            while (counter == 0) { 
                if (end - start < minLen) {
                    minLen = end - start;
                    head = start;
                }

                toBeFound[s[start]]++;
                if (toBeFound[s[start]] >0) {
                    counter++;
                }
                start++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(head, minLen);
    }
};