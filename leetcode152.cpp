class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mn=1;
        int mx=1;
        int prod = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) swap(mx,mn);
            mx = max(nums[i],mx*nums[i]);
            mn = min(nums[i],mn*nums[i]);
            prod = max(prod,mx);
        }
        return prod;
    }
};