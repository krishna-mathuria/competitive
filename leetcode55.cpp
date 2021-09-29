class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = nums[0];
        for(int i=1;i<nums.size();i++){
            if(mx<i) return false;
            mx= max(mx,i+nums[i]);
        }
        return true;
    }
};