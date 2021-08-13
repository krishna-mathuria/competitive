class Solution{
    public:
    void dfs(vector<vector<int>> &m, int n,vector<string> &res,int i,int j,string s){
        
        if(i==n-1 && j==n-1){
            res.push_back(s);
            return;
        }
        else{
            if(i!=n-1){
                if(m[i+1][j]==1){
                    string sd=s;
                    sd+='D';
                    m[i][j]=0;
                    dfs(m,n,res,i+1,j,sd);
                    m[i][j]=1;
                }
            }
            if(j!=n-1){
                if(m[i][j+1]==1){
                    string sr=s;
                    sr+='R';
                    m[i][j]=0;
                    dfs(m,n,res,i,j+1,sr);
                    m[i][j]=1;
                }
            }
            if(i>0){
                if(m[i-1][j]==1){
                    string sl=s;
                    sl+='U';
                    m[i][j]=0;
                    dfs(m,n,res,i-1,j,sl);
                    m[i][j]=1;
                }
            }
            if(j>0){
                if(m[i][j-1]==1){
                    string su=s;
                    su+='L';
                    m[i][j]=0;
                    dfs(m,n,res,i,j-1,su);
                    m[i][j]=1;
                }
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[n-1][n-1]==0 || m[0][0]==0) return {};
        vector<string> res;
        string s="";
        dfs(m,n,res,0,0,s);
        sort(res.begin(),res.end());
        return res;
    }
};