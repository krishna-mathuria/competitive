#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;
# define INF 1e18
vector<pair<int,int> > adj[100005];
int steps[100005];
void shortestPath(int V, int src)
{   
    steps[1]=0;
    steps[V-1]=-1;
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    vector<long long> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;
  

    while (!pq.empty())
    {

        int u = pq.top().second;
        pq.pop();
  

        for (auto x : adj[u])
        {

            int v = x.first;
            int weight = x.second;
  
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                steps[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    int kid = V-1;
    if(steps[V-1]==-1){
        cout<<-1;
    }else{
    vector<int> ans;
    while(kid!=0){
        
        ans.push_back(kid);
        kid=steps[kid];
    }
    for(int i=ans.size()-1;i>=0;i--)
    cout<<ans[i]<<" "; 
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    shortestPath(n+1,1);
}