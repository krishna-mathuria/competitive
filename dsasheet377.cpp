vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
//Your code here
    vector<vector<int>> ans;
    set<vector<int>> st;
    for(int i=0;i<row;i++){
        vector<int> no;
        for(int j=0;j<col;j++){
            no.push_back(M[i][j]);
        }
        if(st.find(no) == st.end())
        {
        st.insert(no);
        ans.push_back(no);
        }
    }
    return ans;
}