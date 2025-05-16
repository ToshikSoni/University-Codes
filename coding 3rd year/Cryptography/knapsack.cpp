#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int size = 6;
    vector<int> knapsack;
    knapsack.push_back(1);
    for (int i = 0; i < size; i++)
    {
        int temp = 0;
        for (int j = 0; j <= i; j++)
            temp += knapsack[j];
        knapsack.push_back(temp + 1);
    }
    for (auto x : knapsack)
        cout << x << '\t';
}