void printOrder(int n, int m)
{

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            job[i] = 1;
        }
    }
    while (!q.empty()) {

        int cur = q.front();

        q.pop();
 
        for (int adj : graph[cur]) {

            indegree[adj]--;
 
            if (indegree[adj] == 0) {
                job[adj] = job[cur] + 1;
                q.push(adj);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << job[i] << " ";
    cout << "\n";
}