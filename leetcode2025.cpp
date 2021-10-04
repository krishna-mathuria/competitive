class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<long long> pref(n), suff(n);

        pref[0] = nums[0]; suff[n-1] = nums[n-1];
        for(int i=1; i<n; ++i) { 
            pref[i]     = pref[i-1] + nums[i]; 
            suff[n-1-i] = suff[n-i] + nums[n-1-i];
        } 

        long long ans = 0;
        unordered_map<long long,long long> left, right;
        
        for(int i=0;i<n-1; ++i) right[pref[i] - suff[i+1]]++;
        
        
        if(right.count(0)) ans = right[0];
        for(int i=0; i<n; ++i){
            long long curr = 0, diff = k-nums[i];
            if(left.count(diff)) curr+=left[diff];
            if(right.count(-diff)) curr+=right[-diff];
            ans = max(ans, curr);
            if(i<n-1){
                long long dd = pref[i]-suff[i+1]; 
                left[dd]++; right[dd]--;
                if(right[dd] == 0) right.erase(dd);

            }
        }
        return ans;
        
    }
};