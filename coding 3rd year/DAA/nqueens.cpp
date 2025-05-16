#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<string> &board, int row, int col, int n)
{
    for (int i = 0; i < col; i++)
        if (board[row][i] == 'Q')
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j] == 'Q')
            return false;
    return true;
}
void solveNQueensUtil(vector<string> &board, int col, int n, vector<vector<string>> &solutions)
{
    if (col >= n)
    {
        solutions.push_back(board);
        return;
    }
    for (int i = 0; i < n; i++)
        if (isSafe(board, i, col, n))
        {
            board[i][col] = 'Q';
            solveNQueensUtil(board, col + 1, n, solutions);
            board[i][col] = '.';
        }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solveNQueensUtil(board, 0, n, solutions);
    return solutions;
}
void printSolutions(vector<vector<string>> &solutions)
{
    for (auto &solution : solutions)
    {
        for (auto &row : solution)
            cout << row << endl;
        cout << endl;
    }
}
int main()
{
    int n = 4 ;
    vector<vector<string>> solutions = solveNQueens(n);
    printSolutions(solutions);
}