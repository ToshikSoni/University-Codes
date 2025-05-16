#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;
void dijkstra(int src, vector<vector<pair<int, int>>> &adj, vector<int> &dist)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}
int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    adj[0] = {{1, 9}, {2, 6}, {3, 5}, {4, 3}};
    adj[2] = {{1, 2}, {3, 4}};
    adj[3] = {{4, 1}};
    vector<int> dist(V, INF);
    dijkstra(0, adj, dist);
    for (int i = 0; i < V; ++i)
        cout << dist[i] << " ";
}