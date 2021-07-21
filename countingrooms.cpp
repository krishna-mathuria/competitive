#include <bits/stdc++.h>
using namespace std;
char arr[1001][1001];
int vis[1001][1001];

int n,k;

bool check(int x,int y){
	if(x<1 || y<1 || x>n || y>k ) return false;
	if(arr[x][y]=='#') return false;
	if(vis[x][y]==1) return false;
	return true;
}

void dfs(int x,int y){
	vis[x][y]=1;
	if(check(x+1,y))
	dfs(x+1,y);
	if(check(x-1,y))
	dfs(x-1,y);
	if(check(x,y+1))
	dfs(x,y+1);
	if(check(x,y-1))
	dfs(x,y-1);
} 

int main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=k;j++)
	cin>>arr[i][j];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
		if(vis[i][j]==0 && arr[i][j]=='.'){
			ans++;
			dfs(i,j);
		}		
		}
	}
	cout<<ans;
	return 0;
}