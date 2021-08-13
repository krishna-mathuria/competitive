class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool issafe(int grid[N][N], int l, int m, int n){
        for(int i=0;i<9;i++){
            if(grid[i][n]==l)
                return false;
        }
        for(int i=0;i<9;i++){
            if(grid[m][i]==l)
                return false;
        }
        for(int i=3*(m/3);i<=3*(m/3)+2;i++){
            for(int j=3*(n/3);j<=3*(n/3)+2;j++){
                if(grid[i][j]==l)
                    return false;
            }
        }
        return true;
    }
    bool solve(int grid[N][N] , int m , int n){
        if(n==9 && m==8) return true;
        if(n==9){
            m++;
            n=0;
        }
        if(grid[m][n]==0){
            for(int l=1;l<=9;l++){
                if(issafe(grid,l,m,n)==true){
                    grid[m][n]=l;
                    if(solve(grid,m,n+1)){
                        return true;
                    }
                    grid[m][n] = 0;
                }
            }
            return false;
        }
        else{
            if(solve(grid,m,n+1)==true){
                return true;
            }
        }
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        if(solve(grid,0,0)==true) return true;
        else return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};