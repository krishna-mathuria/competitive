#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    int p=0,q=0;
    int n =s.size();
    for(int i=0;i<n;i++){
        if (i%2==0 && s[i]=='1') p++;
        else if(i%2!=0 && s[i]=='0') p++;
        else if(i%2==0 && s[i]=='0') q++;
        else if(i%2!=0 && s[i]=='1') q++;
    }
    return min(p,q);
}
