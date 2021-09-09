class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> pq;
        for(int i=0;i<points.size();i++){
            int dist = 0;
            dist+= (points[i][0]*points[i][0]);
            dist+= (points[i][1]*points[i][1]);
            pq.push({dist,points[i]});
        }
        vector<vector<int>> ans;
        while(ans.size()!=k){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};