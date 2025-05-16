#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> iPair;
struct Graph
{
    int V, E;
    vector<pair<int, iPair>> edges;
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }
    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }
    void createGraphWithVMinus1Edges();
};
struct DisjointSets
{
    int *parent, *rnk;
    int n;
    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n + 1];
        rnk = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
            parent[i] = i;
        }
    }
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;
        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};
void Graph::createGraphWithVMinus1Edges()
{
    sort(edges.begin(), edges.end());
    DisjointSets ds(V);
    int edgeCount = 0;
    vector<pair<int, iPair>>::iterator it;
    for (it = edges.begin(); it != edges.end() && edgeCount < V - 1; it++)
    {
        int u = it->second.first;
        int v = it->second.second;
        int weight = it->first;
        int set_u = ds.find(u);
        int set_v = ds.find(v);
        if (set_u != set_v)
        {
            cout << u << " - " << v << " with weight " << weight << endl;
            ds.merge(set_u, set_v);
            edgeCount++;
        }
    }
}
int main()
{
    int V = 4, E = 5;
    Graph g(V, E);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    cout << "Edges of the new graph are \n";
    g.createGraphWithVMinus1Edges();
}