#include <iostream>
using namespace std;
class Matrix
{
    int **matrix, rows, cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols)
    {
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new int[cols];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                matrix[i][j] = 0;
    }
    void get()
    {
        cout << "Enter the matrix elements:\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> matrix[i][j];
    }
    void show()
    {
        for (int i = 0; i < rows; i++)
        {
            cout << "| ";
            for (int j = 0; j < cols; j++)
                cout << matrix[i][j] << " ";
            cout << "|" << endl;
        }
    }
    Matrix operator*(Matrix &m)
    {
        Matrix result(rows, m.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < m.cols; j++)
            {
                int sum = 0;
                for (int k = 0; k < cols; k++)
                    result.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
            }
        return result;
    }
};
int main()
{
    int rows, columns;
    cout << "Enter rows and columns:" << endl;
    cin >> rows >> columns;
    Matrix m1(rows, columns), m2(columns, rows);
    m1.get();
    m2.get();
    m1 = m1 * m2;
    m1.show();
}