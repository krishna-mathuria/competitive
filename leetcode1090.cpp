class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<values.size();i++){
            pq.push({values[i],labels[i]});
        }
        map<int,int> mp;
        int ans=0;
        int num=0;
        while(num!=numWanted){
            auto x = pq.top();
            pq.pop();
            if(mp.find(x.second)!=mp.end() && mp[x.second]<useLimit){
                mp[x.second]++;
                ans+=x.first;
                num++;
            }
            else if(mp.find(x.second)==mp.end()) {
                mp[x.second]++;
                ans+=x.first;
                num++;
            }
            if(pq.empty()) break;
        }
        return ans;
    }
};