#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    int k = 3;
    stack<int> s;
    for (int i = 0; i < q.size() - k; i++)
    {
        s.push(q.front());
        q.pop();
    }
}