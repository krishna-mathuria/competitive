#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


bool search(int a1[],int x,int l,int r){
    
     while (l <= r) {
        int m = l + (r - l) / 2;
  
        // Check if x is present at mid
        if (a1[m] == x)
            return true;
  
        // If x greater, ignore left half
        if (a1[m] < x)
            l = m + 1;
  
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
  
    // if we reach here, then element was
    // not present
    return false;
}


string isSubset(int a1[], int a2[], int n, int m) {
    if(n<m) return "No";
    sort(a1,a1+n);
    for(int i=0;i<m;i++){
        if(!search(a1,a2[i],0,n-1)) return "No";
    }
    return "Yes";
}

