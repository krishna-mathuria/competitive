class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
        int dist[n];
        for(int i=0;i<n;i++){
            dist[i]=INT_MAX;
        }
        dist[0]=0;

    	for (int i = 1; i <= n - 1; i++) {
            for (int j = 0; j < edges.size(); j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                int weight = edges[j][2];
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                return 1; 
            }
        }
     
     
        return 0;
	}
};