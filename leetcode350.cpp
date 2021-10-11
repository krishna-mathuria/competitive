class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
         sort(nums2.begin(),nums2.end());
    vector<int> v(nums1.size() + nums2.size());
    vector<int>::iterator it, st;
  
    it = set_intersection(nums1.begin(),
                          nums1.end(),
                          nums2.begin(),
                          nums2.end(),
                          v.begin());
    vector<int> ans;
    for (st = v.begin(); st != it; ++st)
        ans.push_back(*st);
    return ans;
    }
};