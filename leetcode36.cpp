class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
        int freq3[3][3][10];
        memset(freq3,0,sizeof(freq3));
        for(int i=0;i<9;i++){
            int freq[10]={0};
            int freq2[10]={0};
            for(int j=0;j<9;j++){
                if(mat[i][j]!='.' && mat[i][j]<='9'){
                    freq[mat[i][j]-'0']++;
                    if(freq[mat[i][j]-'0']==2) return 0;
                    freq3[i/3][j/3][mat[i][j]-'0']++;
                    if(freq3[i/3][j/3][mat[i][j]-'0']==2) return 0;
                }
                if(mat[j][i]!='.' && mat[j][i]<='9'){
                    freq2[mat[j][i]-'0']++;
                    if(freq2[mat[j][i]-'0']==2) return 0;
                }
            }
            
        }
        return 1;
    }
};