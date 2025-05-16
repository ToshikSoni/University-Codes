#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> findStockSpans(vector<int> &vec)
{
    vector<int> out;
    stack<int> s;
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        while (s.empty() == false && s.top() <= vec[i])
            s.pop();
        int value = s.empty() ? -1 : s.top();
        out.push_back(value);
        s.push(vec[i]);
    }
    return out;
}
int main()
{
    vector<int> vec{15, 10, 18, 12, 4, 6, 2, 8}, temp;
    temp = findStockSpans(vec);
    for (auto i : vec)
        cout << i << '\t';
    cout << endl;
    for (int i = temp.size() - 1; i >= 0; i--)
        cout << temp[i] << '\t';
}