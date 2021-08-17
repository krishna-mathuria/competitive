class Solution 
{
    public:
    int dx[8] = {2,2,-2,-2,1,1,-1,-1};
    int dy[8] = {1,-1,1,-1,2,-2,2,-2};
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    queue<pair<int,int>> q;
	    int count =0;
	    int a[1001][1001];
	    memset(a,0,sizeof(a));
	    q.push({KnightPos[0],KnightPos[1]});
	    if(KnightPos[0]==TargetPos[0] && KnightPos[1]==TargetPos[1]) return 0;

	    while(!q.empty()){

	        int x = q.front().first;
	        int y = q.front().second;
	        q.pop();
	        for(int i=0;i<8;i++){
	            if(x+dx[i]==TargetPos[0] && y+dy[i]==TargetPos[1]) return a[x][y]+1;
	            if(x+dx[i]>0 && x+dx[i]<=n && y+dy[i]>0 && y+dy[i]<=n && a[x+dx[i]][y+dy[i]]==0){
	                a[x+dx[i]][y+dy[i]] = a[x][y]+1;
	                q.push({x+dx[i],y+dy[i]});
	            }
	        }
	    }
	    return a[TargetPos[0]][TargetPos[1]];
	}
};