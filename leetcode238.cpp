class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1,zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
            }
            else{
                prod = prod*nums[i];
            }
        }
        vector<int> ans(nums.size(),0);
        if(zero>1)
            return ans;
        if(zero==0){
            for(int i=0;i<nums.size();i++){
                ans[i] = prod/nums[i];
            }
        }
        else{
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    ans[i] = prod;
                }
            }
        }
        return ans;
    }
};