class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void topologicalSortUtil(int v, bool visited[],stack<int>& st,vector<int> adj[]){
	    visited[v]=true;
	    for(auto x:adj[v])
	        if (!visited[x])
                topologicalSortUtil(x, visited, st,adj);
 
    st.push(v);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    stack<int> st;
	    bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                topologicalSortUtil(i, visited, st,adj);
            
        while (st.empty() == false) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
	}
	
};