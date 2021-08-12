class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    int mn=INT_MAX;
    for(int i=0;i<=n-m;i++){
        int diff = a[m+i-1] - a[i];
        if(diff<mn) mn = diff;
    }
    return mn;
    }   
};