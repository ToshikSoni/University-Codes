#include <iostream>
using namespace std;
int main()
{
    int n = 4, W = 6;
    int w[3] = {1, 2, 3};
    int v[3] = {60, 100, 120};
    int c[n][W] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}};
    for (int i = 1; i < n; i++)
        for (int j = 1; j < W; j++)
            if (w[i - 1] <= j)
                if ((v[i - 1] + c[i - 1][j - w[i - 1]]) > c[i - 1][j])
                    c[i][j] = v[i - 1] + c[i - 1][j - w[i - 1]];
                else
                    c[i][j] = c[i - 1][j];
            else
                c[i][j] = c[i - 1][j];
    int i = n - 1;
    int j = W - 1;
    cout << "Maximum profit: " << c[i][j] << endl;
    cout << "Items included: ";
    while (i > 0 && j > 0)
    {
        if (c[i][j] != c[i - 1][j])
        {
            cout << "Item " << i << " is part of the knapsack" << endl;
            j -= w[i - 1];
        }
        else
            cout << "Item " << i << " is not part of the knapsack" << endl;
        i--;
    }
}