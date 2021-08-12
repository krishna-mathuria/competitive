class Solution
{
    public:
    int solv(int gp[],int cp[],int wt[],int i,int &min_dia){
    if(gp[i] == 0)
        return i;
    min_dia = min(min_dia,min(wt[gp[i]],wt[i]));
    return solv(gp,cp,wt,gp[i],min_dia);
}

    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        int cp[n+1] = {0}; 
        int gp[n+1] = {0}; 
        int wt[n+1]; 
        memset(wt,10000,sizeof(wt));
        vector<vector<int>> ans;
        for(int i=0;i<p;i++){
            gp[a[i]] = b[i];
            cp[b[i]] = a[i];
            wt[a[i]] = min(wt[a[i]],d[i]); 
            wt[b[i]] = min(wt[b[i]],d[i]); 
        }
    
        
        for(int i=1;i<=n;i++){
            if(gp[i]!=0 and cp[i] == 0){
                vector<int> vec;
                int min_dia=INT_MAX;
                vec.push_back(i);  
                vec.push_back(solv(gp,cp,wt,i,min_dia)); 
                vec.push_back(min_dia);   
                ans.push_back(vec);
            }
        }
    
        return ans;
    }
};