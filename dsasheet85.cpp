#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution{
    public:
    int dp[1001][1001];
    int matchUtil(string wild,int i, string pattern, int j){
        int n = wild.size();
        int m = pattern.size();
        if(i == n && j == m)
            return (dp[i][j] = 1);
        else if(i == n && j < m)
            return (dp[i][j] = 0);
        else if(j == m && i < n){
            if(wild[i] == '*')
                return (dp[i][j] = matchUtil(wild,i+1,pattern,j));
            return (dp[i][j] = 0);
        }//elseif
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(wild[i] == pattern[j] || wild[i] == '?')
            return (dp[i][j] = matchUtil(wild,i+1,pattern,j+1));
        
        else if(wild[i] == '*'){
            int m1 = matchUtil(wild,i+1,pattern,j);
            int m2 = matchUtil(wild,i,pattern,j+1);
            dp[i][j] = (m1 || m2);
        }//elseif
        else
            dp[i][j] = 0;
        
        return dp[i][j];
    
    }//func
    
    bool match(string wild, string pattern)
    {
        memset(dp,-1,sizeof(dp));
        if(matchUtil(wild,0,pattern,0) == 1)
        return true;
        return false;
    }

};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}  // } Driver Code Ends