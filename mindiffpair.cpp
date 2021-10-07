class Solution{
	public:
   	int  minimum_difference(vector<int>nums){
   	    // Code here
   	    sort(nums.begin(),nums.end());
   	    int mn=INT_MAX;
   	    for(int i=0;i<nums.size()-1;i++){
   	        mn = min(mn,nums[i+1]-nums[i]);
   	    }
   	    return mn;
   	}    
};
