#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000001
#define f first
#define s second
#define mp make_pair

long long bgx,bgy,edx,edy;
map<pair<long long,long long>, bool> allowed;
map<pair<long long,long long>, long long> steps;
map<pair<long long,long long>, bool> visited;

queue<pair<long long,long long>> q;
// 0 = up, 1 = right, 2 = down, 3 = left, left-up = 4, left-down = 5,right-up=6,right-down=7
int dx[8] = { -1, 0, 1, 0,-1,1,-1,1 };
int dy[8] = { 0, 1, 0, -1,-1,-1,1,1 };


void bfs(long long x,long long y){
	q.push(make_pair(x,y));
	visited[{x,y}]=true;
	while(!q.empty()){
		pair<long long,long long> u = q.front(); q.pop();
		for (int i = 0; i < 8; i++) {
			pair<long long,long long> v = make_pair(u.f + dx[i], u.s + dy[i]);
			if (v.f < 1 || v.f >= MAXN || v.s < 1 || v.s >= MAXN) continue;
			if (allowed[{v.f,v.s}] == false) continue;
			if (visited[{v.f,v.s}]) continue;
			visited[{v.f,v.s}] = true;
			if(!steps[{v.f, v.s}] ||  steps[{v.f, v.s}] > steps[{u.first, u.second}] + 1)
                    steps[{v.f, v.s}] = steps[{u.first, u.second}] + 1;
			q.push(v);
		}
	}
	
	if(visited[{edx,edy}]){
		cout<<steps[{edx,edy}];
	}
	else{
		cout<<-1;
	}
}

int main() {
	long long t;
	cin>>bgx>>bgy>>edx>>edy;
	cin>>t;
	long long r,c1,c2;
	while(t--){
		cin>>r>>c1>>c2;
		for(long long i=c1;i<=c2;i++){
			allowed[{r,i}]=true;
		}
	}
	bfs(bgx,bgy);
	return 0;
}