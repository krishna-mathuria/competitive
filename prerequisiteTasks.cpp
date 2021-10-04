class Solution {
    public:
	bool isPossible(int N, vector<pair<int, int>> &prerequisites) 
	{
	    vector<int> adj[N];
	    vector<int> indeg(N, 0);
	    for(auto edge: prerequisites)
	    {
	        int u = edge.second;
	        int v = edge.first;
	        adj[u].push_back(v);
	        indeg[v]++;
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < N; i++)
	    {
	        if(indeg[i] == 0)
	        {
	            q.push(i);
	        }
	    }
	    int count = 0;
	    while(!q.empty())
	    {
	        int u = q.front();
	        q.pop();
	        
	        for(auto v: adj[u])
	        {
	            indeg[v]--;
	            
	            if(indeg[v] == 0)
	            {
	                q.push(v);
	            }
	        }
	        
	        count++;
	    }
	    
	    return count == N;
	}
};