class NumMatrix {
private:
        vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        dp = vector<vector<int>>(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                dp[i][j] =  matrix[i][j];
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
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        long long result = 0;
        result+= dp[row2][col2];
        if(row1>0)
        result -= dp[row1-1][col2];
        if(col1>0)
        result -= dp[row2][col1-1];
        if(row1>0 && col1>0)
        result+=dp[row1-1][col1-1];
        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */