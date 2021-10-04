class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool iscyclic(int i,int k,vector<int> adj[],int V,vector<bool> &vis){
        vis[i]= true;
        for(auto x: adj[i]){
            if(!vis[x]){
                if(iscyclic(x,i,adj,V,vis))
                return true;
            }
            else if(x!=k){
                return true;
            }
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> vis(V+1,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            if(iscyclic(i,-1,adj,V,vis)) return true;
	        }
	    }
	    return false;
	}
};