#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class node
{
public:
    char vertex;
    vector<pair<node *, int>> edges;
    node(char v)
    {
        vertex = v;
    }
    void addedge(vector<pair<node *, int>> e)
    {
        edges = e;
    }
};
class Edge
{
public:
    char u, v;
    int weight;
    Edge(char u, char v, int weight) : u(u), v(v), weight(weight) {}
};
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}
int find(vector<int> &parent, int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
void unionSet(vector<int> &parent, int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    if (xset != yset)
        parent[xset] = yset;
}
vector<Edge> kruskal(vector<node *> adjm)
{
    vector<Edge> edges;
    for (auto &n : adjm)
        for (auto &e : n->edges)
            edges.push_back(Edge(n->vertex, e.first->vertex, e.second));
    sort(edges.begin(), edges.end(), compare);
    vector<Edge> mstEdges;
    vector<int> parent(adjm.size(), -1);
    for (auto &edge : edges)
    {
        int u = find(parent, edge.u - 'A');
        int v = find(parent, edge.v - 'A');
        if (u != v)
        {
            mstEdges.push_back(edge);
            unionSet(parent, u, v);
        }
    }
    return mstEdges;
}
int main()
{
    vector<node *> adjm;
    int size;
    cout << "Enter number of nodes: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        char v;
        cout << "Enter vertex: ";
        cin >> v;
        adjm.push_back(new node(v));
    }
    cout << endl;
    for (auto x : adjm)
        cout << x->vertex << ' ';
    cout << endl;
    for (int i = 0; i < adjm.size(); i++)
        cout << i << ' ';
    cout << endl;
    for (int i = 0; i < adjm.size(); i++)
    {
        vector<pair<node *, int>> e;
        int size, wei, n;
        cout << "Enter number of edges of " << adjm[i]->vertex << ": ";
        cin >> size;
        for (int j = 0; j < size; j++)
        {
            cout << "Enter edge number and weight: ";
            cin >> n >> wei;
            e.push_back({adjm[n], wei});
        }
        adjm[i]->addedge(e);
    }
    cout << endl
         << endl;
    for (auto x : adjm)
    {
        cout << "Vertex: " << x->vertex << endl
             << "Edges: " << endl;
        for (int i = 0; i < x->edges.size(); i++)
            cout << "Vertex: " << x->edges[i].first->vertex << ", Weight: " << x->edges[i].second << endl;
        cout << endl;
    }
    vector<Edge> mstEdges = kruskal(adjm);
    cout << "Minimum Spanning Tree edges:" << endl;
    for (auto &edge : mstEdges)
        cout << "Edge: " << edge.u << " - " << edge.v << " with weight " << edge.weight << endl;
}