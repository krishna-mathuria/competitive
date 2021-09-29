class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odd,even;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        int j=0;
        for(int i=0;i<nums.size();i+=2){
            nums[i] = even[j];
            nums[i+1] = odd[j];
            j++;
        }
        return nums;
    }
};