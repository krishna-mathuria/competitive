class Solution{
    public:
    int Maximize(int a[],int n)
    {
        // Complete the function
        sort(a,a+n);
        long long mod = 1000000007;
        long long ans=0;
        for(int i=0;i<n;i++){
            ans = (ans + ((a[i]%mod)*i))%mod;
        }
        return ans;
    }
};