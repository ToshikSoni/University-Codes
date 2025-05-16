#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;
void prim(int src, vector<vector<pair<int, int>>> &adj, vector<int> &parent)
{
    int V = adj.size();
    vector<int> key(V, INF);
    vector<bool> inMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});
    key[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
}
int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    adj[0] = {{1, 2}, {3, 6}};
    adj[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
    adj[2] = {{1, 3}, {4, 7}};
    adj[3] = {{0, 6}, {1, 8}};
    adj[4] = {{1, 5}, {2, 7}};
    vector<int> parent(V, -1);
    prim(0, adj, parent);
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "\n";
}