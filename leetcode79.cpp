class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i,int j,string word,int k){
        if(k==word.size()) return true;
        if(i<board.size()-1 && board[i+1][j]==word[k]){
            char c = board[i+1][j];
            board[i+1][j]='*';
            if(dfs(board,i+1,j,word,k+1) ) return true;
            board[i+1][j]=c;
        }
        if(j<board[0].size()-1 && board[i][j+1]==word[k]){
             char c = board[i][j+1];
            board[i][j+1]='*';
            if(dfs(board,i,j+1,word,k+1)) return true;
            board[i][j+1]=c;
        }
         if( i>0 && board[i-1][j]==word[k]){
             char c = board[i-1][j];
             board[i-1][j]='*';
            if(dfs(board,i-1,j,word,k+1)) return true;
             board[i-1][j]=c;
        }
         if(j>0 && board[i][j-1]==word[k]){
             char c = board[i][j-1];
             board[i][j-1]='*';
            if(dfs(board,i,j-1,word,k+1)) return true;
             board[i][j-1]=c;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    char c = board[i][j];
                    board[i][j]='*';
                    if(dfs(board,i,j,word,1)) return true;
                    board[i][j]=c;
                }
            }
        }
        return false;
    }
};

// C A A
// A A A
// B C D