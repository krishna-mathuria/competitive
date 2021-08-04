#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    if(s.length()%2!=0) return -1;
    stack<int> st;
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{'){
            st.push('{');
        }
        else if(!st.empty() && st.top()=='{'){
            st.pop();
        }
        else{
            count++;
            st.push('{');
        }
    }
    count+=st.size()/2;
    return count;
}