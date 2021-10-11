class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x = INT_MAX, y = INT_MAX;
        for (int z : nums) {
            if (z <= x) {
                x = z;           
            } else if (z <= y) { 
                y = z;           
            } else {             
                return true;     
            }
        }
        return false;
    }
};