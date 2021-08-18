#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100001];
int vis[100001],level[100001];
int par[100001][20];
int n;

void dfs(int s,int parent,int dis){
    vis[s]=1;
    level[s]=dis;
    par[s][0]=parent;
    for(int i=0;i<adj[s].size();i++)
        if(vis[adj[s][i]]==0)
            dfs(adj[s][i],s,dis+1);

}

void init(){
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            if(par[i][j-1]!=-1){
                int temp=par[i][j-1];
                par[i][j]=par[temp][j-1];
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    memset(par,-1,sizeof(par));
    dfs(1,-1,0);
    init();
    int q;
    cin>>q;
    while(q--){

        int code,x,y;
        cin>>code>>x>>y;
        if(x==y){
            cout<<"YES\n";
            continue;
        }
        if(code){
            if(level[y]<level[x]){
                int d=level[x]-level[y];
                while(d){
                    int i=log2(d);
                    x=par[x][i];
                    d-=(1<<i);
                }
                if(x==y)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
            else
                cout<<"NO\n";
        }

        else{

            if(level[x]<level[y]){
                int d=level[y]-level[x];
                while(d){
                    int i=log2(d);
                    y=par[y][i];
                    d-=(1<<i);
                }
                if(x==y)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";

            }
            else
                cout<<"NO\n";
        }
    }
}