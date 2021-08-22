class Solution 
{
  public:
    int kadane(int v[],int n)
    {
        int maxSoFar=v[0],currMax=v[0];
        for(int i=1;i<n;i++)
        {
            currMax=max(currMax+v[i],v[i]);
            maxSoFar=max(maxSoFar,currMax);
        }
        return maxSoFar;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) 
    {
        int ans=INT_MIN,aux[R][C];
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                aux[i][j]=(i==0?M[i][j]:M[i][j]+aux[i-1][j]);
            }
        }
        int v[C];
        for(int i=0;i<R;i++)
        {
            for(int j=i;j<R;j++)
            {
                for(int k=0;k<C;k++)
                {
                    v[k]=aux[j][k]-(i>0?aux[i-1][k]:0);
                }
                ans=max(ans,kadane(v,C));
            }
        }
        return ans;
    }
};