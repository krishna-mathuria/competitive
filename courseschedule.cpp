#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> adj[100005];
stack<ll> st;
vector<ll> vis;
int v1[100005];

bool cycle(int s){
    v1[s]=1;
    for (auto i: adj[s]){
        if (!v1[i]){
            if (cycle(i)) return 1;
        }
        else if (v1[i]==1) return 1;
    }
    v1[s] = 2;
    return 0;
}


void dfs(ll node){
if(vis[node]) return;
    vis[node] =1;
    for(auto it : adj[node]){
            dfs(it);
    }
    st.push(node);
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vis.resize(n+1,0);

    for(ll i=1;i<=m;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for(ll i=1;i<=n;i++){
        if (!v1[i] && cycle(i))
        {
            cout<<"IMPOSSIBLE";
            return 0;
            
        }
        if(!vis[i]){
            dfs(i);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}