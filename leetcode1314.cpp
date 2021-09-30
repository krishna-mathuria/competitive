class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> dp(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>> dp2(mat.size(),vector<int>(mat[0].size(),0));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                dp[i][j] =  mat[i][j];
                if(j>0){
                   dp[i][j]+= dp[i][max(0,j-1)];
                }
                if(i>0){
                    dp[i][j]+=+dp[max(0,i-1)][j]; 
                }
                if(i>0 && j>0){
                    dp[i][j] -= dp[max(0,i-1)][max(j-1,0)];
                }
            }
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int temp,temp1;
                temp =j+k;
                if(j+k>=mat[0].size()){
                    temp = mat[0].size()-1;
                }
                temp1 =i+k;
                if(i+k>=mat.size()){
                    temp1 = mat.size()-1;
                }
                
                dp2[i][j] += dp[temp1][temp];
                
                if(i-k>0){

                    dp2[i][j] -=dp[i-k-1][temp];
                }
                if(j-k>0){

                    dp2[i][j] -= dp[temp1][j-k-1];
                }
                if(i-k>0 && j-k>0 ) {
                    dp2[i][j] += dp[i-k-1][j-k-1];
                }
                
            }
        }
        return dp2;
    }
};