class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if(n == 1 || nums[0] == 0){
            return 0;
        }
        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            if(!size){
                break;
            }
            while(size--){
                int x = q.front();
                q.pop();
                
                if(x == n - 1){
                    return level;
                }
                
                for(int jump = 1; jump <= nums[x]; jump++){
                    if((x + jump) < n && !visited[x + jump]){
                        q.push(x + jump);
                        visited[x + jump] = true;
                    }
                }
            }
            level++;
        }
        
        return level;
    }
};