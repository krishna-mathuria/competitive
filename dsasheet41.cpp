class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int> temp;
        for(auto i : v)
            temp.insert(temp.end(), i.begin(), i.end());
        
        sort(temp.begin(), temp.end());
        
        int counter = 0;
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < v[i].size(); j++)
            {
                v[i][j] = temp[counter++];
            }
        }
        return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}