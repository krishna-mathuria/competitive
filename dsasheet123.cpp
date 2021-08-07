#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge(long long int arr[],long long int temp[],long long int start,long long int mid,long long int end){
        long long int i,j,k;
        long long int invcount=0;
        i=start;
        j=mid;
        k = start;
        while((i<=mid-1) && (j<=end)){
            if(arr[i]<=arr[j]) temp[k++]=arr[i++];
            else{
                temp[k++]=arr[j++];
                invcount = invcount + (mid-i);
            }
        }
        while(i<=mid-1){
            temp[k++]=arr[i++];
        }
        while(j<=end){
            temp[k++]=arr[j++];
        }
        for(i=start;i<=end;i++){
            arr[i]=temp[i];
        }
        return invcount;
    }
    
    long long int mergeSort(long long int arr[],long long int temp[],long long int start,long long int end){
        long long int mid;
        long long invcount=0;
        if(start<end) {
            mid = (end+start)/2;
            invcount+=mergeSort(arr,temp,start,mid);
            invcount+=mergeSort(arr,temp,mid+1,end);
            invcount+=merge(arr,temp,start,mid+1,end);
        }
        return invcount;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int temp[N];
        return mergeSort(arr,temp,0,N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}