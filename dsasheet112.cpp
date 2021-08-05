#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int N = n+m;
        int gap = (N+1)/2;
        while(gap>=1){
            for(int i=0;(i+gap)<N;i++){
                if(i<n && i+gap<n){
                    if(arr1[i]>arr1[i+gap]) swap(arr1[i],arr1[i+gap]);
                }
                else if(i<n && i+gap>=n){
                    if(arr1[i]>arr2[i+gap-n]) swap(arr1[i],arr2[i+gap-n]);
                }
                else if(i>=n && i+gap>=n){
                    if(arr2[i-n]>arr2[i+gap-n]) swap(arr2[i-n],arr2[i+gap-n]);
                }
            }
            if(gap==1) break;
            gap = (gap+1)/2;
        }
        if(k<=n) return arr1[k-1];
        else return arr2[k-n-1];
    }
};


// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
} 