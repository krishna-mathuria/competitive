#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> a;
	    for(int i=0;i<n;i++){
	        int x;
	        cin>>x;
	        if(x%2==0){
	            a.push_back(x);
	        }
	    }
	    n=(n+1)/2;
	    if(a.size()<n){
	        cout<<"NO\n";
	        continue;
	    }
	     sort(a.begin(), a.end());

        if(a[0]==2)
        {
            cout << "YES" << endl;
            continue;
        }

        bool next = false;

        int ans = a[0], count = 0;;
        for(int i=0;i<n;i++)
        {
            int x= __gcd(ans, a[i]);

            ans = x;
        }

        if(ans==2){
            cout << "YES" << endl;
            continue;
        }
        else{
            cout << "NO" << endl;
            continue;
        }
	}
	
}