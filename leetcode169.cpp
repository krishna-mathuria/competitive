class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int mx = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==mx) count++;
            else count--;
            if(count==0){
                mx = nums[i];
                count =1;
            }
        }
        return mx;
    }
};