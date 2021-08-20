long long int count(long long int n)
{                
	int opt[] = {3,5,10};
	long long sum = n;
	int size =3;
	long long dp[size+1][sum+1];
	for(int i=0;i<=size;i++){
	    dp[i][0]=1;
	}
	for(long long int i=1;i<=sum;i++){
	    dp[0][i]=0;
	}
	for(int i=1;i<=size;i++){
	    for(long long j=0;j<=sum;j++){
	        if(opt[i-1]<=j)
	            dp[i][j] = dp[i-1][j]+dp[i][j-opt[i-1]];
	        else
	            dp[i][j] = dp[i-1][j];
	    }
	}
	return dp[size][sum];
}