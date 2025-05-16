#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int MAXN = 1000;
const int INF = INT_MAX;
int n, m;
vector<pair<int, int>> adj[MAXN];
void primsMST(int start)
{
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    vector<bool> vis(n, false);
    dist[start] = 0;
    int total_cost = 0;
    for (int count = 0; count < n; ++count)
    {
        int u = -1;
        for (int i = 0; i < n; ++i)
            if (!vis[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        if (u == -1)
            break;
        vis[u] = true;
        total_cost += dist[u];
        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (!vis[v] && weight < dist[v])
            {
                dist[v] = weight;
                parent[v] = u;
            }
        }
    }
    cout << "Edges in the MST:\n";
    for (int i = 1; i < n; ++i)
        if (parent[i] != -1)
            cout << parent[i] << " - " << i << " : " << dist[i] << "\n";
    cout << "Total cost: " << total_cost << "\n";
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    primsMST(0);
    return 0;
}