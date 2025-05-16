#include <iostream>
using namespace std;
class Matrix
{
    int **matrix, rows, cols;

public:
    Matrix() {}
    Matrix(int rows, int cols) : rows(rows), cols(cols)
    {
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new int[cols];
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
    void operator-(Matrix m)
    {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                this->matrix[i][j] = this->matrix[i][j] - m.matrix[i][j];
    }
};
int main()
{
    int rows, columns;
    cout << "Enter rows and columns:" << endl;
    cin >> rows >> columns;
    Matrix m1(rows, columns), m2(rows, columns);
    m1.get();
    m2.get();
    m1 - m2;
    m1.show();
}