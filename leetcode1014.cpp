class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int result = 0;
        int mx = values[0]+0;

        for (int i=1; i<values.size(); ++i)
        {
            mx = max(mx, values[i-1]+i-1);  
            result = max(result, values[i]-i+mx);         
        }
        return result;
    }
};