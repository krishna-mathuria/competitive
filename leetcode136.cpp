class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()) mp.erase(nums[i]);
            else{
                mp[nums[i]]++;
            }
        }
        for(auto x : mp){
            return x.first;
        }
        return mp.size();
    }
};