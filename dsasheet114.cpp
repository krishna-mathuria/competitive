#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isValid(int arr[],int n,int m,int pg){
        int s =1;
        int counter =0;
        for(int i=0;i<n;i++){
            counter+=arr[i];
            if(counter>pg){
                s++;
                counter = arr[i];
            }
            if(s>m) return false;
        }
        return true;
    }
    
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(m>n) return -1;
        int sum=arr[0];
        int mx = arr[0];
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(arr[i]>mx) mx = arr[i];
        }
        int res = -1;
        while(mx<=sum){
            int mid = mx + (sum-mx)/2;
            if(isValid(arr,n,m,mid)){
                res = mid;
                sum = mid - 1;
            }
            else{
                mx = mid+1;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}