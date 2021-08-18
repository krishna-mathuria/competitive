bool safe(bool graph[101][101],int V,int s,int j, int *vis){
    for(int k=0;k<V;k++){
        if(graph[s][k] && vis[k]==j){
            return false;
        }
    }
    return true;
}

bool solve(bool graph[101][101],int *vis,int V,int m,int i){
    if(i==V) return true;
    for(int j=0;j<m;j++){
        if(safe(graph,V,i,j,vis)){
            vis[i] = j;
            if(solve(graph,vis,V,m,i+1)) return true;
            vis[i]=-1;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int vis[V];
    memset(vis,-1,sizeof(vis));
    return solve(graph,vis,V,m,0);
}