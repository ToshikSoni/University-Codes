#include <iostream>
using namespace std;
class Node
{
public:
    int vertex;
    Node *next;
    Node()
    {
        vertex = -1;
        next = NULL;
    }
};
void createGraph(Node *adj[], int no_of_nodes)
{
    Node *newNode, *last;
    int i, j, val, n;
    for (i = 0; i < no_of_nodes; i++)
    {
        last = NULL;
        cout << "\nEnter the number of neighbours of " << i << endl;
        cin >> n;
        for (j = 1; j <= n; j++)
        {
            cout << "\nEnter the value for " << j << " of " << i << endl;
            cin >> val;
            newNode = new Node();
            newNode->vertex = val;
            newNode->next = NULL;
            if (adj[i] == NULL)
                adj[i] = newNode;
            else
                last->next = newNode;
            last = newNode;
        }
    }
}
void displayGraph(Node *adj[], int no_of_nodes)
{
    Node *ptr;
    int i;
    for (i = 0; i < no_of_nodes; i++)
    {
        ptr = adj[i];
        cout << "\nNeighbours of " << i << " are " << endl;
        while (ptr != NULL)
        {
            cout << ptr->vertex << " ";
            ptr = ptr->next;
        }
    }
}
int main()
{
    Node *Adj[10];
    int i, no_of_nodes;
    cout << "Entre number of nodes in graph: ";
    cin >> no_of_nodes;
    for (int i = 0; i < no_of_nodes; i++)
        Adj[i] = NULL;
    createGraph(Adj, no_of_nodes);
    displayGraph(Adj, no_of_nodes);
}