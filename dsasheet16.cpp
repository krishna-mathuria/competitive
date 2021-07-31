// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long getSUM(long long BIT[],long long index){
        long long sum=0;
        while(index>0){
            sum+=BIT[index];
            index-= index & (-index);
        }
        return sum;
    }

    void updateBIT(long long BIT[],long long N,long long index,long long inc){
        while(index<=N){
            BIT[index]+=inc;
            index+=index & (-index);
        }
    }

    void convert(long long arr[],long long  N){
        long long temp[N];
        for(int i=0;i<N;i++){
            temp[i]=arr[i];
        }
        sort(temp,temp+N);
        for(int i=0;i<N;i++){
            arr[i] = lower_bound(temp,temp+N,arr[i]) - temp + 1;
        }
    }

    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        convert(arr,N);
        unsigned long long invcount=0;
        long long BIT[N];
        for(int i=0;i<N;i++) BIT[i]=0;
        for(int i=N-1;i>=0;i--){
            invcount+=getSUM(BIT,arr[i]-1);
            updateBIT(BIT,N,arr[i],1);
        }
        return invcount;
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
  // } Driver Code Ends