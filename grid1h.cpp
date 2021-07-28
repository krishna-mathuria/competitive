#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
char graph[1005][1005];
ll dp[1005][1005];
ll h,w;
ll ans;


bool check(int x,int y){
	if(x>h || y>w || y<1 || x<1) return false;
	if(graph[x][y]=='#') return false;

	return true;
}
 

 
ll dfs(int x,int y){
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    dp[x][y]=0;

	if(check(x+1,y)){
		dp[x][y] += dfs(x+1,y);
		dp[x][y]%=MOD;
		
	}
	if(check(x,y+1)){
		dp[x][y] += dfs(x,y+1);
		dp[x][y]%=MOD;
	}
	return dp[x][y];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>h>>w;
    for(ll i=1;i<=h;i++){
        for(ll j=1;j<=w;j++){
            cin>>graph[i][j];
        }
    }
    dp[h][w]=1;
    cout<<dfs(1,1);
    
}