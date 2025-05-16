#include <iostream>
#include <vector>
#include <queue>
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
vector<pair<char, char>> prim(vector<node *> adjm, node *start)
{
    vector<bool> inMST(adjm.size(), false);
    vector<pair<char, char>> mstEdges;
    priority_queue<pair<int, pair<node *, node *>>, vector<pair<int, pair<node *, node *>>>, greater<pair<int, pair<node *, node *>>>> pq;
    pq.push({0, {start, start}});
    while (!pq.empty())
    {
        int weight = pq.top().first;
        node *u = pq.top().second.first;
        node *v = pq.top().second.second;
        pq.pop();
        if (inMST[v->vertex - 'A'])
            continue;
        inMST[v->vertex - 'A'] = true;
        if (u != v)
            mstEdges.push_back({u->vertex, v->vertex});
        for (auto &edge : v->edges)
            if (!inMST[edge.first->vertex - 'A'])
                pq.push({edge.second, {v, edge.first}});
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
    vector<pair<char, char>> mstEdges = prim(adjm, adjm[0]);
    cout << "Minimum Spanning Tree edges:" << endl;
    for (auto &edge : mstEdges)
        cout << "Edge: " << edge.first << " - " << edge.second << endl;
}