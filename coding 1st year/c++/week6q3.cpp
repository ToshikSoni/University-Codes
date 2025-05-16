#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout("file.txt");
    fout << "hello" << endl;
    fout << "hi";
    fout.close();
    ifstream fin("file.txt");
    string temp;
    while (!fin.eof())
    {
        getline(fin, temp);
        cout << temp << endl;
    }
    fin.close();
}