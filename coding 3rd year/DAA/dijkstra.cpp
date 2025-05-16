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
vector<int> dijkstra(vector<node *> adjm, node *start)
{
    vector<int> dist(adjm.size(), INT_MAX);
    dist[start->vertex - 'A'] = 0;
    priority_queue<pair<int, node *>, vector<pair<int, node *>>, greater<pair<int, node *>>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        int curr_dist = pq.top().first;
        node *curr_node = pq.top().second;
        pq.pop();
        for (auto &edge : curr_node->edges)
        {
            int new_dist = curr_dist + edge.second;
            if (new_dist < dist[edge.first->vertex - 'A'])
            {
                dist[edge.first->vertex - 'A'] = new_dist;
                pq.push({new_dist, edge.first});
            }
        }
    }
    return dist;
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
    vector<int> distances = dijkstra(adjm, adjm[0]);
    cout << "Shortest distances from node A:" << endl;
    for (int i = 0; i < distances.size(); ++i)
        cout << "Node " << char('A' + i) << ": " << distances[i] << endl;
}