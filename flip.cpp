vector<int> Solution::flip(string A) {
    vector<int> ans(2,0);
    vector<int> ans2;
    int n = A.size();
    int ar[n];
    int count=0;
    for(int i=0;i<n;i++){
        if(A[i]=='1') {
            ar[i]=-1;
            count++;
        }
        else ar[i]=1;
    }
    if(count==n) return ans2;
    int sum=0;
    int mx=0;
    int x=0;
    for(int i=0;i<n;i++){  
        if(sum+ar[i]<0){
            sum=0;
            x = i+1;
        }
        else sum +=ar[i];
        if(mx<sum) {
            mx=sum;
            ans[0]=x;
            ans[1] = i+1;
        }
    }
    ans[0]++;
    ans[1]++;
    return ans;
}