#include<bits/stdc++.h>
using namespace std;

int n, m;
int counter;
unordered_set<int> visited;
unordered_set<int> vertices;
vector<int> collectAnswers;
vector<int> adjacencyList[100000];


void dfs(int sv)
{
    visited.insert(sv);
    for (int i : adjacencyList[sv])
    {
        if (visited.find(i) != visited.end()) continue;
        visited.insert(i);
        dfs(i);
    }
    counter++;

}

void find_numbers()
{
    for (int i : vertices)
    {    counter = 0;
        if (visited.find(i) != visited.end()) continue;
        dfs(i);
        collectAnswers.push_back(counter);
    }
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++) vertices.insert(i);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        //storing the vertices
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    // cout << "Visiting Order :" << endl;
    find_numbers();
    long long answer = 0;
    long long sum = collectAnswers[0];
    for (int i = 1; i < collectAnswers.size(); i++)
    {
        answer += sum * collectAnswers[i];
        sum += collectAnswers[i];
    }
    cout << answer;

}