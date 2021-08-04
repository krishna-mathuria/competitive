#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

 // } Driver Code Ends
//User function Template for C++

vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    // Your Code Here
    vector<vector<string>> ans;
    vector<string> unique;
    string temp;
    for(int i=0;i<string_list.size();i++){
        bool flag=0;
        temp = string_list[i];
        sort(temp.begin(),temp.end());
        for(int j=0;j<unique.size();j++){
            if( unique[j] == temp){
                ans[j].push_back(string_list[i]);
                flag=1;
            }
        }
        if(!flag){
            unique.push_back(temp);
            ans.push_back({string_list[i]});
        }
        
    }
    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}