class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        long long int sum=0,mn = INT_MAX;
        for(int i=0;i<n;i++){
            if(a[i]<0) {
                if(k>0){
                    a[i]=-a[i];
                    k--;
                }
                sum+=a[i];
            }
            else{
                sum+=a[i];
            }
            mn = min(mn,a[i]);
        }
        return k%2==0 ? sum : sum-2*mn;
    }
};
