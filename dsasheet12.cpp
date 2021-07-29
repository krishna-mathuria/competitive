// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int N=n+m;
	    int gap = (N+1)/2;
	    while(gap>=1){
	        for(int i=0;i<N-gap;i++){
	            if(i<n && (i+gap)<n){
	                if(arr1[i]>arr1[gap+i]) swap(arr1[i],arr1[gap+i]);
	            }
	            else if(i<n && (i+gap)>=n){
	                if(arr1[i]>=arr2[gap+i-n]) swap(arr1[i],arr2[gap+i-n]);
	            }
	            else if(i>=n)
	            {
	                if(arr2[i-n]>=arr2[gap+i-n]) swap(arr2[i-n],arr2[gap+i-n]);

	            }
	            
	        }
	        if(gap==1) break;
	        gap=(gap+1)/2;
	    }
	}
	
	
};





// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends