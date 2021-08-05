#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    static bool cmpare(int a , int b){
        int count = 0 , count2 = 0 , x,y;
        x = a;
        y =b;
        while(x != 0){
            count += x&1;
            x = x >> 1;
        }
        while(y != 0){
            count2 += y&1;
            y = y >> 1;
        }
        return count > count2;
    }

    void sortBySetBitCount(int arr[], int n)
    {
       stable_sort(arr,arr+n,cmpare);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}