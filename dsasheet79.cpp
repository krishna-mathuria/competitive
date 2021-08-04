#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string findSubString(string str)
    {
        // Your code goes here   
        int visited[256]={0};
        int dis_count=0;
        for(int i=0;i<str.size();i++){
            if(visited[str[i]]==0)
                dis_count++;
            visited[str[i]]++;
        }
        
         int start = 0, start_index = -1, min_len = INT_MAX;
 
        int count = 0;
        int curr_count[256] = { 0 };
        for(int i=0;i<str.size();i++){
            curr_count[str[i]]++;
            if(curr_count[str[i]]==1){
                count++;
            }
            
            if(count==dis_count){
                while (curr_count[str[start]] > 1) {
                    if (curr_count[str[start]] > 1)
                        curr_count[str[start]]--;
                    start++;
                }
                int l = i-start+1;
                if(l<min_len){
                    min_len = l;
                    start_index = start;
                }
            }
        }
        return str.substr(start_index,min_len);
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
} 