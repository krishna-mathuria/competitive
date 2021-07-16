#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m;
	cin>>n>>m;
	int mat[n+1][m+1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>mat[i][j];
	}
	bool check=true;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int val=0;
			if(i>0) val++;
			if(j>0) val++;
			if(i<n-1) val++;
			if(j<m-1) val++;
			if(mat[i][j]>val)
			{
				check=false;
				break;
			}
			mat[i][j]=val;
		}
		if(!check)
			break;
	}
	if(check)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}
	}
	else
		cout<<"NO"<<endl;
}
int main()
{
	int t=1;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		solve();
	}
    return 0;
}