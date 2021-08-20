class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int res[N+1][N+1];
        memset(res,0,sizeof(res));
        for(int i=N-1;i>=0;i--){
            for(int j=0;j<N;j++){
                res[i][j] = Matrix[i][j] + max(res[i+1][j],max(res[i+1][j+1],res[i+1][j-1]));  
            }
        }
    int ans = res[0][0];
    for (int i=1; i<N; i++)
        ans = max(ans, res[0][i]);
    return ans;
    }
};