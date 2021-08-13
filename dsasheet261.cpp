class Solution{
public:
    bool subsetsum(int arr[],int N,int sum){
        bool t[N+1][sum+1];
        for(int i=0;i<=N;i++)
            t[i][0]=true;
    
        for(int i=1;i<=sum;i++)
            t[0][i]=false;

        for(int i=1;i<=N;i++){
            for(int j=1;j<=sum;j++){        
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[N][sum];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return 0;
        else 
            sum = sum/2;
        return subsetsum(arr,N,sum);
    }
};