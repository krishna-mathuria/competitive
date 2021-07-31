#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int counter=0,ans=0;
      sort(arr,arr+N);
      for(int i=0;i<N;i++){
          counter=1;
          while(arr[i+1]==arr[i]+1 || arr[i+1]==arr[i]){
              if(arr[i+1]==arr[i]+1)
                counter++;
              i++;
          }
          ans=max(ans,counter);
      }
      return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends