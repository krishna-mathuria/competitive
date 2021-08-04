#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int counter[256]={0};
        int dis=0;
        for(int i=0;i<p.size();i++){
            if(counter[p[i]]==0){
                dis++;
            }
            counter[p[i]]++;
        }
        int i=0,j=0;
        int min_len = INT_MAX;
        int start;
        while (j < s.length()) {
        counter[s[j]]--;
        if (counter[s[j]] == 0)
            dis--;
         if (dis == 0) {
            while (dis == 0) {
                if (min_len > j - i + 1) {
                    min_len = min(min_len, j - i + 1);
                    start = i;
                }
                counter[s[i]]++;
                if (counter[s[i]] > 0)
                    dis++;
 
                i++;
            }
        }
        j++;
    }
        if(min_len==INT_MAX) return "-1";
        return s.substr(start,min_len);
        
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
} 