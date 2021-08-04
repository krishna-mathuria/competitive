#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
    // code here
    int left=0,right=0,n=s.size(),swaps=0;
    for(int i=0;i<n;i++) { 
        if(s[i]=='[') 
        { 
            if(right>left)
            swaps+=(right-left);
            left++;
        }
        if(s[i]==']')
            right++;
    }
    return swaps;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}