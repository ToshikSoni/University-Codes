#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 10000000;
int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<pair<int, int>>> graph(vertices + 1);
    vector<int> dist(vertices + 1, INF);
    for (int i = 0; i < edges; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int source;
    cin >> source;
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while (!pq.empty())
    {
        int currentVertex = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();
        for (int i = 0; i < graph[currentVertex].size(); ++i)
        {
            int neighborVertex = graph[currentVertex][i].first;
            int weight = graph[currentVertex][i].second;
            if (dist[currentVertex] + weight < dist[neighborVertex])
            {
                dist[neighborVertex] = dist[currentVertex] + weight;
                pq.push({dist[neighborVertex], neighborVertex});
            }
        }
    }
    for (int i = 1; i <= vertices; ++i)
    {
        cout << "Distance from the vertex to souurce is  " << source << " to " << i << " is ";
        if (dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }
}