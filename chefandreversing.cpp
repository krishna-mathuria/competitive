#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll>> adj[100007];
bool vis[100007];
deque<ll> q; 
ll n,m;

void bfs(){
    vector<ll> dist(n+1,INT_MAX);
    dist[1]=0;
    vis[1]=1;
    q.push_front(1);
    while(!q.empty()){
        ll prev = q.front();
        q.pop_front();
        for( auto it : adj[prev]){
            ll x = it.first;
            ll y = it.second;
            if(dist[x]>dist[prev]+y){ 
                dist[x]=dist[prev]+y;
                if(y==1) q.push_back(x);
                else q.push_front(x);
            }
        }
    }
     if(dist[n]==INT_MAX) dist[n]=-1;
    cout<<dist[n]<<"\n";
}


int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back({b,0});
        adj[b].push_back({a,1});
    }
    bfs();
}