#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void findStockSpans(vector<int> &vec)
{
    stack<int> s;
    for (int i = 0; i < vec.size(); i++)
    {
        while (s.empty() == false && s.top() <= vec[i])
            s.pop();
        int value = s.empty() ? -1 : s.top();
        cout << value << endl;
        s.push(vec[i]);
    }
}
int main()
{
    vector<int> vec{15, 10, 18, 12, 4, 6, 2, 8};
    findStockSpans(vec);
}