 #include <bits/stdc++.h>
using namespace std;

class Solution{
  public:		
	int lps(string s) {
	        int n = s.length();

    int lps[n];
    lps[0] = 0; 


    int len = 0;

    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {

            if (len != 0)
            {
                len = lps[len-1];

            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    int res = lps[n-1];
    return res;
	}
};

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}