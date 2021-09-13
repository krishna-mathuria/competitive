class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0;
        int hi = nums.size();
        while(low<hi){
            int mid = (hi+low)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else hi = mid;
        }
        return -1;
    }
};