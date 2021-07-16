#include<bits/stdc++.h>
using namespace std;
int t;
string x,y,temp; 
int main() {
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		cin>>x>>y;
		int count=0,ans=0;
		for(int i=y.size()-1;i>=0;i--)
			if(y[i]=='0') count++;
			else break;
		for(int i=x.size()-count-1;i>=0;i--)
			if(x[i]=='0') ans++;
			else break; 
		printf("%d\n",ans);
	}
	return 0;
}