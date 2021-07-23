#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	char maxm, maxm1;
	string s,ans;
	cin>>n>>s;
	for(auto i: s){
		if(i>=maxm){
			ans+='0';
			maxm = i;
		}
		else if(i>=maxm1){
			ans+='1';
			maxm1=i;
		}
		else{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n"<<ans;
	return 0;
}