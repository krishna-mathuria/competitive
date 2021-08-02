// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int arr[m]={0};
        int area=INT_MIN;
        for(int k=0;k<n;k++){
            for(int j=0;j<m;j++){
                if(M[k][j]==1){
                arr[j] += M[k][j];
                }
                else arr[j]=0;
            }
        
        stack<int> s;
        s.push(-1);
        vector<int> left_smaller(m, -1), right_smaller(m, m);
        int i=0;
        while(i<m){
            while(!s.empty()&&s.top()!=-1&&arr[s.top()]>arr[i]){
                right_smaller[s.top()] = i;
                s.pop();
            }
            if(i>0&&arr[i]==arr[i-1]){
               left_smaller[i] = left_smaller[i-1];
            }else{

                left_smaller[i] = s.top();
            } 
            s.push(i);
            i++;
        }
        

        for(int j = 0; j<m; j++){
            area = max(area, arr[j]*(right_smaller[j]-left_smaller[j]-1));
        }
        }
        return area;
    }
    
    
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}