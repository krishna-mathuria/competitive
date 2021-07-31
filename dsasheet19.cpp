#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            int j=0,k=0;
            vector<int> ans;
            for(int i=0;i<n1;i++){
                if(i>=n1 || j>=n2 || k>=n3) break;
                
                if(A[i]<B[j] && A[i]<C[k]) continue;
                
                while(A[i]>B[j]){
                    j++;
                }

                while(A[i]>C[k]){
                    k++;
                }

                if(A[i]==B[j] && A[i]==C[k]){
                    if((ans.empty()) || (!ans.empty() && ans[ans.size()-1]!=A[i]))
                        ans.push_back(A[i]);
                    j++;
                    k++;
                    continue;
                }
            }
            return ans;
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends