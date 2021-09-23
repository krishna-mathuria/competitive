long long  numberOfPaths(int m, int n)
{
    long long t[m+1][n+1]={{0}};
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == 1)
                t[i][j] = 1;
            else if(j == 1)
                t[i][j] = 1;
            else
                t[i][j] = t[i - 1][j] + t[i][j - 1];
        }
    }
    return t[m][n];
}