#include<iostream>
#include<string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
}// } Driver Code Ends


/*Complete the function below*/
int PalinArray(int a[], int n)
{  //add code here.
    for(int i = 0 ; i < n ; i++ ) {
        string a1 = to_string( a[i] ) ;
        int l = 0 , r = a1.size() - 1 ;
        while(l <= r){
            if(a1[l] != a1[r])return false;
            l++ , r-- ;
        }
    }
    return true;
}