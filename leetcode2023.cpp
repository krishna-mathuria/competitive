class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        map<string,string> mp;
        int count=0;
        for(int i=0;i<nums.size();i++){
           for(int j=0;j<nums.size();j++){
              if(i!=j && (target==nums[i]+nums[j])) count++;
           }
        }
        return count;
    }
};