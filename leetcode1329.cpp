class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n=mat[0].size();
        for(int i=0;i<mat.size();i++){
            vector<int> s;
            int j=0;
            int l=i;
            while(j<n && l<m){
                s.push_back(mat[l][j]);
                l++;
                j++;
            }
            sort(s.begin(),s.end());
            j=0;
            l=i;
            while(j<n && l<m){
                mat[l][j] = s[j];
                l++;
                j++;
            }
        }
        for(int i=1;i<mat[0].size();i++){
            vector<int> s;
            int j=0;
            int l=i;
            while(j<m && l<n){
                s.push_back(mat[j][l]);
                l++;
                j++;
            }
            sort(s.begin(),s.end());
            j=0;
            l=i;
            while(j<m && l<n){
                mat[j][l] = s[j];
                l++;
                j++;
            }
        }
        return mat;
    }
};