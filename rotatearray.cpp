#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    vector<int> arr(n);
	    int j=0;
	    int i=0;
	    while(j<n){
            int f = (n-k+i)%n;
	        cin>>arr[f];
	        j++;
	        i++;
	    }
	    for(int i=0;i<n;i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}