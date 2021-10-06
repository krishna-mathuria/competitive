class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        int start = 0;
        int end = nums.size()-1;
        int begin =-1;
        int last =-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]==target){
                begin = mid;
                end = mid-1;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
        }
        start = 0;
        end = nums.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]==target){
                last=mid;
                start = mid+1;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
        }
        return {begin,last};
    }
};