#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout;
    fout.open("1file1.txt"); // opening file by open function
    if (!fout)
    {
        cout << "Error in opening the file." << endl;
        exit(1);
    }
    fout << "hello world";
    fout.close();

    ofstream fout1("1file2.txt"); // opening file by constructor
    if (!fout1)
    {
        cout << "Error in opening the file." << endl;
        exit(1);
    }
    fout1 << "hello world1";
    fout1.close();
}