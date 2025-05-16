#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    queue<string> q;
    q.push("5");
    q.push("6");
    int n = 10;
    for (int count = 0; count < n; count++)
    {
        string curr = q.front();
        cout << "Curr: " << q.front() << endl;
        q.pop();
        q.push(curr + '5');
        q.push(curr + '6');
    }
}