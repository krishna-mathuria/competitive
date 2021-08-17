#define pii pair<int,pair<int,int>>
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          priority_queue<pii,vector<pii>,greater<pii>> pq;
          int mx = INT_MIN;
          int mn = INT_MAX;
          for(int i=0;i<k;i++){
              pq.push({arr[i][0],{i,0}});
              mx = max(mx,arr[i][0]);
          }
          int range = INT_MAX;
          int start = 0;
          int end =0;
          while(true){
              pii temp = pq.top();
              pq.pop();
              mn = temp.first;
              if(mx-mn<range){
                  start = mn;
                  end = mx;
                  range = mx-mn;
              }
              if(temp.second.second+1==n) break;
              pq.push({arr[temp.second.first][temp.second.second+1],{temp.second.first,temp.second.second+1}});
              if(arr[temp.second.first][temp.second.second+1]>mx)
                mx = arr[temp.second.first][temp.second.second+1];
          }
          pair<int,int> ans = {start,end};
          return ans;
    }
};