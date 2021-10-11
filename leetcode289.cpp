class Solution {
public:
    pair<int,int> getneighbours(int i,int j,vector<vector<int>> board){
        int one=0,zero=0;
        int dx[8] = {1,-1,1,-1,1,-1,0,0};
        int dy[8] = {1,-1,-1,1,0,0,1,-1};
        for(int k=0;k<8;k++){
            if(i+dx[k]<board.size() && i+dx[k]>=0 && j+dy[k]<board[0].size() && j+dy[k]>=0){
                if(board[i+dx[k]][j+dy[k]]==0 || board[i+dx[k]][j+dy[k]]==2 ) zero++;
                else one++;
            }
        }
        return {zero,one};
    }
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                auto x = getneighbours(i,j,board);
                //cout<<x.first<<" "<<x.second<<endl;
                if(board[i][j]==1){
                    if(x.second<2){
                        board[i][j]=-1;
                    }
                    else if(x.second>3){
                        board[i][j]=-1;
                    }
                }else{
                    if(x.second==3){
                        board[i][j]=2;
                    }
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==2) board[i][j]=1;
                else if(board[i][j]==-1) board[i][j]=0;
            }
        }
    }
};