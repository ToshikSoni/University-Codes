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
void createGraph(Node *arr[], int noNode)
{
    Node *newNode, *last;
    int n, val;
    for (int i = 0; i < noNode; i++)
    {
        last = NULL;
        cout << "\nEnter number of neighbours of " << i << endl;
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            cout << "Enter value of " << j << " neighbour of " << i << endl;
            cin >> val;
            newNode = new Node();
            newNode->vertex = val;
            newNode->next = NULL;
            if (arr[i] == NULL)
                arr[i] = newNode;
            else
                last->next = newNode;
            last = newNode;
        }
    }
}
void displayGraph(Node *arr[], int noNode)
{
    Node *ptr;
    for (int i = 0; i < noNode; i++)
    {
        cout << endl;
        ptr = arr[i];
        cout << "Neighbours of " << i << " are:" << endl;
        while (ptr != NULL)
        {
            cout << ptr->vertex << " ";
            ptr = ptr->next;
        }
    }
}
int main()
{
    int size;
    cout << "Enter number of nodes: ";
    cin >> size;
    Node *arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = NULL;
    createGraph(arr, size);
    displayGraph(arr, size);
}