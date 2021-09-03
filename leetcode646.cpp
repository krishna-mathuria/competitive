class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),cmp);
        vector<int> v;
        int n = p.size();
        v.push_back(p[0][1]);
        for(int i=1;i<n;i++){
            if(p[i][0] > v.back()){
                v.push_back(p[i][1]);
            }
            else{
                // int temp = lower_bound(v.begin(),v.end(),p[i][1]) -v.begin(); 
                // v[temp] = p[i][1];
            }
        }
        return v.size();
    }
};