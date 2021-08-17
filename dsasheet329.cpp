class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    bool vis[V];
	    memset(vis,0,sizeof(vis));
	    queue<int> q;
	    q.push(0);
	    vector<int> ans;
	    vis[0]=1;
	    while(!q.empty()){
	        int temp = q.front();
	        q.pop();
	        ans.push_back(temp);
	        for( auto x: adj[temp]){
	            if(!vis[x]){
	                vis[x]=true;
	                q.push(x);
	            }
	        }
	    }
	    return ans;
	}
};