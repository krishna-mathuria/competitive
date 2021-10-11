class Solution {
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> arr(nums);
        for (int i = 0;i < arr.size();i++) {
            int x = rand()%(arr.size()-i);
            swap(arr[i+x], arr[i]);
        }
        return arr;
    }
};