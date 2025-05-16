#include <iostream>
#define MAX 4
using namespace std;
void breadth_first_search(int adj[][MAX], int visited[], int start)
{
    int queue[MAX], rear = -1, front = -1;
    queue[++rear] = start;
    visited[start] = 1;
    while (rear != front)
    {
        start = queue[++front];
        cout << (char)(start + 65) << "\t";
        for (int i = 0; i < MAX; i++)
            if (adj[start][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
    }
}
void depth_first_search(int adj[][MAX], int visited[], int start)
{
    int stack[MAX], top = -1, i;
    stack[++top] = start;
    visited[start] = 1;
    cout << (char)(start + 65) << "\t";
    while (top != -1)
    {
        start = stack[top];
        for (i = 0; i < MAX; i++)
            if (adj[start][i] && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
                cout << (char)(i + 65) << "\t";
                break;
            }
        if (i == MAX)
            top--;
    }
}
int main()
{
    int visited[MAX] = {0};
    int adj[MAX][MAX], i, j;
    cout << "Enter the adjancey matrix: " << endl;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            cin >> adj[i][j];
    breadth_first_search(adj, visited, 0);
}