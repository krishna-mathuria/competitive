#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int soldiers[n];
	int sum[n];
	for(int i=0;i<n;i++){
		cin>>soldiers[i];
	}
	sort(soldiers,soldiers+n);
	sum[0]=soldiers[0];
	for(int i=1;i<n;i++){
		sum[i] = sum[i-1] + soldiers[i];
	}
	int q;
	cin>>q;
	while(q--){
		int p;
		cin>>p;
		int count=n;
		for(int i=0;i<n;i++){
			if(p<soldiers[i]){
				count = i;
				break;
			}
		}
		cout<<count<<" "<<sum[count-1]<<"\n";
	}
	
}
