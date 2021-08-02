class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        cout<<r<<" "<<c;
    
        int row=-1;
        for(int i=0;i<r;i++){
            if(matrix[i][c-1]>target){
                row=i;
                break;
            }
            if(matrix[i][c-1]==target) return true;
        }
        if(row==-1) return false;
        for(int i=0;i<c;i++){
            if(matrix[row][i]==target) {
                return true;
            }
        }
        return false;
    }
};