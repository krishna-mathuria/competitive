#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int x[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };
    int y[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };

bool search2D(vector<vector<char>>grid, int row, int col,string word, int R, int C)
{

    if (grid[row][col] != word[0])
        return false;
 
    int len = word.length();

    for (int dir = 0; dir < 8; dir++) {

        int k, rd = row + x[dir], cd = col + y[dir];

        for (k = 1; k < len; k++) {
            if (rd >= R || rd < 0 || cd >= C || cd < 0)
                break;
 
            if (grid[rd][cd] != word[k])
                break;
 
            rd += x[dir], cd += y[dir];
        }

        if (k == len)
            return true;
    }
    return false;
}

	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> found;
	    int R = grid.size();
	    int C = grid[0].size();
    for (int row = 0; row < R; row++){
        for (int col = 0; col < C; col++){
            if (search2D(grid, row, col, word, R, C)){
	             found.push_back({row,col});   
	            }
	        }
	    }
	    return found;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends