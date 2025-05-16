#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};
int main()
{
    int V = 4;
    vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    vector<int> parent(V);
    for (int i = 0; i < V; i++)
        parent[i] = i;
    sort(edges.begin(), edges.end());
    vector<Edge> result;
    for (Edge e : edges)
        if (parent[e.u] != parent[e.v])
        {
            result.push_back(e);
            int old_parent = parent[e.v], new_parent = parent[e.u];
            for (int i = 0; i < V; i++)
                if (parent[i] == old_parent)
                    parent[i] = new_parent;
        }

    for (Edge e : result)
        cout << e.u << " - " << e.v << "\n";
}